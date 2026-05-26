/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:20:46 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/26 13:17:46 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_sphere(t_minirt *rt, t_ray *ray, t_sphere *sp, double min, double max, t_hit_point *p)
{
	(void)rt;
	t_vec3	oc = vec_sub(sp->position, ray->origin);//vector between camera origin and sphere center
	double	a = vec_squared_magnitude(ray->dir);
	double	h = vec_dot(ray->dir, oc);
	double	c = vec_squared_magnitude(oc) - sp->diameter * sp->diameter * 0.25;
	double	d = h * h - a *c;
	if (d < 0)
		return (false);
	double	sqrtd = sqrt(d);
	double	root = (h - sqrtd) / a;
	if (root < min || root > max)
	{
		root = (h + sqrtd) / a;
		if (root < min || root > max)
			return (false);
	}
	p->t = root;
	p->point = ray_at(ray, p->t);
	t_vec3	normal = vec_scale(vec_sub(p->point, sp->position), 1 / (sp->diameter / 2));
	const bool	front = vec_dot(ray->dir, normal) < 0;
	if (front)
		p->normal = normal;
	else
		p->normal = vec_scale(normal, -1);
	return (true);
}
