/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emission.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 12:22:05 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/30 16:33:41 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	emission_scatter(t_ray *in, t_ray *out, t_hit_point *p)
{
	(void)in;
	(void)out;
	(void)p;
	return (false);
}

static t_rgb	emission_emit(t_hit_point *p)
{
	return (p->mat.col);
}

t_material	mat_emission(t_rgb col)
{
	const float	intensity = 5;
	t_material	m;

	m.col = vec_scale(col, intensity);
	m.scatter = &emission_scatter;
	m.emit = &emission_emit;
	return (m);
}
