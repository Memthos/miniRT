/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:15:36 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/01 13:21:18 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "../libs/lib_tools/includes/math_ops.h"

typedef struct s_vec3	t_point3;

enum	e_moving_index
{
	MOVING_LEFT,
	MOVING_RIGHT,
	MOVING_FORWARD,
	MOVING_BACKWARD,
	MOVING_UP,
	MOVING_DOWN
};

typedef struct s_movement
{
	bool	moving[6];
	double	speed;
	t_vec3	velocity;
}	t_move;

typedef struct s_antialiasing
{
	t_uint	size;
	double	scale;
}	t_aa;

typedef struct s_viewport
{
	double		width;
	double		height;
	t_vec3		delta_x;
	t_vec3		delta_y;
	t_point3	nw_corner;
	t_point3	nw_pixel;
}	t_viewport;

typedef struct s_camera
{
	double		focal_length;
	double		hfov;
	t_aa		aa;
	t_point3	pos;
	t_point3	dir;
	t_move		move;
	t_viewport	viewport;
}	t_camera;

t_camera	*camera_init(t_camera *cam, t_vec2 screen);

t_camera	*camera_update(t_camera *cam, const t_vec2 screen);

bool		camera_is_moving(t_camera *cam);

#endif