/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:54 by juperrin          #+#    #+#             */
/*   Updated: 2026/07/01 14:41:20 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_quit(t_minirt *rt)
{
	if (NULL == rt)
		return ;
	if (rt->render)
		mlx_destroy_image(rt->context, rt->render);
	if (rt->window)
		mlx_destroy_window(rt->context, rt->window);
	if (rt->context)
		mlx_destroy_context(rt->context);
	if (rt->geos.size > 0)
		free(rt->geos.objs);
	if (rt->lights.size > 0)
		free(rt->lights.objs);
	exit(0);
}
