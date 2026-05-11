/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_ops_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:58:04 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/11 17:11:38 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vec_add(const t_vec3 v1, const t_vec3 v2, t_status *status)
{
	t_vec3	res;

	res = (t_vec3) {0.0, 0.0, 0.0};
	if (fabs(v1.x) > DBL_MAX - fabs(v2.x)
		|| fabs(v1.y) > DBL_MAX - fabs(v2.y)
		|| fabs(v1.z) > DBL_MAX - fabs(v2.z))
	{
		if (status)
			*status = OVERFLOW;
		return (res);
	}
	res = (t_vec3) {v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
	return (res);
}

t_vec3	vec_sub(const t_vec3 v1, const t_vec3 v2, t_status *status)
{
	t_vec3	res;

	res = (t_vec3) {0.0, 0.0, 0.0};
	if (fabs(v1.x) < -DBL_MAX + fabs(v2.x)
		|| fabs(v1.y) < -DBL_MAX + fabs(v2.y)
		|| fabs(v1.z) < -DBL_MAX + fabs(v2.z))
	{
		if (status)
			*status = OVERFLOW;
		return (res);
	}
	res = (t_vec3) {v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
	return (res);
}

t_vec3	vec_scale(const t_vec3 v1, const double lambda)
{
	t_vec3	res;

	if (v1.x > DBL_MAX / lambda)
	res.x = v1.x * lambda;
	res.y = v1.y * lambda;
	res.z = v1.z * lambda;
	return (res);
}
double	vec_dot(const t_vec3 v1, const t_vec3 v2, t_status *status)
{
	double	x;
	double	y;
	double	z;
	double	res;

	if ((v2.x && fabs(v1.x) > DBL_MAX / fabs(v2.x))
		|| (v2.y && fabs(v1.y) > DBL_MAX / fabs(v2.y))
		|| (v2.z && fabs(v1.z) > DBL_MAX / fabs(v2.z)))
	{
		if (status)
			*status = OVERFLOW;
		return (0);
	}
	x = v1.x * v2.x;
	y = v1.y * v2.y;
	z = v1.z * v2.z;
	if (fabs(x) > DBL_MAX - fabs(y) || fabs(x + y) > DBL_MAX - fabs(z))
	{
		if (status)
			*status = OVERFLOW;
		return (0);
	}
	res = x + y + z;
	return (res);
}

t_vec3	vec_cross(const t_vec3 v1, const t_vec3 v2, t_status *status)
{
	t_vec3	res;

	res = (t_vec3) {v1.y * v2.z - v1.z *  v2.y,
					v1.z * v2.x - v1.x *  v2.z,
					v1.x * v2.y - v1.y *  v2.x};
	return (res);
}
