/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 12:26:14 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/30 18:08:46 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_between_i(double *root, double h, double b, t_interval i)
{
	double	sqrth;

	sqrth = sqrt(h);
	*root = b - sqrth;
	if (*root < i.min || *root > i.max)
	{
		*root = b + sqrth;
		if (*root < i.min || *root > i.max)
			return (false);
	}
	return (true);
}

bool	hit_light(t_ray *ray, t_obj *light, t_interval i, t_hit_point *p)
{
	t_vec3	oc;
	double	b;
	double	h;
	double	root;
	t_vec3	normal;

	oc = vec_sub(light->u_obj.point_light.position, ray->origin);
	b = vec_dot(ray->dir, oc);
	h = 0.25 - vec_squared_magnitude(vec_sub(oc, vec_scale(ray->dir, b)));
	if (h < 0)
		return (false);
	root = 0.0;
	if (false == is_between_i(&root, h, b, i))
		return (false);
	p->t = root;
	p->point = ray_at(ray, p->t);
	p->mat = light->mat;
	normal = vec_scale(vec_sub(p->point, light->u_obj.point_light.position), 2);
	p->front = vec_dot(ray->dir, normal) < 0;
	if (p->front)
		p->normal = normal;
	else
		p->normal = vec_scale(normal, -1);
	return (true);
}
