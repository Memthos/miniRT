/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:45:40 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/26 15:43:06 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERVAL_H
# define INTERVAL_H

typedef struct s_interval
{
	double	min;
	double	max;
}	t_interval;

double	interval_size(const t_interval *inter);

bool	interval_contains(const t_interval *inter, double x);

bool	interval_surrounds(const t_interval *inter, double x);

double	interval_clamp(const t_interval *inter, double x);

#endif
