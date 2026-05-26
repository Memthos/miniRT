/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interval.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:45:40 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/26 15:07:54 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERVAL_H
# define INTERVAL_H

typedef struct s_interval
{
	double	min;
	double	max;
}	t_interval;

double	interval_size(t_interval *inter);

bool	interval_contains(t_interval *inter, double x);

bool	interval_surrounds(t_interval *inter, double x);

#endif
