/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 14:33:42 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/12 12:36:19 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "../libs/lib_tools/includes/math_ops.h"


typedef struct s_ray		t_ray;
typedef struct s_hit_point	t_hit_point;
typedef struct s_vec3		t_rgb;
typedef bool	(*t_scatter_func)(t_ray *in, t_ray *out, t_hit_point *p);
typedef t_rgb	(*t_emit_func)(t_hit_point *p);

typedef struct s_material
{
	t_rgb			col;
	t_scatter_func	scatter;
	t_emit_func		emit;
}	t_material;

t_material	mat_lambertian(t_rgb col);

t_material	mat_emission(t_rgb col);

#endif
