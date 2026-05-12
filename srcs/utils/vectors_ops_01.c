/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_ops_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:58:04 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/12 09:46:43 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	vec_add(const t_vec3 v1, const t_vec3 v2, t_status *status)
{
	t_vec3	res;

	res = (t_vec3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
	if (!isfinite(res.x) || !isfinite(res.y) || !isfinite(res.z))
	{
		if (status)
			*status = OVERFLOW;
		return ((t_vec3){0.0, 0.0, 0.0});
	}
	return (res);
}

t_vec3	vec_sub(const t_vec3 v1, const t_vec3 v2, t_status *status)
{
	t_vec3	res;

	res = (t_vec3){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
	if (!isfinite(res.x) || !isfinite(res.y) || !isfinite(res.z))
	{
		if (status)
			*status = OVERFLOW;
		return ((t_vec3){0.0, 0.0, 0.0});
	}
	return (res);
}

t_vec3	vec_scale(const t_vec3 v1, const double lambda, t_status *status)
{
	t_vec3	res;

	res = (t_vec3){v1.x * lambda, v1.y * lambda, v1.z * lambda};
	if (!isfinite(res.x) || !isfinite(res.y) || !isfinite(res.z))
	{
		if (status)
			*status = OVERFLOW;
		return ((t_vec3){0.0, 0.0, 0.0});
	}
	return (res);
}

double	vec_dot(const t_vec3 v1, const t_vec3 v2, t_status *status)
{
	double	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	if (!isfinite(res))
	{
		if (status)
			*status = OVERFLOW;
		return (0);
	}
	return (res);
}

t_vec3	vec_cross(const t_vec3 v1, const t_vec3 v2, t_status *status)
{
	t_vec3	res;

	res = (t_vec3){v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x};
	if (!isfinite(res.x) || !isfinite(res.y) || !isfinite(res.z))
	{
		if (status)
			*status = OVERFLOW;
		return ((t_vec3){0.0, 0.0, 0.0});
	}
	return (res);
}
