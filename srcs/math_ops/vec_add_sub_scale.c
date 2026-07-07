/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_add_sub_scale.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:58:35 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/19 10:51:21 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_ops.h"

t_vec3	vec_add(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	res;

	res = (t_vec3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z};
	if (!isfinite(res.x) || !isfinite(res.y) || !isfinite(res.z))
	{
		if (res.x < 0 || res.y < 0 || res.z < 0)
			use_status(UNDERFLOW);
		else
			use_status(OVERFLOW);
		print_status("vec_add");
		return ((t_vec3){0.0, 0.0, 0.0});
	}
	return (res);
}

t_vec3	vec_sub(const t_vec3 v1, const t_vec3 v2)
{
	t_vec3	res;

	res = (t_vec3){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z};
	if (!isfinite(res.x) || !isfinite(res.y) || !isfinite(res.z))
	{
		if (res.x < 0 || res.y < 0 || res.z < 0)
			use_status(UNDERFLOW);
		else
			use_status(OVERFLOW);
		print_status("vec_sub");
		return ((t_vec3){0.0, 0.0, 0.0});
	}
	return (res);
}

t_vec3	vec_scale(const t_vec3 v1, const double lambda)
{
	t_vec3	res;

	res = (t_vec3){v1.x * lambda, v1.y * lambda, v1.z * lambda};
	if (!isfinite(res.x) || !isfinite(res.y) || !isfinite(res.z))
	{
		if (res.x < 0 || res.y < 0 || res.z < 0)
			use_status(UNDERFLOW);
		else
			use_status(OVERFLOW);
		print_status("vec_scale");
		return ((t_vec3){0.0, 0.0, 0.0});
	}
	return (res);
}
