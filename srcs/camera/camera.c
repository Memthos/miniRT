/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:26:13 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/08 16:37:48 by juperrin         ###   ########.fr       */
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
	return (cam);
}

t_camera	*camera_update(t_camera *cam, t_aa aa, t_utime delta, const t_vec2 screen)
{
	const t_vec3	vup = {0, 1, 0};
	const t_vec3	vel = vec_add(
			vec_scale(cam->dir, cam->move.velocity.z),
			vec_add(
				vec_scale(cam->right, cam->move.velocity.x),
				vec_scale(cam->up, cam->move.velocity.y)));
	t_vec3			vx;
	t_vec3			vy;

	cam->right = vec_cross(vup, cam->dir);
	if (0 == cam->right.x && 0 == cam->right.y && 0 == cam->right.z)
		cam->right = (t_vec3){1, 0, 0};
	cam->right = vec_normalize(cam->right);
	cam->up = vec_cross(cam->dir, cam->right);
	vx = vec_scale(cam->right, cam->viewport.width);
	vy = vec_scale(cam->up, -cam->viewport.height);
	cam->aa = aa;
	cam->pos = vec_add(cam->pos, vec_scale(vel, cam->move.speed * (delta * 0.000001)));
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
