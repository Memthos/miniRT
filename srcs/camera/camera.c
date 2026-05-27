/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:26:13 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/27 17:51:31 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*camera_init(t_camera *cam, t_vec2 screen)
{
	const t_vec3	vup = {0, 1, 0};

	cam->aa.size = 2;
	cam->aa.scale = 1.0 / (double)(cam->aa.size * cam->aa.size);
	cam->dir = (t_vec3){0, 0, 1};
	cam->focal_length = vec_magnitude(cam->dir);
	cam->viewport.height = 2.0 * tan(cam->vfov * deg_to_rad() / 2) * cam->focal_length;
	cam->viewport.width = cam->viewport.height * (16.0 / 9.0);
	t_vec3	w = vec_normalize(vec_scale(cam->dir, -1));
	t_vec3	u = vec_normalize(vec_cross(vup, w));
	t_vec3	v = vec_cross(w, u);
	t_vec3	vx = vec_scale(u, cam->viewport.width);
	t_vec3	vy = vec_scale(v, -cam->viewport.height);
	cam->viewport.delta_x = vec_scale(vx, 1 / screen.x);
	cam->viewport.delta_y =  vec_scale(vy, 1 / screen.y);
	cam->viewport.nw_corner = vec_sub(cam->pos, vec_scale(w, cam->focal_length));
	cam->viewport.nw_corner = vec_sub(cam->viewport.nw_corner, vec_scale(vx, 0.5));
	cam->viewport.nw_corner = vec_sub(cam->viewport.nw_corner, vec_scale(vy, 0.5));
	cam->viewport.nw_pixel = cam->viewport.nw_corner;
	return (cam);
}
