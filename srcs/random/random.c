/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 10:51:43 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/29 11:34:23 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sys/time.h>

long int	seed(void)
{
	struct timeval	time;
	static long int	seed = 0;

	if (0 == seed)
	{
		gettimeofday(&time, 0);
		seed = time.tv_sec * time.tv_usec + 1;
	}
	return (seed);
}
double	random_double(void)
{
	static double	num = 0;
	return (num);
}
