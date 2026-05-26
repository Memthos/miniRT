/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:04:09 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/21 14:24:54 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_render(t_minirt *rt)
{
	int	x;
	int	y;

	if (NULL == rt)
		return ;
	y = 0;
	while (y < rt->dimensions.y)
	{
		x = 0;
		while (x < rt->dimensions.x)
		{
			t_point3	pixel_point = vec_add(rt->camera.viewport.nw_pixel, vec_add(vec_scale(rt->camera.viewport.delta_x, x), vec_scale(rt->camera.viewport.delta_y, y)));
			t_ray		ray = {rt->camera.pos, vec_sub(pixel_point, rt->camera.pos)};
			mlx_set_image_pixel(rt->context, rt->render, x, y, ray_color(rt, &ray));
			++x;
		}
		++y;
	}
	return ;
}
