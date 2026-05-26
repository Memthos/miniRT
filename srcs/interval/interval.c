/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:45:26 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/26 15:07:49 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	interval_size(t_interval *inter)
{
	return (inter->max - inter->min);
}

bool	interval_contains(t_interval *inter, double x)
{
	return (x >= inter->min && x <= inter->max);
}

bool	interval_surrounds(t_interval *inter, double x)
{
	return (x > inter->min && x < inter->max);
}
