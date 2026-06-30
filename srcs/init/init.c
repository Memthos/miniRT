/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:24:04 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/30 17:19:38 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_minirt	*rt_init(t_minirt *rt)
{
	const int				width = 1280;
	mlx_window_create_info	info;

	rt->should_render = true;
	rt->intensity = 1;
	rt->size_changed = true;
	rt->aspect_ratio = 16.0 / 9.0;
	rt->sensibility = 0.1;
	rt->sensibility_rot = 0.005;
	rt->dimensions = (t_vec2){width, width / rt->aspect_ratio};
	render_set_quality(rt);
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
