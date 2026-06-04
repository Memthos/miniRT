/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:24:04 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/04 09:59:04 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_minirt	*rt_init(t_minirt *rt)
{
	const int				width = 1280;
	mlx_window_create_info	info;

	rt->should_render = true;
	rt->aspect_ratio = 16.0 / 9.0;
	rt->sensibility = 0.005;
	rt->dimensions = (t_vec2){width, width / rt->aspect_ratio};
	rt->max_quality = (t_quality){1, (t_vec2){width / 10,
		rt->dimensions.y / 10}, (t_aa){3, 1 / 9.0}};
	rt->min_quality = (t_quality){0.1, rt->dimensions, (t_aa){1, 1}};
	rt->cur_quality = &rt->max_quality;
	rt->context = mlx_init();
	ft_bzero(&info, sizeof(info));
	info.title = "miniRT";
	info.width = rt->dimensions.x;
	info.height = rt->dimensions.y;
	rt->window = mlx_new_window(rt->context, &info);
	rt->render = mlx_new_image(rt->context, rt->dimensions.x, rt->dimensions.y);
	mouse_init(rt);
	camera_init(&rt->camera, rt->cur_quality->aa, rt->dimensions);
	rt_init_events(rt);
	return (rt);
}
