/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:20:52 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/01 11:18:06 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_between_i(double *root, double h, double b, double a, t_interval i)
{
	double	sqrth;

	sqrth = sqrt(h);
	*root = (b - sqrth) / a;
	if (*root < i.min || *root > i.max)
	{
		*root = (b + sqrth) / a;
		if (*root < i.min || *root > i.max)
			return (false);
	}
	return (true);
}

static bool	hit_body(t_ray *ray, t_cylinder *cyl, t_interval i, t_hit_point *p)
{
	t_vec3	oc;
	t_vec3	rdc;
	t_vec3	occ;
	double	a;
	double	b;
	double	h;
	double	y;
	double	root;
	t_vec3	normal;

	oc = vec_sub(cyl->position, ray->origin);
	rdc = vec_cross(ray->dir, cyl->norm_rot);
	occ = vec_cross(oc, cyl->norm_rot);
	a = vec_squared_magnitude(rdc);
	b = vec_dot(rdc, occ);
	h = b * b - a * (vec_squared_magnitude(occ) -
		cyl->diameter * cyl->diameter * 0.25);
	if (h < 1e-8)
		return (false);
	root = 0.0;
	if (false == is_between_i(&root, h, b, a, i))
		return (false);
	p->t = root;
	p->point = ray_at(ray, p->t);
	y = vec_dot(vec_sub(p->point, cyl->position), cyl->norm_rot);
	if (y < -cyl->height * 0.5 || y > cyl->height * 0.5)
		return (false);
	normal = vec_normalize(vec_sub(p->point, vec_add(cyl->position, vec_scale(cyl->norm_rot, y))));
	p->front = vec_dot(ray->dir, normal) < 0;
	if (p->front)
		p->normal = normal;
	else
		p->normal = vec_scale(normal, -1);
	return (true);
}

static bool	hit_cap(t_ray *ray, t_vec3 pos, t_vec3 norm_rot, double diameter, t_interval i, t_hit_point *p)
{
	double	denom;
	double	t;
	t_vec3	hit;
	t_vec3	diff;

	denom = vec_dot(ray->dir, norm_rot);
	if (denom > -1e-6 && denom < 1e-6)
		return (false);
	t = vec_dot(vec_sub(pos, ray->origin), norm_rot) / denom;
	if (t < i.min || t > i.max)
		return (false);
	hit = ray_at(ray, t);
	diff = vec_sub(hit, pos);
	if (vec_squared_magnitude(diff) > diameter * diameter * 0.25)
		return (false);
	p->t = t;
	p->point = hit;
	p->front = denom < 0;
	if (p->front)
		p->normal = norm_rot;
	else
		p->normal = vec_scale(norm_rot, -1);
	return (true);
}

bool	hit_cylinder(t_ray *ray, t_obj *cylinder, t_interval i, t_hit_point *p)
{
	bool		has_hit;
	t_hit_point	tmp;
	t_cylinder	*cyl;
	t_vec3		cap_pos;

	cyl = &cylinder->u_obj.cylinder;
	has_hit = false;
	if (hit_body(ray, cyl, i, p))
	{
		i.max = p->t;
		has_hit = true;
	}
	cap_pos = vec_add(cyl->position, vec_scale(cyl->norm_rot, cyl->height * 0.5));
	if (hit_cap(ray, cap_pos, cyl->norm_rot, cyl->diameter, i, &tmp))
	{
		i.max = tmp.t;
		*p = tmp;
		has_hit = true;
	}
	cap_pos = vec_sub(cyl->position, vec_scale(cyl->norm_rot, cyl->height * 0.5));
	if (hit_cap(ray, cap_pos, vec_scale(cyl->norm_rot, -1), cyl->diameter, i, &tmp))
	{
		*p = tmp;
		has_hit = true;
	}
	return (has_hit);
}
