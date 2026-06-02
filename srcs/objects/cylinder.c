/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:20:52 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/02 10:09:29 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_obj_ret	is_between_i(double a, double b, double h, t_interval i)
{
	double	sqrth;
	double	root;

	sqrth = sqrt(h);
	root = (b - sqrth) / a;
	if (root < i.min || root > i.max)
	{
		root = (b + sqrth) / a;
		if (root < i.min || root > i.max)
			return ((t_obj_ret){0.0, false});
	}
	return ((t_obj_ret){root, true});
}

static t_obj_ret	does_hit(t_ray *ray, t_cylinder cyl, t_interval i)
{
	t_vec3		rdc;
	t_vec3		occ;
	double		data[3];
	t_obj_ret	ret;

	ret = (t_obj_ret){0.0, false};
	rdc = vec_cross(ray->dir, cyl.norm_rot);
	occ = vec_cross(vec_sub(cyl.position, ray->origin), cyl.norm_rot);
	data[0] = vec_squared_magnitude(rdc);
	data[1] = vec_dot(rdc, occ);
	data[2] = data[1] * data[1] - data[0] * (vec_squared_magnitude(occ)
			- cyl.diameter * cyl.diameter * 0.25);
	if (data[2] < 1e-8)
		return (ret);
	ret = is_between_i(data[0], data[1], data[2], i);
	return (ret);
}

static bool	hit_body(t_ray *ray, t_cylinder cyl, t_interval i, t_hit_point *p)
{
	double		y;
	t_obj_ret	ret;
	t_vec3		normal;

	ret = does_hit(ray, cyl, i);
	if (false == ret.ret)
		return (false);
	p->t = ret.val;
	p->point = ray_at(ray, p->t);
	y = vec_dot(vec_sub(p->point, cyl.position), cyl.norm_rot);
	if (y < -cyl.height * 0.5 || y > cyl.height * 0.5)
		return (false);
	normal = vec_normalize(vec_sub(p->point, vec_add(cyl.position,
					vec_scale(cyl.norm_rot, y))));
	p->front = vec_dot(ray->dir, normal) < 0;
	if (p->front)
		p->normal = normal;
	else
		p->normal = vec_scale(normal, -1);
	return (true);
}

static bool	hit_cap(t_ray *ray, t_cylinder cyl, t_interval i, t_hit_point *p)
{
	double	denom;
	double	t;
	t_vec3	hit;
	t_vec3	diff;

	denom = vec_dot(ray->dir, cyl.norm_rot);
	if (denom > -1e-6 && denom < 1e-6)
		return (false);
	t = vec_dot(vec_sub(cyl.position, ray->origin), cyl.norm_rot) / denom;
	if (t < i.min || t > i.max)
		return (false);
	hit = ray_at(ray, t);
	diff = vec_sub(hit, cyl.position);
	if (vec_squared_magnitude(diff) > cyl.diameter * cyl.diameter * 0.25)
		return (false);
	p->t = t;
	p->point = hit;
	p->front = denom < 0;
	if (p->front)
		p->normal = cyl.norm_rot;
	else
		p->normal = vec_scale(cyl.norm_rot, -1);
	return (true);
}

bool	hit_cylinder(t_ray *ray, t_obj *cylinder, t_interval i, t_hit_point *p)
{
	bool		has_hit;
	t_cylinder	*c;
	t_cylinder	cp;

	c = &cylinder->u_obj.cylinder;
	cp = *c;
	has_hit = false;
	if (hit_body(ray, cp, i, p))
	{
		i.max = p->t;
		has_hit = true;
	}
	cp.position = vec_add(c->position, vec_scale(c->norm_rot, c->height * 0.5));
	if (hit_cap(ray, cp, i, p))
	{
		i.max = p->t;
		has_hit = true;
	}
	cp.position = vec_sub(c->position, vec_scale(c->norm_rot, c->height * 0.5));
	cp.norm_rot = vec_scale(c->norm_rot, -1);
	if (hit_cap(ray, cp, i, p))
		has_hit = true;
	return (has_hit);
}
