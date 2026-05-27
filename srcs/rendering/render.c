/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:04:09 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/27 14:32:15 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_rgb	get_pixel_color(t_minirt *rt, int x, int y)
{
	t_uint	delta_y;
	t_uint	delta_x;
	t_rgb	pixel_c;
	t_rgb	ray_c;
	t_ray	ray;

	pixel_c = (t_rgb){0};
	delta_y = 0;
	while (delta_y < rt->camera.aa.size)
	{
		delta_x = 0;
		while (delta_x < rt->camera.aa.size)
		{
			ray = ray_gen(&rt->camera, x, y, delta_x, delta_y);
			ray_c = ray_color(rt, &ray);
			pixel_c = vec_add(pixel_c, ray_c);
			++delta_x;
		}
		++delta_y;
	}
	pixel_c = vec_scale(pixel_c, rt->camera.aa.scale);
	return (pixel_c);
}

void	rt_render(t_minirt *rt)
{
	int		x;
	int		y;
	t_rgb	pixel_c;

	if (NULL == rt)
		return ;
	y = 0;
	while (y < rt->dimensions.y)
	{
		x = 0;
		while (x < rt->dimensions.x)
		{
			pixel_c = get_pixel_color(rt, x, y);
			mlx_set_image_pixel(rt->context, rt->render, x, y, (mlx_color){
				.r = 255 * pixel_c.x,
				.g = 255 * pixel_c.y,
				.b = 255 * pixel_c.z,
				.a = 255});
			++x;
		}
		++y;
	}
	return ;
}
