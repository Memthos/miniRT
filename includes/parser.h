#ifndef PARSER_H
# define PARSER_H

# include "../libs/lib_tools/includes/lib_tools.h"

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
	double		ratio;
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
	union u_obj
	{
		t_sphere		sphere;
		t_plane			plane;
		t_cylinder		cylinder;
		t_ambient_light	ambient_light;
		t_point_light	point_light;
		t_camera		camera;
	};
}	t_obj;

typedef struct s_array
{
	t_obj	*objs;
	size_t	size;
}	t_array;

/*-----------------------------------END--------------------------------------*/
#endif
