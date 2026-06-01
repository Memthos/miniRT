/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:20:46 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/28 11:13:49 by mperrine         ###   ########.fr       */
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

bool	hit_sphere(t_ray *ray, t_obj *obj, t_interval i, t_hit_point *p)
{
	t_vec3	oc;
	double	b;
	double	h;
	double	root;
	t_vec3	normal;

	oc = vec_sub(obj->u_obj.sphere.position, ray->origin);
	b = vec_dot(ray->dir, oc);
	h = obj->u_obj.sphere.diameter * obj->u_obj.sphere.diameter * 0.25
		- vec_squared_magnitude(vec_sub(oc, vec_scale(ray->dir, b)));
	if (h < 0)
		return (false);
	root = 0.0;
	if (false == is_between_i(&root, h, b, i))
		return (false);
	p->t = root;
	p->point = ray_at(ray, p->t);
	normal = vec_scale(vec_sub(p->point, obj->u_obj.sphere.position),
		2.0 / obj->u_obj.sphere.diameter);
	p->front = vec_dot(ray->dir, normal) < 0;
	if (p->front)
		p->normal = normal;
	else
		p->normal = vec_scale(normal, -1);
	return (true);
}
