/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:11:05 by mperrine          #+#    #+#             */
/*   Updated: 2026/06/09 14:18:18 by mperrine         ###   ########.fr       */
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
	mouse_delta[0] = mouse_pos[0] - rt->mv_params.last_ms_pos[0];
	mouse_delta[1] = mouse_pos[1] - rt->mv_params.last_ms_pos[1];
	scale = vec_magnitude(vec_sub(rt->mv_params.selected->u_obj.plane.position,
				rt->camera.pos)) / rt->camera.focal_length;
	rt->mv_params.selected->u_obj.plane.position
		= vec_add(rt->mv_params.selected->u_obj.plane.position,
			vec_add(vec_scale(rt->camera.right, mouse_delta[0] * scale),
				vec_scale(rt->camera.up, -mouse_delta[1] * scale)));
	rt->mv_params.last_ms_pos[0] = mouse_pos[0];
	rt->mv_params.last_ms_pos[1] = mouse_pos[1];
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

static void	get_cyl_move_data(t_minirt *rt, t_vec2 *dia_data, t_vec2 *hgt_data,
	int mouse_pos[2])
{
	t_vec2	sc_axis;
	t_vec2	cur_rel_ms;
	t_vec2	pre_rel_ms;
	double	dist_axis;

	sc_axis.x = vec_dot(rt->mv_params.selected->u_obj.cylinder.norm_rot,
			rt->camera.right);
	sc_axis.y = vec_dot(rt->mv_params.selected->u_obj.cylinder.norm_rot,
			rt->camera.up);
	dist_axis = sqrt(sc_axis.x * sc_axis.x + sc_axis.y * sc_axis.y);
	if (dist_axis > 1e-6)
		sc_axis = (t_vec2){sc_axis.x / dist_axis, sc_axis.y / dist_axis};
	cur_rel_ms.x = mouse_pos[0] - rt->mv_params.screen_pos.x;
	cur_rel_ms.y = -(mouse_pos[1] - rt->mv_params.screen_pos.y);
	pre_rel_ms.x = rt->mv_params.last_ms_pos[0] - rt->mv_params.screen_pos.x;
	pre_rel_ms.y = -(rt->mv_params.last_ms_pos[1] - rt->mv_params.screen_pos.y);
	hgt_data->x = fabs(cur_rel_ms.x * sc_axis.x + cur_rel_ms.y * sc_axis.y);
	hgt_data->y = fabs(pre_rel_ms.x * sc_axis.x + pre_rel_ms.y * sc_axis.y);
	dia_data->x = sqrt(cur_rel_ms.x * cur_rel_ms.x + cur_rel_ms.y * cur_rel_ms.y
			- hgt_data->x * hgt_data->x);
	dia_data->y = sqrt(pre_rel_ms.x * pre_rel_ms.x + pre_rel_ms.y * pre_rel_ms.y
			- hgt_data->y * hgt_data->y);
}

static void	scale_cylinder(t_minirt *rt, int mouse_pos[2], double scale)
{
	t_vec2	dia_data;
	t_vec2	hgt_data;

	ft_bzero(&dia_data, sizeof(t_vec2));
	ft_bzero(&hgt_data, sizeof(t_vec2));
	get_cyl_move_data(rt, &dia_data, &hgt_data, mouse_pos);
	rt->mv_params.selected->u_obj.cylinder.height += (hgt_data.x - hgt_data.y)
		* scale * 2;
	rt->mv_params.selected->u_obj.cylinder.diameter += (dia_data.x - dia_data.y)
		* scale * 2;
}

void	scale_object(t_minirt *rt)
{
	int		mouse_pos[2];
	double	scale;
	t_vec2	dist_data;

	ft_bzero(&mouse_pos, sizeof(int [2]));
	mlx_mouse_get_pos(rt->context, &mouse_pos[0], &mouse_pos[1]);
	scale = vec_magnitude(vec_sub(rt->mv_params.selected->u_obj.plane.position,
				rt->camera.pos)) / rt->camera.focal_length;
	if (CYLINDER == rt->mv_params.selected->type)
		scale_cylinder(rt, mouse_pos, scale);
	else if (SPHERE == rt->mv_params.selected->type)
	{
		dist_data.x = sqrt(pow(mouse_pos[0] - rt->mv_params.screen_pos.x, 2)
				+ pow(mouse_pos[1] - rt->mv_params.screen_pos.y, 2));
		dist_data.y = sqrt(pow(rt->mv_params.last_ms_pos[0]
					- rt->mv_params.screen_pos.x, 2)
				+ pow(rt->mv_params.last_ms_pos[1]
					- rt->mv_params.screen_pos.y, 2));
		rt->mv_params.selected->u_obj.sphere.diameter += (dist_data.x
				- dist_data.y) * scale * 2;
	}
	else
		return ;
	rt->mv_params.last_ms_pos[0] = mouse_pos[0];
	rt->mv_params.last_ms_pos[1] = mouse_pos[1];
}
