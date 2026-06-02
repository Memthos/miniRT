/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:34:23 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/02 11:26:17 by juperrin         ###   ########.fr       */
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

t_vec2	mouse_get_delta(t_minirt *rt)
{
	t_vec2	delta;
	int		x;
	int		y;

	mlx_mouse_get_pos(rt->context, &x, &y);
	delta.x = x - rt->mouse.oldpos.x;
	delta.y = y - rt->mouse.oldpos.y;
	rt->mouse.oldpos.x = x;
	rt->mouse.oldpos.y = y;
	return (delta);
}
