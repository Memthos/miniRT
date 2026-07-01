/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:51 by juperrin          #+#    #+#             */
/*   Updated: 2026/07/01 14:34:06 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	window_hook(int event, void *param)
{
	t_minirt	*rt;
	int			size_x;
	int			size_y;

	rt = (t_minirt *)param;
	if (0 == event)
		mlx_loop_end(rt->context);
	else if (1 == event)
	{
		mlx_loop_end(rt->context);
		mlx_get_window_size(rt->context, rt->window, &size_x, &size_y);
		rt->dimension = (t_vec2){size_x, size_y};
		mlx_destroy_image(rt->context, rt->render);
		rt->render = mlx_new_image(
				rt->context,
				rt->dimension.x,
				rt->dimension.y);
		if (NULL == rt->render)
			rt_quit(rt);
		render_set_quality(rt);
		rt->size_changed = true;
		mlx_loop(rt->context);
	}
	return ;
}

void	mousewheel_hook(int key, void *param)
{
	t_minirt	*rt;

	rt = param;
	if (1 == key)
	{
		rt->camera.move.speed += 1;
		if (rt->camera.move.speed >= INT_MAX)
			rt->camera.move.speed = INT_MAX;
	}
	if (2 == key)
	{
		rt->camera.move.speed -= 1;
		if (rt->camera.move.speed < 1)
			rt->camera.move.speed = 1;
	}
	return ;
}

static void	mouseup_hook(int key, void *param)
{
	t_minirt			*rt;
	int					mouse_pos[2];
	const t_interval	i = {0, 100};
	t_point3			pixel_point;

	rt = (t_minirt *)param;
	if (KEY_MOUSE_WHEEL == key)
	{
		mlx_mouse_show(rt->context);
		rt->mouse.rotating = false;
	}
	if (key == KEY_RIGHT_MOUSE)
	{
		rt->mv_params.moving = false;
		rt->should_render = true;
		return ;
	}
	if (key != KEY_LEFT_MOUSE)
		return ;
	mlx_mouse_get_pos(rt->context, &mouse_pos[0], &mouse_pos[1]);
	pixel_point = vec_add(rt->camera.viewport.nw_pixel,
			vec_add(vec_scale(rt->camera.viewport.delta_x, mouse_pos[0]),
				vec_scale(rt->camera.viewport.delta_y, mouse_pos[1])));
	get_hit_obj(rt, pixel_point, i);
}

static void	mousedown_hook(int key, void *param)
{
	t_minirt			*rt;

	rt = (t_minirt *)param;
	if (KEY_MOUSE_WHEEL == key)
	{
		mlx_mouse_hide(rt->context);
		rt->mouse.rotating = true;
	}
	if (KEY_RIGHT_MOUSE != key || NULL == rt->mv_params.selected
		|| rt->mv_params.move_mode == NONE)
		return ;
	rt->mv_params.moving = true;
	mlx_mouse_get_pos(rt->context, &rt->mv_params.mouse_pressed_pos[0],
		&rt->mv_params.mouse_pressed_pos[1]);
	rt->mv_params.last_ms_pos[0] = rt->mv_params.mouse_pressed_pos[0];
	rt->mv_params.last_ms_pos[1] = rt->mv_params.mouse_pressed_pos[1];
	rt->mv_params.start_norm_rot = rt->mv_params.selected->u_obj.plane.norm_rot;
	rt->mv_params.screen_pos = project_to_screen(
			rt, rt->mv_params.selected->u_obj.plane.position);
}

void	rt_init_events(t_minirt *rt)
{
	mlx_on_event(rt->context, rt->window, MLX_KEYDOWN, &keydown_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_KEYUP, &keyup_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_WINDOW_EVENT, &window_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_MOUSEUP, &mouseup_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_MOUSEDOWN, &mousedown_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_MOUSEWHEEL, &mousewheel_hook, rt);
	mlx_add_loop_hook(rt->context, &rt_loop, rt);
	return ;
}
