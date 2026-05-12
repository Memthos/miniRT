/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_ops_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:58:14 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/12 10:07:12 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_min(const t_vec3 v1)
{
	if (v1.x < v1.y && v1.x < v1.z)
		return (v1.x);
	else if (v1.y < v1.x && v1.y < v1.z)
		return (v1.y);
	else
		return (v1.z);
}

double	vec_max(const t_vec3 v1)
{
	if (v1.x > v1.y && v1.x > v1.z)
		return (v1.x);
	else if (v1.y > v1.x && v1.y > v1.z)
		return (v1.y);
	else
		return (v1.z);
}

double	vec_squared_magnitude(t_vec3 v1, t_status *status)
{
	double	res;

	res = v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
	if (!isfinite(res))
	{
		if (status)
			*status = OVERFLOW;
		return (0);
	}
	return (res);
}

double	vec_magnitude(t_vec3 v1, t_status *status)
{
	double	squared;
	double	res;

	squared = vec_squared_magnitude(v1, status);
	if (*status)
		return (0);
	res = sqrt(squared);
	if (!isfinite(res))
	{
		if (status)
			*status = OVERFLOW;
		return (0);
	}
	return (res);
}

t_vec3	vec_normalize(const t_vec3 v1, t_status *status)
{
	double	magnitude;
	t_vec3	res;

	magnitude = vec_magnitude(v1, status);
	if (*status)
		return ((t_vec3){0.0, 0.0, 0.0});
	if (magnitude == 0.0)
	{
		if (status)
			*status = ZERO_DIVISION;
		return ((t_vec3){0.0, 0.0, 0.0});
	}
	res = (t_vec3){v1.x / magnitude, v1.y / magnitude, v1.z / magnitude};
	return (res);
}
