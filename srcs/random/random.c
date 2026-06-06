/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 10:51:43 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/06 11:33:47 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/lib_tools/includes/math_ops.h"
#include <math.h>
#include <sys/time.h>
#include <stdio.h>

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
	const long int	a = 9348324;
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

t_vec3	random_vec3(double min, double max)
{
	return ((t_vec3){random_double2(min, max),
			random_double2(min, max),
			random_double2(min, max)});	
}

t_vec3	random_unit_vec3(void)
{
	t_vec3	vec;
	double	lensq;

	while (1)
	{
		vec = random_vec3(-1, 1);
		lensq = vec_squared_magnitude(vec);
		if (lensq > 1e-160 && lensq <= 1)
			return (vec_scale(vec, 1 / sqrt(lensq)));
	}
	return (random_vec3(0, 1));
}

t_vec3	random_surface_vec3(const t_vec3	normal)
{
	t_vec3	vec;

	vec = random_unit_vec3();
	if (vec_dot(vec, normal) > 0)
		return (vec);
	return (vec_scale(vec, -1));
}
