/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:51 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/29 15:17:13 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	key_hook(int key, void *param)
{
	t_minirt	*rt;

	rt = (t_minirt *)param;
	if (KEY_ESCAPE == key)
		mlx_loop_end(rt->context);
	if (KEY_A == key)
		rt->camera.pos.x -= 0.01;
	if (KEY_D == key)
		rt->camera.pos.x += 0.01;
	if (KEY_W == key)
		rt->camera.pos.z += 0.01;
	if (KEY_S == key)
		rt->camera.pos.z -= 0.01;
	if (KEY_E == key)
		rt->camera.pos.y += 0.01;
	if (KEY_Q == key)
		rt->camera.pos.y -= 0.01;
	camera_update(&rt->camera, rt->dimensions);
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
	mlx_on_event(rt->context, rt->window, MLX_KEYDOWN, &key_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_WINDOW_EVENT, &window_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_MOUSEDOWN, &select_hook, rt);
	mlx_add_loop_hook(rt->context, &rt_loop, rt);
	return ;
}
