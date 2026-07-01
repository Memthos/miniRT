/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:54 by juperrin          #+#    #+#             */
/*   Updated: 2026/07/01 13:52:52 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_quit(t_minirt *rt)
{
	if (NULL == rt)
		return ;
	mlx_destroy_image(rt->context, rt->render);
	mlx_destroy_window(rt->context, rt->window);
	mlx_destroy_context(rt->context);
	exit(0);
}
