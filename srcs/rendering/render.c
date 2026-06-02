/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:04:09 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/02 10:09:57 by mperrine         ###   ########.fr       */
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
			ray = ray_gen(&rt->camera, (int[2]){x, y},
				(int[2]){delta_x, delta_y});
			ray_c = ray_color(rt, &ray);
			pixel_c = vec_add(pixel_c, ray_c);
			++delta_x;
		}
		++delta_y;
	}
	pixel_c = vec_scale(pixel_c, rt->camera.aa.scale);
	return (pixel_c);
}

static void	set_pixel_color(t_minirt *rt, int x, int y, t_rgb color)
{
	int	_y;
	int	_x;

	_y = 0;
	while (_y < 1 / rt->cur_quality->quality)
	{
		_x = 0;
		while (_x < 1 / rt->cur_quality->quality)
		{
			mlx_set_image_pixel(rt->context, rt->render, x + _x, y + _y,
				(mlx_color){
				.r = 255 * color.x,
				.g = 255 * color.y,
				.b = 255 * color.z,
				.a = 255});
			++_x;
		}
		++_y;
	}
	return ;
}

static void	render_region(t_minirt *rt, t_vec2 pos)
{
	int		x;
	int		y;
	t_rgb	pixel_c;

	y = 0;
	while (y < rt->cur_quality->region.y)
	{
		x = 0;
		while (x < rt->cur_quality->region.x)
		{
			pixel_c = get_pixel_color(rt, x + pos.x * rt->cur_quality->region.x, y + pos.y * rt->cur_quality->region.y);
			set_pixel_color(rt, x + pos.x * rt->cur_quality->region.x, y + pos.y * rt->cur_quality->region.y, pixel_c);
			x += 1 / rt->cur_quality->quality;
		}
		y += 1 / rt->cur_quality->quality;
	}
	return ;
}

void	rt_render(t_minirt *rt, bool restart)
{
	static t_vec2	pos;

	if (restart)
	{
		pos.x = 0;
		pos.y = 0;
	}
	render_region(rt, pos);
	++pos.x;
	if (pos.x * rt->cur_quality->region.x >= rt->dimensions.x)
	{
		pos.x = 0;
		++pos.y;
	}
	if (pos.y * rt->cur_quality->region.y >= rt->dimensions.y)
	{
		pos.x = 0;
		pos.y = 0;
		rt->should_render = false;
		mlx_clear_window(rt->context, rt->window, (mlx_color){.rgba = 0x000000FF});
		mlx_put_image_to_window(rt->context, rt->window, rt->render, 0, 0);
	}
	return ;
}
