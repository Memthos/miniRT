/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:26:13 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/03 12:24:50 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*camera_init(t_camera *cam, t_aa aa, const t_vec2 screen)
{
	cam->focal_length = (screen.x / 2.0) / tan(cam->hfov * deg_to_rad() / 2);
	cam->viewport.width = 2.0 * tan(cam->hfov * deg_to_rad() / 2);
	cam->viewport.height = cam->viewport.width / (16.0 / 9.0);
	cam->move.speed = 1;
	camera_update(cam, aa, 0, screen);
	// printf("Camera direction : [%f, %f, %f]\n", cam->dir.x, cam->dir.y, cam->dir.z);
	// printf("focal length : %f\n", cam->focal_length);
	// printf("Viewport dimensions : [%f, %f]\n", cam->viewport.width, cam->viewport.height);
	// printf("u : [%f, %f, %f]\n", u.x, u.y, u.z);
	// printf("v : [%f, %f, %f]\n", v.x, v.y, v.z);
	// printf("delta : [%f, %f]\n", cam->viewport.delta_x.x, cam->viewport.delta_y.y);
	// printf("north-west corner position : [%f, %f, %f]\n", cam->viewport.nw_corner.x, cam->viewport.nw_corner.y, cam->viewport.nw_corner.z);
	return (cam);
}

t_camera	*camera_update(t_camera *cam, t_aa aa, t_utime delta, const t_vec2 screen)
{
	const t_vec3	vup = {0, 1, 0};
	t_vec3			vx;
	t_vec3			vy;

	cam->right = vec_normalize(vec_cross(vup, cam->dir));
	cam->up = vec_cross(cam->dir, cam->right);
	vx = vec_scale(cam->right, cam->viewport.width);
	vy = vec_scale(cam->up, -cam->viewport.height);

	cam->aa = aa;
	cam->pos = vec_add(cam->pos, vec_scale(cam->move.velocity, cam->move.speed * (delta * 0.000001)));
	cam->viewport.delta_x = vec_scale(vx, 1.0 / screen.x);
	cam->viewport.delta_y =  vec_scale(vy, 1.0 / screen.y);
	cam->viewport.nw_corner = vec_add(cam->pos, cam->dir);
	cam->viewport.nw_corner = vec_sub(cam->viewport.nw_corner, vec_scale(vx, 0.5));
	cam->viewport.nw_corner = vec_sub(cam->viewport.nw_corner, vec_scale(vy, 0.5));
	cam->viewport.nw_pixel = cam->viewport.nw_corner;
	return (cam);
}

bool	camera_is_moving(t_camera *cam)
{
	if (NULL == cam)
		return (false);
	return (cam->move.moving[0] || cam->move.moving[1]
		|| cam->move.moving[2] || cam->move.moving[3]
		|| cam->move.moving[4] || cam->move.moving[5]);
}
