/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:05:03 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/01 16:56:58 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

typedef struct s_minirt	t_minirt;

typedef struct s_render_quality
{
	double	quality;
	t_vec2	region;
	t_aa	aa;
}	t_quality;

void	rt_render(t_minirt *rt, bool restart);

#endif
