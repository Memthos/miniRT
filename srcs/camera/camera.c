/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:26:13 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/21 10:43:10 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	camera_init(double fov)
{
	t_camera	camera;

	ft_bzero(&camera, sizeof(camera));
	camera.height = 2.0;
	camera.width = camera.height * (16.0 / 9.0);
	camera.focal_length = 1.0;
	camera.fov = fov;
	return (camera);
}
