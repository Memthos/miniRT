/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:49:10 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/03 10:58:01 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

time_t	get_time(void)
{
	struct timeval	t;

	if (SUCCESS != gettimeofday(&t, NULL))
		return (0);
	return (t.tv_sec * 0.001 + t.tv_usec * 1000);		
}
