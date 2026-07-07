/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:16:56 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/19 10:50:26 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_ops.h"

double	ft_round(double nb, t_uint precision)
{
	t_uint	i;
	double	res;

	i = 0;
	while (i < precision)
	{
		if (!isfinite(nb))
		{
			if (nb < 0)
				use_status(UNDERFLOW);
			else
				use_status(OVERFLOW);
			print_status("ft_round");
			return (0);
		}
		nb *= 10;
		i++;
	}
	res = round(nb) / pow(10.0, precision);
	return (res);
}
