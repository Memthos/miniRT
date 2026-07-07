/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:33:47 by mperrine          #+#    #+#             */
/*   Updated: 2026/06/03 16:16:18 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_ops.h"

t_vec3	vec_rotate(t_vec3 v1, t_vec3 axis, double angle)
{
	const double	cos_a = cos(angle);
	const double	sin_a = sin(angle);
	t_vec3			res;

	res = vec_add(
			vec_add(vec_scale(v1, cos_a),
				vec_scale(vec_cross(axis, v1), sin_a)),
			vec_scale(axis, vec_dot(axis, v1) * (1.0 - cos_a)));
	if (!isfinite(res.x) || !isfinite(res.y) || !isfinite(res.z))
	{
		if (res.x < 0 || res.y < 0 || res.z < 0)
			use_status(UNDERFLOW);
		else
			use_status(OVERFLOW);
		print_status("vec_rotate");
		return ((t_vec3){0.0, 0.0, 0.0});
	}
	return (res);
}
