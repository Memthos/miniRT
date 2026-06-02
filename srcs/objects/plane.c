/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:21:13 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/02 09:58:58 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	hit_plane(t_ray *ray, t_obj *plane, t_interval i, t_hit_point *p)
{
	double	denom;
	double	t;
	t_vec3	normal;

	denom = vec_dot(plane->u_obj.plane.norm_rot, ray->dir);
	if (fabs(denom) < 1e-6)
		return (false);
	t = vec_dot(plane->u_obj.plane.norm_rot,
			vec_sub(plane->u_obj.plane.position, ray->origin)) / denom;
	if (t < i.min || t > i.max)
		return (false);
	p->t = t;
	p->point = ray_at(ray, p->t);
	normal = plane->u_obj.plane.norm_rot;
	p->front = vec_dot(ray->dir, normal) < 0;
	if (p->front)
		p->normal = normal;
	else
		p->normal = vec_scale(normal, -1);
	return (true);
}
