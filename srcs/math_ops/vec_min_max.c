/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:55:27 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 15:57:24 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_ops.h"

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
