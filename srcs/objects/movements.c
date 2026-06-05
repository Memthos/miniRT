/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:11:05 by mperrine          #+#    #+#             */
/*   Updated: 2026/06/05 09:57:20 by mperrine         ###   ########.fr       */
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
	rt->mv_params.selected->u_obj.plane.position
		= vec_add(rt->mv_params.selected->u_obj.plane.position,
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
	axis = vec_add(vec_scale(rt->camera.up,
				-(mouse_pos[0] - rt->mv_params.mouse_pressed_pos[0])),
			vec_scale(rt->camera.right,
				-(mouse_pos[1] - rt->mv_params.mouse_pressed_pos[1])));
	angle = vec_magnitude(axis) * rt->sensibility_rot;
	if (angle > 0.0001)
		rt->mv_params.selected->u_obj.plane.norm_rot = vec_normalize(
				vec_rotate(rt->mv_params.start_norm_rot,
					vec_normalize(axis), angle));
}

static void	scale_cylinder(t_minirt *rt, int mouse_pos[2], double scale)
{
	t_vec2	sc_axis;
	t_vec2	curr_rel_ms;
	t_vec2	prev_rel_ms;
	t_vec2	dia_data;
	t_vec2	hgt_data;
	double	dist_axis;

	sc_axis.x = vec_dot(rt->mv_params.selected->u_obj.cylinder.norm_rot,
		rt->camera.right);
	sc_axis.y = vec_dot(rt->mv_params.selected->u_obj.cylinder.norm_rot,
		rt->camera.up);
	dist_axis = sqrt(sc_axis.x * sc_axis.x + sc_axis.y * sc_axis.y);
	if (dist_axis > 1e-6)
		sc_axis = (t_vec2){sc_axis.x / dist_axis, sc_axis.y / dist_axis};
	curr_rel_ms.x = mouse_pos[0] - rt->mv_params.screen_pos.x;
	curr_rel_ms.y = -(mouse_pos[1] - rt->mv_params.screen_pos.y);
	prev_rel_ms.x = rt->mv_params.last_mouse_pos[0]
		- rt->mv_params.screen_pos.x;
	prev_rel_ms.y = -(rt->mv_params.last_mouse_pos[1]
		- rt->mv_params.screen_pos.y);
	hgt_data.x = fabs(curr_rel_ms.x * sc_axis.x + curr_rel_ms.y * sc_axis.y);
	hgt_data.y = fabs(prev_rel_ms.x * sc_axis.x + prev_rel_ms.y * sc_axis.y);
	dia_data.x = sqrt(curr_rel_ms.x * curr_rel_ms.x + curr_rel_ms.y
		* curr_rel_ms.y - hgt_data.x  * hgt_data.x);
	dia_data.y = sqrt(prev_rel_ms.x * prev_rel_ms.x + prev_rel_ms.y
		* prev_rel_ms.y - hgt_data.y  * hgt_data.y);
	rt->mv_params.selected->u_obj.cylinder.height += (hgt_data.x - hgt_data.y)
		* scale * 2;
	rt->mv_params.selected->u_obj.cylinder.diameter += (dia_data.x - dia_data.y)
		* scale * 2;
}

static void	scale_sphere(t_minirt *rt, int mouse_pos[2], double scale)
{
	double	curr_dist;
	double	prev_dist;

	curr_dist = sqrt(pow(mouse_pos[0] - rt->mv_params.screen_pos.x, 2)
		+ pow(mouse_pos[1] - rt->mv_params.screen_pos.y, 2));
	prev_dist = sqrt(pow(rt->mv_params.last_mouse_pos[0]
		- rt->mv_params.screen_pos.x, 2)
		+ pow(rt->mv_params.last_mouse_pos[1]
		- rt->mv_params.screen_pos.y, 2));
	rt->mv_params.selected->u_obj.sphere.diameter += (curr_dist - prev_dist)
		* scale * 2;
}

void	scale_object(t_minirt *rt)
{
	int		mouse_pos[2];
	double	scale;

	if (rt->mv_params.selected->type != CYLINDER
		&& rt->mv_params.selected->type != SPHERE)
		return ;
	ft_bzero(&mouse_pos, sizeof(int [2]));
	mlx_mouse_get_pos(rt->context, &mouse_pos[0], &mouse_pos[1]);
	scale = vec_magnitude(vec_sub(rt->mv_params.selected->u_obj.plane.position,
				rt->camera.pos)) / rt->camera.focal_length;
	if (CYLINDER == rt->mv_params.selected->type)
		scale_cylinder(rt, mouse_pos, scale);
	else
		scale_sphere(rt, mouse_pos, scale);
	rt->mv_params.last_mouse_pos[0] = mouse_pos[0];
	rt->mv_params.last_mouse_pos[1] = mouse_pos[1];
}
