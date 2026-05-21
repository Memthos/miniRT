/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:26:13 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/21 14:26:00 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	camera_init(double fov, t_vec2 screen)
{
	t_camera	camera;

	camera.focal_length = 1.0;
	camera.fov = fov;
	camera.viewport.height = 2.0;
	camera.viewport.width = camera.viewport.height * (16.0 / 9.0);
	camera.viewport.delta_x = (t_vec3){camera.viewport.width / screen.x, 0, 0};
	camera.viewport.delta_y = (t_vec3){0, -camera.viewport.height / screen.y, 0};
	camera.viewport.nw_corner = vec_sub(camera.pos, (t_vec3){0, 0, camera.focal_length});
	camera.viewport.nw_corner = vec_sub(camera.viewport.nw_corner, vec_scale((t_vec3){camera.viewport.width, 0, 0}, 0.5));
	camera.viewport.nw_corner = vec_sub(camera.viewport.nw_corner, vec_scale((t_vec3){0, -camera.viewport.height, 0}, 0.5));
	camera.viewport.nw_pixel = vec_add(camera.viewport.nw_corner, vec_scale(vec_add(camera.viewport.delta_x, camera.viewport.delta_y), 0.5));
	return (camera);
}
