/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:26:13 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/27 17:05:01 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*camera_init(t_camera *cam, t_vec2 screen)
{
	cam->aa.size = 2;
	cam->aa.scale = 1.0 / (double)(cam->aa.size * cam->aa.size);
	cam->dir = (t_vec3){0, 0, -1};
	cam->focal_length = 1.0;
	cam->viewport.height = 2.0 * tan(cam->vfov * deg_to_rad() / 2) * cam->focal_length;
	cam->viewport.width = cam->viewport.height * (16.0 / 9.0);
	cam->viewport.delta_x = (t_vec3){cam->viewport.width / screen.x, 0, 0};
	cam->viewport.delta_y = (t_vec3){0, -cam->viewport.height / screen.y, 0};
	cam->viewport.nw_corner = vec_sub(cam->pos, (t_vec3){0, 0, cam->focal_length});
	cam->viewport.nw_corner = vec_sub(cam->viewport.nw_corner, vec_scale((t_vec3){cam->viewport.width, 0, 0}, 0.5));
	cam->viewport.nw_corner = vec_sub(cam->viewport.nw_corner, vec_scale((t_vec3){0, -cam->viewport.height, 0}, 0.5));
	cam->viewport.nw_pixel = cam->viewport.nw_corner;
	return (cam);
}
