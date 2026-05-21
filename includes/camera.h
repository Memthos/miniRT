/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:15:36 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/21 10:43:49 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "../libs/lib_tools/includes/math_ops.h"

typedef struct s_vec3	t_point3;

typedef struct s_camera
{
	double		focal_length;
	double		fov;
	double		width;
	double		height;
	t_point3	position;
}	t_camera;

t_camera	camera_init(double fov);

#endif