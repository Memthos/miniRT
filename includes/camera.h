/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 09:19:57 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/13 13:47:45 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "types.h"
# include "vectors.h"

typedef struct s_camera
{
	double	fov;
	t_vec2	clip_planes;
	t_vec2	plane;
	t_vec3	position;
	t_vec3	rotation;
}	t_camera;

#endif
