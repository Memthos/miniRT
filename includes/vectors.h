/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:47:50 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/13 13:43:11 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include "types.h"

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

t_vec3	vec_add(const t_vec3 v1, const t_vec3 v2, t_status *status);
t_vec3	vec_sub(const t_vec3 v1, const t_vec3 v2, t_status *status);
t_vec3	vec_scale(const t_vec3 v1, const double lambda, t_status *status);
double	vec_dot(const t_vec3 v1, const t_vec3 v2, t_status *status);
t_vec3	vec_cross(const t_vec3 v1, const t_vec3 v2, t_status *status);
double	vec_min(const t_vec3 v1);
double	vec_max(const t_vec3 v1);
double	vec_squared_magnitude(t_vec3 v1, t_status *status);
double	vec_magnitude(t_vec3 v1, t_status *status);
t_vec3	vec_normalize(const t_vec3 v1, t_status *status);

#endif
