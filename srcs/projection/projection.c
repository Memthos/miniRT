/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 09:14:59 by mperrine          #+#    #+#             */
/*   Updated: 2026/07/01 08:34:06 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec2	project_to_screen(t_minirt *rt, t_vec3 pos)
{
	t_vec2	screen_pos;
	t_vec3	cam_space;
	t_vec3	pc;
	t_vec2	screen_half;

	pc = vec_sub(pos, rt->camera.pos);
	cam_space.x = vec_dot(pc, rt->camera.right);
	cam_space.y = vec_dot(pc, rt->camera.up);
	cam_space.z = vec_dot(pc, rt->camera.dir);
	screen_half.x = rt->dimension.x / 2;
	screen_half.y = rt->dimension.y / 2;
	screen_pos.x = screen_half.x + (cam_space.x / cam_space.z)
		* rt->camera.focal_length;
	screen_pos.y = screen_half.y - (cam_space.y / cam_space.z)
		* rt->camera.focal_length;
	return (screen_pos);
}
