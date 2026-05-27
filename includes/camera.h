/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:15:36 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/27 10:45:44 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "../libs/lib_tools/includes/math_ops.h"

typedef struct s_vec3	t_point3;

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
	double		fov;
	t_aa		aa;
	t_point3	pos;
	t_point3	dir;
	t_vec3		norm_rot;
	t_viewport	viewport;
}	t_camera;

t_camera	*camera_init(t_camera *cam, t_vec2 screen);

#endif