/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:32:40 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/02 10:04:46 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "camera.h"
# include "../libs/lib_tools/includes/math_ops.h"

typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_rgb;

typedef struct s_hit_point
{
	t_point3	point;
	t_vec3		normal;
	double		t;
	bool		front;
}	t_hit_point;

typedef struct s_ray
{
	t_point3	origin;
	t_vec3		dir;
}	t_ray;

t_ray		ray_gen(t_camera *cam, int pos[2], int delta[2]);

t_point3	ray_at(t_ray *ray, double delta);

t_rgb		ray_color(t_minirt *rt, t_ray *ray);

#endif
