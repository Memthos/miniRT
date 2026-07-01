/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:02:44 by juperrin          #+#    #+#             */
/*   Updated: 2026/07/01 08:25:32 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "ray.h"
# include "interval.h"

typedef struct s_minirt		t_minirt;
typedef struct s_hit_point	t_hit_point;
typedef struct s_obj		t_obj;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	AMBIENT_LIGHT,
	POINT_LIGHT,
	CAMERA,
}	t_obj_type;

typedef struct s_ambient_light
{
	double	brightness;
	t_rgb	color;
}	t_ambient_light;

typedef struct s_point_light
{
	t_vec3	position;
	double	brightness;
}	t_point_light;

typedef struct s_sphere
{
	t_vec3	position;
	double	diameter;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	position;
	t_vec3	norm_rot;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	position;
	t_vec3	norm_rot;
	double	diameter;
	double	height;
}	t_cylinder;

typedef bool				(*t_hit_func)(t_ray *, t_obj *, t_interval,
								t_hit_point *);

typedef struct s_obj
{
	t_obj_type	type;
	union
	{
		t_sphere		sphere;
		t_plane			plane;
		t_cylinder		cylinder;
		t_point_light	point_light;
	}	u_obj;
	t_material	mat;
	t_hit_func	hit;
}	t_obj;

typedef struct s_obj_ret
{
	double	val;
	bool	ret;
}	t_obj_ret;

bool	hit_sphere(t_ray *ray, t_obj *sphere, t_interval i, t_hit_point *p);
bool	hit_cylinder(t_ray *ray, t_obj *cylinder, t_interval i, t_hit_point *p);
bool	hit_plane(t_ray *ray, t_obj *plane, t_interval i, t_hit_point *p);
bool	hit_light(t_ray *ray, t_obj *light, t_interval i, t_hit_point *p);

void	move_object(t_minirt *rt);
void	rotate_object(t_minirt *rt);
void	scale_object(t_minirt *rt);

void	get_hit_obj(t_minirt *rt, t_point3 pixel_point, const t_interval i);

#endif
