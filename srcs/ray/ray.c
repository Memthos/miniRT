/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:37:51 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/21 10:23:00 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point3	ray_at(t_ray *ray, double delta)
{
	t_point3	point;

	point = vec_add(ray->origin, vec_scale(ray->dir, delta));
	return (point);
}

mlx_color	ray_color(t_minirt *rt, t_ray *ray)
{
	mlx_color c;

	(void)rt;
	c = (mlx_color){.r = 0, .b = 0, .b = 0, .a = 0};
	return (c);
}
