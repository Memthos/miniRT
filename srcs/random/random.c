/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 10:51:43 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/06 09:21:10 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <sys/time.h>

long int	seed(void)
{
	struct timeval	time;
	static long int	seed = 0;

	if (0 == seed)
	{
		gettimeofday(&time, 0);
		seed = time.tv_sec * (time.tv_usec + 1);
	}
	return (seed);
}

double	random_double(void)
{
	static long int	num = 0;
	double 			mantissa;
	const long int	a = 103948257;
	const long int	c = seed();
	const int		m = 1000000000;

	num = (a * num + c) % m;
	mantissa = (a * num + c) % m;
	return (num + mantissa / pow(10, (long)log10(mantissa) + 1));
}

double	random_normed_double(void)
{
	const double	r = random_double();

	return (r / pow(10, (long)log10(r) + 1));
}

double	random_double2(double min, double max)
{
	return (min + (max - min) * random_normed_double());
}
