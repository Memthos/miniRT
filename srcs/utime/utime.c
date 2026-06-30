/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:49:10 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/30 17:34:28 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_utime	get_utime(void)
{
	struct timeval	t;

	if (SUCCESS != gettimeofday(&t, NULL))
		return (0);
	return ((t_utime)t.tv_sec * 1000000 + t.tv_usec);
}

t_utime	get_delta_time(void)
{
	static t_utime	last = 0;
	t_utime			cur;
	t_utime			delta;

	cur = get_utime();
	delta = cur - last;
	last = cur;
	return (delta);
}
