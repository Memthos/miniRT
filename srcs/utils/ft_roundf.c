/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:52:09 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/10 23:02:19 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_roundf(double nb, t_uint precision, t_status *status)
{
	t_uint	i;
	double	res;

	i = 0;
	while (i < precision)
	{
		if (nb > ((t_uint) -1) / 10)
		{
			if (status)
				*status = OVERFLOW;
			return (0);
		}
		nb *= 10;
		i++;
	}
	res = (int) nb;
	i = 0;
	while (i < precision)
	{
		res /= 10;
	
		i++;
	}
	return (res);
}
