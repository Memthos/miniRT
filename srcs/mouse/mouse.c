/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:34:23 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/30 18:22:49 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mouse_init(t_minirt *rt)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(rt->context, &x, &y);
	rt->mouse.oldpos.x = x;
	rt->mouse.oldpos.y = y;
	rt->mouse.rotating = false;
	return ;
}

static bool	mouse_teleport(t_minirt *rt, const t_vec2 border, int x, int y)
{
	if (x <= border.x || y <= border.y
		|| x >= rt->dimensions.x - border.x - 1
		|| y >= rt->dimensions.y - border.y - 1)
	{
		if (x <= border.x)
			mlx_mouse_move(rt->context, rt->window,
				rt->dimensions.x - border.x - 2, y);
		if (y <= border.y)
			mlx_mouse_move(rt->context, rt->window, x,
				rt->dimensions.y - border.y - 2);
		if (x >= rt->dimensions.x - border.x - 1)
			mlx_mouse_move(rt->context, rt->window, border.x + 1, y);
		if (y >= rt->dimensions.y - border.y - 1)
			mlx_mouse_move(rt->context, rt->window, x, border.y + 1);
		mlx_mouse_get_pos(rt->context, &x, &y);
		rt->mouse.oldpos.x = x;
		rt->mouse.oldpos.y = y;
		return (true);
	}
	return (false);
}

t_vec2	mouse_get_delta(t_minirt *rt)
{
	const t_vec2	border = {10, 10};
	t_vec2			delta;
	int				x;
	int				y;

	mlx_mouse_get_pos(rt->context, &x, &y);
	if (rt->mouse.rotating || rt->mv_params.moving)
	{
		if (mouse_teleport(rt, border, x, y))
			return ((t_vec2){0, 0});
	}
	delta.x = x - rt->mouse.oldpos.x;
	delta.y = y - rt->mouse.oldpos.y;
	rt->mouse.oldpos.x = x;
	rt->mouse.oldpos.y = y;
	return (delta);
}

void	mouse_update(t_minirt *rt)
{
	const t_vec2	delta = mouse_get_delta(rt);

	if (!rt->mouse.rotating)
		return ;
	rt->camera.dir = vec_rotate(
			rt->camera.dir,
			(t_vec3){0, 1, 0},
			delta.x * rt->sensibility * deg_to_rad());
	rt->camera.dir = vec_rotate(
			rt->camera.dir,
			rt->camera.right,
			delta.y * rt->sensibility * deg_to_rad());
	return ;
}
