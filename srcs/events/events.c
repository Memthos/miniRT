/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:51 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/02 10:46:43 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	keydown_hook(int key, void *param)
{
	t_minirt	*rt;

	rt = (t_minirt *)param;
	if (KEY_ESCAPE == key)
		mlx_loop_end(rt->context);
	if (KEY_A == key && !rt->camera.move.moving[MOVING_LEFT])
	{
		rt->camera.move.moving[MOVING_LEFT] = true;
		rt->camera.move.velocity.x -= 1.0;
	}
	if (KEY_D == key && !rt->camera.move.moving[MOVING_RIGHT])
	{
		rt->camera.move.moving[MOVING_RIGHT] = true;
		rt->camera.move.velocity.x += 1.0;
	}
	if (KEY_W == key && !rt->camera.move.moving[MOVING_FORWARD])
	{
		rt->camera.move.moving[MOVING_FORWARD] = true;
		rt->camera.move.velocity.z += 1.0;
	}
	if (KEY_S == key && !rt->camera.move.moving[MOVING_BACKWARD])
	{
		rt->camera.move.moving[MOVING_BACKWARD] = true;
		rt->camera.move.velocity.z -= 1.0;
	}
	if (KEY_SPACE == key && !rt->camera.move.moving[MOVING_UP])
	{
		rt->camera.move.moving[MOVING_UP] = true;
		rt->camera.move.velocity.y += 1.0;
	}
	if (KEY_CTRL == key && !rt->camera.move.moving[MOVING_DOWN])
	{
		rt->camera.move.moving[MOVING_DOWN] = true;
		rt->camera.move.velocity.y -= 1.0;
	}
	return ;
}

static void	keyup_hook(int key, void *param)
{
	t_minirt	*rt;

	rt = (t_minirt *)param;
	if (KEY_A == key && rt->camera.move.moving[MOVING_LEFT])
	{
		rt->camera.move.moving[MOVING_LEFT] = false;
		rt->camera.move.velocity.x += 1.0;
	}
	if (KEY_D == key && rt->camera.move.moving[MOVING_RIGHT])
	{
		rt->camera.move.moving[MOVING_RIGHT] = false;
		rt->camera.move.velocity.x -= 1.0;
	}
	if (KEY_W == key && rt->camera.move.moving[MOVING_FORWARD])
	{
		rt->camera.move.moving[MOVING_FORWARD] = false;
		rt->camera.move.velocity.z -= 1.0;
	}
	if (KEY_S == key && rt->camera.move.moving[MOVING_BACKWARD])
	{
		rt->camera.move.moving[MOVING_BACKWARD] = false;
		rt->camera.move.velocity.z += 1.0;
	}
	if (KEY_SPACE == key && rt->camera.move.moving[MOVING_UP])
	{
		rt->camera.move.moving[MOVING_UP] = false;
		rt->camera.move.velocity.y -= 1.0;
	}
	if (KEY_CTRL == key && rt->camera.move.moving[MOVING_DOWN])
	{
		rt->camera.move.moving[MOVING_DOWN] = false;
		rt->camera.move.velocity.y += 1.0;
	}
	return ;
}

static void	mousedown_hook(int button, void *param)
{
	t_minirt	*rt;

	rt = param;
	if (2 != button)
		return ;
	mlx_mouse_hide(rt->context);
	rt->mouse.rotating = true;
	return ;
}

static void	mouseup_hook(int button, void *param)
{
	t_minirt	*rt;

	rt = param;
	if (2 != button)
		return ;
	mlx_mouse_show(rt->context);
	rt->mouse.rotating = false;
	return ;
}

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
			rt->selected = &objects->objs[index];
		}
		++index;
	}
}

static void	select_hook(int event, void *param)
{
	t_minirt			*rt;
	int					mouse_pos[2];
	const t_interval	i = {0, 100};
	t_point3			pixel_point;
	t_ray				ray;

	rt = (t_minirt *)param;
	if (1 != event)
		return ;
	ft_bzero(&mouse_pos, sizeof(int[2]));
	mlx_mouse_get_pos(rt->context, &mouse_pos[0], &mouse_pos[1]);
	pixel_point = vec_add(rt->camera.viewport.nw_pixel,
		vec_add(vec_scale(rt->camera.viewport.delta_x, (double)mouse_pos[0]),
		vec_scale(rt->camera.viewport.delta_y, (double)mouse_pos[1])));
	ray = (t_ray){rt->camera.pos, vec_sub(pixel_point, rt->camera.pos)};
	rt->selected = NULL;
	get_hit_obj(rt, &ray, i);
}

void	rt_init_events(t_minirt *rt)
{
	mlx_on_event(rt->context, rt->window, MLX_KEYDOWN, &keydown_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_KEYUP, &keyup_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_MOUSEDOWN, &mousedown_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_MOUSEUP, &mouseup_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_WINDOW_EVENT, &window_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_MOUSEDOWN, &select_hook, rt);
	mlx_add_loop_hook(rt->context, &rt_loop, rt);
	return ;
}
