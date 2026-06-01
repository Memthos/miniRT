/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:26:13 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/29 15:09:02 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*camera_init(t_camera *cam, const t_vec2 screen)
{
	cam->aa.size = 1;
	cam->aa.scale = 1.0 / (double)(cam->aa.size * cam->aa.size);
	cam->focal_length = vec_magnitude(cam->dir);
	cam->viewport.width = 2.0 * tan(cam->hfov * deg_to_rad() / 2);
	cam->viewport.height = cam->viewport.width / (16.0 / 9.0);
	camera_update(cam, screen);
	// printf("Camera direction : [%f, %f, %f]\n", cam->dir.x, cam->dir.y, cam->dir.z);
	// printf("focal length : %f\n", cam->focal_length);
	// printf("Viewport dimensions : [%f, %f]\n", cam->viewport.width, cam->viewport.height);
	// printf("u : [%f, %f, %f]\n", u.x, u.y, u.z);
	// printf("v : [%f, %f, %f]\n", v.x, v.y, v.z);
	// printf("delta : [%f, %f]\n", cam->viewport.delta_x.x, cam->viewport.delta_y.y);
	// printf("north-west corner position : [%f, %f, %f]\n", cam->viewport.nw_corner.x, cam->viewport.nw_corner.y, cam->viewport.nw_corner.z);
	return (cam);
}

t_camera	*camera_update(t_camera *cam, const t_vec2 screen)
{
	const t_vec3	vup = {0, 1, 0};
	const t_vec3	u = vec_normalize(vec_cross(vup, cam->dir));
	const t_vec3	v = vec_cross(cam->dir, u);
	const t_vec3	vx = vec_scale(u, cam->viewport.width);
	const t_vec3	vy = vec_scale(v, -cam->viewport.height);

	cam->viewport.delta_x = vec_scale(vx, 1.0 / screen.x);
	cam->viewport.delta_y =  vec_scale(vy, 1.0 / screen.y);
	cam->viewport.nw_corner = vec_add(cam->pos, cam->dir);
	cam->viewport.nw_corner = vec_sub(cam->viewport.nw_corner, vec_scale(vx, 0.5));
	cam->viewport.nw_corner = vec_sub(cam->viewport.nw_corner, vec_scale(vy, 0.5));
	cam->viewport.nw_pixel = cam->viewport.nw_corner;
	return (cam);
}
