/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:00:19 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/19 17:15:31 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdint.h>
# include <stdlib.h>

# include "../libs/lib_tools/includes/lib_tools.h"

typedef struct s_minirt	t_minirt;

typedef void (*t_parse_func)(t_string *, t_minirt *);

typedef struct s_parse_func_id
{
	t_string		type;
	t_parse_func	func;
}	t_parse_func_id;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	AMBIENT_LIGHT,
	POINT_LIGHT,
	CAMERA,
}	t_obj_type;

/*-----------------------------------GEO--------------------------------------*/
typedef struct s_sphere
{
	t_vec3		position;
	double		diameter;
	uint32_t	color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3		position;
	t_vec3		norm_rot;
	double		diameter;
	uint32_t	color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3		position;
	t_vec3		norm_rot;
	double		diameter;
	double		height;
	uint32_t	color;
}	t_cylinder;

/*-----------------------------------LIGHT------------------------------------*/
typedef struct s_ambient_light
{
	double		brightness;
	uint32_t	color;
}	t_ambient_light;

typedef struct s_point_light
{
	t_vec3		position;
	double		brightness;
}	t_point_light;

/*-----------------------------------ARRAY------------------------------------*/
typedef struct s_obj
{
	t_obj_type	type;
	union
	{
		t_sphere		sphere;
		t_plane			plane;
		t_cylinder		cylinder;
		t_ambient_light	ambient_light;
		t_point_light	point_light;
	}	u_obj;
}	t_obj;

typedef struct s_array
{
	t_obj	*objs;
	size_t	size;
}	t_array;

/*-----------------------------------END--------------------------------------*/

t_status	add_array_slot(t_array array);

#endif
