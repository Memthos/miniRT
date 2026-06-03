/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:11:05 by mperrine          #+#    #+#             */
/*   Updated: 2026/06/03 16:18:51 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_object(t_minirt *rt)
{
	int					mouse_pos[2];
	int					mouse_delta[2];
	double				scale;

	if (rt->mv_params.selected->type != CYLINDER
		&& rt->mv_params.selected->type != PLANE
		&& rt->mv_params.selected->type != SPHERE)
		return ;

	ft_bzero(&mouse_pos, sizeof(int [2]));
	mlx_mouse_get_pos(rt->context, &mouse_pos[0], &mouse_pos[1]);
	mouse_delta[0] = mouse_pos[0] - rt->mv_params.last_mouse_pos[0];
	mouse_delta[1] = mouse_pos[1] - rt->mv_params.last_mouse_pos[1];
	scale = vec_magnitude(vec_sub(rt->mv_params.selected->u_obj.plane.position,
		rt->camera.pos)) / rt->camera.focal_length;
	rt->mv_params.selected->u_obj.plane.position =
		vec_add(rt->mv_params.selected->u_obj.plane.position,
		vec_add(vec_scale(rt->camera.right, mouse_delta[0] * scale),
				vec_scale(rt->camera.up, -mouse_delta[1] * scale)));
	rt->mv_params.last_mouse_pos[0] = mouse_pos[0];
	rt->mv_params.last_mouse_pos[1] = mouse_pos[1];
}

void	rotate_object(t_minirt *rt)
{
	int		mouse_pos[2];
	t_vec3	axis;
	double	angle;

	if (rt->mv_params.selected->type != CYLINDER
		&& rt->mv_params.selected->type != PLANE)
		return ;
	ft_bzero(&mouse_pos, sizeof(int [2]));
	mlx_mouse_get_pos(rt->context, &mouse_pos[0], &mouse_pos[1]);
	axis = vec_add(vec_scale(rt->camera.up, -(mouse_pos[0] - rt->mv_params.mouse_pressed_pos[0])),
			vec_scale(rt->camera.right, -(mouse_pos[1] - rt->mv_params.mouse_pressed_pos[1])));
	angle = vec_magnitude(axis) * rt->sensibility;
	if (angle > 0.0001)
		rt->mv_params.selected->u_obj.plane.norm_rot = vec_normalize(
			vec_rotate(rt->mv_params.start_norm_rot, vec_normalize(axis), angle));
}
