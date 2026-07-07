/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 10:42:23 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/19 15:10:42 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_status	check_overflow(const double nb)
{
	if (!isfinite(nb))
	{
		if (nb < 0)
			use_status(UNDERFLOW);
		else
			use_status(OVERFLOW);
		print_status("ft_strtod");
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	add_dot(double *res, const t_string str, size_t *i)
{
	size_t	divider;

	divider = 1;
	++(*i);
	while (ft_isdigit(str[*i]) == SUCCESS)
	{
		if (divider >= (size_t) - 1 / 10)
		{
			use_status(OVERFLOW);
			print_status("ft_strtod");
		}
		divider *= 10;
		*res += (str[(*i)++] - '0') / (double)divider;
		if (check_overflow(*res) == FAILURE)
		{
			*res = 0.0;
			return ;
		}
	}
}

double	ft_strtod(const t_string str, t_string *endptr)
{
	size_t	i;
	int		sign;
	double	res;

	i = 0;
	sign = 1;
	res = 0.0;
	while (ft_isspace(str[i]) == SUCCESS)
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = (str[i++] % 43) * -1 + 1;
	while (ft_isdigit(str[i]) == SUCCESS)
	{
		res = (res * 10) + (str[i++] - '0');
		if (check_overflow(res) == FAILURE)
			return (0.0);
	}
	if (str[i] == '.')
		add_dot(&res, str, &i);
	if (endptr && str[i])
		*endptr = &str[i];
	return (res * sign);
}
