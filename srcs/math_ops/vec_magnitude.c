/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_magnitude.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:57:44 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/19 10:52:57 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_ops.h"

double	vec_squared_magnitude(t_vec3 v1)
{
	double	res;

	res = v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
	if (!isfinite(res))
	{
		if (res < 0)
			use_status(UNDERFLOW);
		else
			use_status(OVERFLOW);
		print_status("vec_squared_magnitude");
		return (0);
	}
	return (res);
}

double	vec_magnitude(t_vec3 v1)
{
	double	squared;
	double	res;

	squared = vec_squared_magnitude(v1);
	if (use_status(ERR_GET) != SUCCESS)
		return (0);
	res = sqrt(squared);
	if (!isfinite(res))
	{
		if (res < 0)
			use_status(UNDERFLOW);
		else
			use_status(OVERFLOW);
		print_status("vec_magnitude");
		return (0);
	}
	return (res);
}
