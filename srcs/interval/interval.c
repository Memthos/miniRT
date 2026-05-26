/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:45:26 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/26 15:43:21 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	interval_size(const t_interval *inter)
{
	return (inter->max - inter->min);
}

bool	interval_contains(const t_interval *inter, double x)
{
	return (x >= inter->min && x <= inter->max);
}

bool	interval_surrounds(const t_interval *inter, double x)
{
	return (x > inter->min && x < inter->max);
}

double	interval_clamp(const t_interval *inter, double x)
{
	if (x < inter->min)
		return (inter->min);
	if (x > inter->max)
		return (inter->max);
	return (x);
}
