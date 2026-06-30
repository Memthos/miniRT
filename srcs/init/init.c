/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:24:04 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/30 16:29:22 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_quality(t_minirt *rt)
{
	const float	fact = 10;

	rt->max_quality = (t_quality){
		.ray_depth = 5,
		.quality = 1,
		.region = (t_vec2){rt->dimensions.x / fact, rt->dimensions.y / fact},
		.aa.size = 4,
	};
	rt->max_quality.aa.scale = 1 / (double)(
			rt->max_quality.aa.size * rt->max_quality.aa.size);
	rt->min_quality = (t_quality){
		.ray_depth = 2,
		.quality = 0.1,
		.region = rt->dimensions,
		.aa = (t_aa){1, 1}
	};
	rt->cur_quality = &rt->max_quality;
	return ;
}

t_minirt	*rt_init(t_minirt *rt)
{
	const int				width = 1280;
	mlx_window_create_info	info;

	rt->should_render = true;
	rt->intensity = 1;
	rt->aspect_ratio = 16.0 / 9.0;
	rt->sensibility = 0.1;
	rt->sensibility_rot = 0.005;
	rt->dimensions = (t_vec2){width, width / rt->aspect_ratio};
	set_quality(rt);
	rt->context = mlx_init();
	ft_bzero(&info, sizeof(info));
	info.title = "miniRT";
	info.width = rt->dimensions.x;
	info.height = rt->dimensions.y;
	info.is_resizable = true;
	rt->window = mlx_new_window(rt->context, &info);
	rt->render = mlx_new_image(rt->context, rt->dimensions.x, rt->dimensions.y);
	mouse_init(rt);
	camera_init(&rt->camera, rt->cur_quality->aa, rt->dimensions);
	rt_init_events(rt);
	return (rt);
}
