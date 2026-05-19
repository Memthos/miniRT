/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:51 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/19 15:21:51 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	key_hook(int key, void *param)
{
	t_minirt	rt;

	rt = *(t_minirt *)param;
	if (41 == key)
		mlx_loop_end(rt.context);
	return ;
}

static void	window_hook(int event, void *param)
{
	t_minirt	rt;

	rt = *(t_minirt *)param;
	if (0 == event)
		mlx_loop_end(rt.context);
	return ;
}

void	rt_init_events(t_minirt *rt)
{
	mlx_on_event(rt->context, rt->window, MLX_KEYDOWN, &key_hook, rt);
	mlx_on_event(rt->context, rt->window, MLX_WINDOW_EVENT, &window_hook, rt);
	return ;
}
