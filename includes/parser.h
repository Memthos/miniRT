/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:00:19 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/19 17:19:09 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdint.h>
# include <stdlib.h>

# include "../libs/lib_tools/includes/lib_tools.h"

typedef struct s_minirt	t_minirt;

typedef void			(*t_parse_func)(const t_string *, t_minirt *);

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
	uint32_t	color;
}	t_point_light;

/*----------------------------------CAMERA------------------------------------*/
typedef struct s_camera
{
	t_vec3		position;
	t_vec3		norm_rot;
	double		fov;
	t_vec2		clip_planes;
	t_vec2		plane;
}	t_camera;

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
typedef struct s_unique_obj
{
	int	camera;
	int	ambient_light;
	int	point_light;
}	t_unique_obj;

t_status	rt_add_array_slot(t_array *array, t_obj obj);

void		rt_parse_sphere(const t_string *line, t_minirt *rt);
void		rt_parse_plane(const t_string *line, t_minirt *rt);
void		rt_parse_cylinder(const t_string *line, t_minirt *rt);
void		rt_parse_ambient_light(const t_string *line, t_minirt *rt);
void		rt_parse_point_light(const t_string *line, t_minirt *rt);

void		rt_parse_coords(const t_string *input, t_vec3 *pos);
void		rt_parse_orientation(const t_string *input, t_vec3 *norm_rot);
void		rt_parse_color(const t_string *input, uint32_t *color);

#endif
