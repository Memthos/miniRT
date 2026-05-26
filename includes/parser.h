/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:00:19 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/26 13:14:29 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "objects.h"
# include "../libs/lib_tools/includes/lib_tools.h"
# include "../libs/MacroLibX/includes/mlx.h"

typedef struct s_minirt	t_minirt;

typedef void			(*t_parse_func)(const t_string *, t_minirt *);

typedef struct s_parse_func_id
{
	t_string		type;
	t_parse_func	func;
}	t_parse_func_id;

/*-----------------------------------ARRAY------------------------------------*/

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

void		rt_parser(const t_string filename, t_minirt *rt);

void		rt_parse_sphere(const t_string *line, t_minirt *rt);
void		rt_parse_plane(const t_string *line, t_minirt *rt);
void		rt_parse_cylinder(const t_string *line, t_minirt *rt);
void		rt_parse_ambient_light(const t_string *line, t_minirt *rt);
void		rt_parse_point_light(const t_string *line, t_minirt *rt);

void		rt_parse_coords(const t_string *input, t_vec3 *pos);
void		rt_parse_orientation(const t_string *input, t_vec3 *norm_rot);
void		rt_parse_color(const t_string *input, mlx_color *color);

t_status	rt_add_array_slot(t_array *array, t_obj *obj);

#endif
