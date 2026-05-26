/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:37:51 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/26 13:48:06 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point3	ray_at(t_ray *ray, double delta)
{
	t_point3	point;

	point = vec_add(ray->origin, vec_scale(ray->dir, delta));
	return (point);
}

static bool	ray_hit_object(t_minirt *rt, t_ray *ray, double min, double max, t_hit_point *p)
{
	bool			hit;
	double			_max;
	t_hit_point		tmp;
	t_uint			index;
	const t_array	*objects = &rt->geos;

	hit = false;
	_max = max;
	index = 0;
	while (index < objects->size)
	{
		if ((objects->objs + index)->hit(rt, ray, objects->objs + index, min, _max, &tmp))
		{
			hit = true;
			_max = tmp.t;
			*p = tmp;
		}
		++index;
	}
	return (hit);
}

mlx_color	ray_color(t_minirt *rt, t_ray *ray)
{
	mlx_color	c;
	t_hit_point	p;

	(void)rt;
	if (ray_hit_object(rt, ray, 0, 1000, &p))
	{
		c = (mlx_color){.r = (p.normal.x + 1) * 127.5, .g = (p.normal.y + 1) * 127.5, .b = (p.normal.z + 1) * 127.5, .a = 255};
		return (c);
	}
	double	f = (vec_normalize(ray->dir).y + 1) * 0.5;
	t_vec3	col = vec_add(vec_scale((t_vec3){1, 1, 1}, 1 - f), vec_scale((t_vec3){0.5, 0.7, 1}, f));
	c = (mlx_color){.r = col.x * 255, .g = col.y * 255, .b = col.z * 255, .a = 255};
	return (c);
}
