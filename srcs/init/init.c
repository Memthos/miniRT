/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:24:04 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/01 13:59:16 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_minirt	*rt_init(t_minirt *rt)
{
	const int				width = 1280;
	mlx_window_create_info	info;

	rt->aspect_ratio = 16.0 / 9.0;
	rt->scale = 1;
	rt->dimensions = (t_vec2){width, width / rt->aspect_ratio};
	rt->context = mlx_init();
	ft_bzero(&info, sizeof(info));
	info.title = "miniRT";
	info.width = rt->dimensions.x;
	info.height = rt->dimensions.y;
	rt->window = mlx_new_window(rt->context, &info);
	rt->render = mlx_new_image(rt->context, rt->dimensions.x, rt->dimensions.y);
	camera_init(&rt->camera, rt->dimensions);
	rt_init_events(rt);
	return (rt);
}
