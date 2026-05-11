/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:52:09 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/11 14:14:09 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_round(double nb, t_uint precision, t_status *status)
{
	t_uint	i;
	double	res;

	i = 0;
	while (i < precision)
	{
		if (ceil(nb) >= DBL_MAX / 10)
		{
			if (status)
				*status = OVERFLOW;
			return (0);
		}
		nb *= 10;
		i++;
	}
	res = round(nb) / pow(10.0, precision);
	return (res);
}
