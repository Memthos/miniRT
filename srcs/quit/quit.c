/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:54 by juperrin          #+#    #+#             */
/*   Updated: 2026/07/01 14:32:53 by mperrine         ###   ########.fr       */
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
	exit(0);
}
