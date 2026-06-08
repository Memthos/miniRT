/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:34:20 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/08 09:57:45 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	lambertian_scatter(t_ray *in, t_ray *out, t_hit_point *p)
{
	const t_vec3	scatter_dir = random_surface_vec3(p->normal);
	// const t_vec3	scatter_dir = vec_add(p->normal, random_unit_vec3());

	(void)in;
	*out = (t_ray){p->point, scatter_dir};
	return (true);
}

t_material	mat_lambertian(t_rgb col)
{
	t_material	m;

	m.col = col;
	m.scatter = &lambertian_scatter;
	return (m);
}
