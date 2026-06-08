/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:37:51 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/08 09:37:17 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray_gen(t_camera *cam, int pos[2], int delta[2])
{
	t_ray			ray;
	const double	offset = 1.0 / (double)(cam->aa.size + 1);
	const t_point3	pixel_point = vec_add(
			cam->viewport.nw_pixel,
			vec_add(
				vec_scale(cam->viewport.delta_x, pos[0] + delta[0] * offset),
				vec_scale(cam->viewport.delta_y, pos[1] + delta[1] * offset)));

	ray = (t_ray){cam->pos, vec_normalize(vec_sub(pixel_point, cam->pos))};
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
		if ((objects->objs + index)->hit(ray, objects->objs + index, _i, &tmp))
		{
			hit = true;
			_i.max = tmp.t;
			*p = tmp;
		}
		++index;
	}
	return (hit);
}

t_rgb	ray_color(t_minirt *rt, t_ray *ray, t_uint max_depth)
{
	t_ray				reflect;
	t_rgb				c;
	t_hit_point			p;
	const t_interval	i = {0.001, 1000};

	if (0 == max_depth)
		return ((t_rgb){0, 0, 0});
	if (ray_hit_object(rt, ray, i, &p))
	{
		if (p.mat.scatter(ray, &reflect, &p))
		{
			c = ray_color(rt, &reflect, --max_depth);
			return ((t_rgb){c.x * p.mat.col.x, c.y * p.mat.col.y, c.z * p.mat.col.z});
		}
		return ((t_rgb){0, 0, 0});
	}
	c = rt->ambient_light.color;
	return (c);
}
