/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:32:40 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/20 12:53:57 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "../libs/lib_tools/includes/math_ops.h"

typedef struct s_vec3	t_point3;

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		dir;
}	t_ray;

t_point3	ray_at(t_ray *ray, double delta);

mlx_color	ray_color(t_minirt *rt, t_ray *ray);

void	display_vec(t_vec3	*vec);

#endif
