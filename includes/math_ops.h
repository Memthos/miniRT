/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ops.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 10:19:50 by mperrine          #+#    #+#             */
/*   Updated: 2026/06/03 14:38:36 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_OPS_H
# define MATH_OPS_H

# include <math.h>
# include "../libs/lib_tools/includes/lib_tools.h"

# define M_PI 3.14159265358979323846

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

typedef struct s_vec2
{
	double	x;
	double	y;
}			t_vec2;

double	ft_round(double nb, t_uint precision);
double	ft_strtod(const t_string str, t_string *endptr);
double	deg_to_rad(void);
t_vec3	vec_add(const t_vec3 v1, const t_vec3 v2);
t_vec3	vec_sub(const t_vec3 v1, const t_vec3 v2);
t_vec3	vec_scale(const t_vec3 v1, const double lambda);
double	vec_dot(const t_vec3 v1, const t_vec3 v2);
t_vec3	vec_cross(const t_vec3 v1, const t_vec3 v2);
double	vec_min(const t_vec3 v1);
double	vec_max(const t_vec3 v1);
double	vec_squared_magnitude(t_vec3 v1);
double	vec_magnitude(t_vec3 v1);
t_vec3	vec_normalize(const t_vec3 v1);
t_vec3	vec_rotate(t_vec3 v1, t_vec3 axis, double angle);

#endif
