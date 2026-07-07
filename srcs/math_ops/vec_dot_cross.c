/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dot_cross.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:01:15 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/19 10:52:03 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_ops.h"

double	vec_dot(const t_vec3 v1, const t_vec3 v2)
{
	double	res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	if (!isfinite(res))
	{
		if (res < 0)
			use_status(UNDERFLOW);
		else
			use_status(OVERFLOW);
		print_status("vec_dot");
		return (0);
	}
	return (res);
}

t_vec3	vec_cross(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	res;

	res = (t_vec3){v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x};
	if (!isfinite(res.x) || !isfinite(res.y) || !isfinite(res.z))
	{
		if (res.x < 0 || res.y < 0 || res.z < 0)
			use_status(UNDERFLOW);
		else
			use_status(OVERFLOW);
		print_status("vec_cross");
		return ((t_vec3){0.0, 0.0, 0.0});
	}
	return (res);
}
