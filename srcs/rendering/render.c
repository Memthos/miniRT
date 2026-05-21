/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:04:09 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/21 10:25:17 by juperrin         ###   ########.fr       */
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
			t_ray	ray = {{0, 0, 0}, {0, 0, 0}};
			mlx_set_image_pixel(rt->context, rt->render, x, y, ray_color(rt, &ray));
			++x;
		}
		++y;
	}
	return ;
}
