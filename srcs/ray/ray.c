/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:37:51 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/27 14:41:26 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray_gen(t_camera *cam, int x, int y, int delta_x, int delta_y)
{
	t_ray			ray;
	const double	offset = 1.0 / (double)(cam->aa.size + 1);
	const t_vec3	offset_vec = {
		offset * cam->viewport.delta_x.x,
		offset * cam->viewport.delta_y.y,
		0};
	const t_point3	pixel_point = vec_add(
			vec_sub(cam->viewport.nw_pixel, offset_vec),
			vec_add(
				vec_scale(
					cam->viewport.delta_x,
					x + delta_x / (double)cam->aa.size),
				vec_scale(
					cam->viewport.delta_y,
					y + delta_y / (double)cam->aa.size)));

	ray = (t_ray){cam->pos, vec_sub(pixel_point, cam->pos)};
	return (ray);
}

t_point3	ray_at(t_ray *ray, double delta)
{
	t_point3	point;

	point = vec_add(ray->origin, vec_scale(ray->dir, delta));
	return (point);
}

static bool	ray_hit_object(t_minirt *rt, t_ray *ray, const t_interval i, t_hit_point *p)
{
	bool			hit;
	t_interval		_i;
	t_hit_point		tmp;
	t_uint			index;
	const t_array	*objects = &rt->geos;

	hit = false;
	_i = i;
	index = 0;
	while (index < objects->size)
	{
		if ((objects->objs + index)->hit(rt, ray, objects->objs + index, _i, &tmp))
		{
			hit = true;
			_i.max = tmp.t;
			*p = tmp;
		}
		++index;
	}
	return (hit);
}

t_rgb	ray_color(t_minirt *rt, t_ray *ray)
{
	t_rgb				c;
	t_hit_point			p;
	const t_interval	i = {0, 100};
	const double		f = (vec_normalize(ray->dir).y + 1) * 0.5;
	const t_vec3		col = vec_add(
			vec_scale((t_vec3){1, 1, 1}, 1 - f),
			vec_scale((t_vec3){0.5, 0.7, 1}, f));

	if (ray_hit_object(rt, ray, i, &p))
	{
		c = (t_rgb){
			.x = (p.normal.x + 1) * 0.5,
			.y = (p.normal.y + 1) * 0.5,
			.z = (p.normal.z + 1) * 0.5
		};
		return (c);
	}
	c = (t_rgb){.x = col.x, .y = col.y, .z = col.z};
	return (c);
}
