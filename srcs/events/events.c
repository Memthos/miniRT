/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:51 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/04 10:05:51 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	window_hook(int event, void *param)
{
	t_minirt	rt;

	rt = *(t_minirt *)param;
	if (0 == event)
		mlx_loop_end(rt.context);
	return ;
}

static void	get_hit_obj(t_minirt *rt, t_ray *ray, const t_interval i)
{
	t_interval		_i;
	t_hit_point		tmp;
	t_uint			index;
	const t_array	*objects = &rt->geos;

	_i = i;
	index = 0;
	while (index < objects->size)
	{
		if (objects->objs[index].hit(ray, &objects->objs[index], _i, &tmp))
		{
			_i.max = tmp.t;
			rt->mv_params.selected = &objects->objs[index];
		}
		++index;
	}
}

static void	mouseup_hook(int key, void *param)
{
	t_minirt			*rt;
	int					mouse_pos[2];
	const t_interval	i = {0, 100};
	t_point3			pixel_point;
	t_ray				ray;

	rt = (t_minirt *)param;
	if (key == RIGHT_MOUSE)
	{
		rt->mv_params.moving = false;
		rt->should_render = true;
		return ;
	}
	if (key != LEFT_MOUSE)
		return ;
	ft_bzero(&mouse_pos, sizeof(int [2]));
	mlx_mouse_get_pos(rt->context, &mouse_pos[0], &mouse_pos[1]);
	pixel_point = vec_add(rt->camera.viewport.nw_pixel,
			vec_add(vec_scale(rt->camera.viewport.delta_x,
					(double)mouse_pos[0]),
				vec_scale(rt->camera.viewport.delta_y, (double)mouse_pos[1])));
	ray = (t_ray){rt->camera.pos, vec_sub(pixel_point, rt->camera.pos)};
	rt->mv_params.selected = NULL;
	get_hit_obj(rt, &ray, i);
}

static void	mousedown_hook(int key, void *param)
{
	t_minirt			*rt;

	rt = (t_minirt *)param;
	if (RIGHT_MOUSE != key || NULL == rt->mv_params.selected
		|| rt->mv_params.move_mode == NONE)
		return ;
	rt->mv_params.moving = true;
	mlx_mouse_get_pos(rt->context, &rt->mv_params.mouse_pressed_pos[0],
		&rt->mv_params.mouse_pressed_pos[1]);
	rt->mv_params.last_mouse_pos[0] = rt->mv_params.mouse_pressed_pos[0];
	rt->mv_params.last_mouse_pos[1] = rt->mv_params.mouse_pressed_pos[1];
	rt->mv_params.start_norm_rot = rt->mv_params.selected->u_obj.plane.norm_rot;
	rt->mv_params.screen_pos = project_to_screen(rt,
		rt->mv_params.selected->u_obj.plane.position);
}

void	rt_init_events(t_minirt *rt)
{
	mlx_on_event(rt->context, rt->window, MLX_KEYDOWN, &keydown_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_KEYUP, &keyup_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_WINDOW_EVENT, &window_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_MOUSEUP, &mouseup_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_MOUSEDOWN, &mousedown_hook, rt);
	mlx_add_loop_hook(rt->context, &rt_loop, rt);
	return ;
}
