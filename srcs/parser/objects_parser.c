/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:51:05 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/20 15:47:18 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_parse_sphere(const t_string *line, t_minirt *rt)
{
	t_obj			obj;
	t_string_tab	data;
	t_string		endptr;

	endptr = NULL;
	ft_bzero(&obj, sizeof(t_obj));
	obj.type = SPHERE;
	data = ft_split(*line + 2, "\t\n\v\f\r ");
	if (ft_string_tab_len(data) != 3)
		use_status(FAILURE);
	if (use_status(ERR_GET) == SUCCESS)
		rt_parse_coords(&data[0], &obj.u_obj.sphere.position);
	if (use_status(ERR_GET) == SUCCESS)
		obj.u_obj.sphere.diameter = ft_strtod(data[1], &endptr);
	if (endptr)
		use_status(FAILURE);
	if (use_status(ERR_GET) == SUCCESS)
		rt_parse_color(&data[2], &obj.u_obj.sphere.color);
	if (use_status(ERR_GET) == FAILURE)
		write(2, "Error\nError in file sphere line\n", 32);
	else if (use_status(ERR_GET) == SUCCESS)
		rt_add_array_slot(&rt->geos, &obj);
	ft_free_tab(&data);
}

void	rt_parse_plane(const t_string *line, t_minirt *rt)
{
	t_obj			obj;
	t_string_tab	data;

	ft_bzero(&obj, sizeof(t_obj));
	obj.type = PLANE;
	data = ft_split(*line + 2, "\t\n\v\f\r ");
	if (ft_string_tab_len(data) != 3)
		use_status(FAILURE);
	if (use_status(ERR_GET) == SUCCESS)
		rt_parse_coords(&data[0], &obj.u_obj.plane.position);
	if (use_status(ERR_GET) == SUCCESS)
		rt_parse_orientation(&data[1], &obj.u_obj.plane.norm_rot);
	if (use_status(ERR_GET) == SUCCESS)
		rt_parse_color(&data[2], &obj.u_obj.sphere.color);
	if (use_status(ERR_GET) == FAILURE)
		write(2, "Error\nError in file plane line\n", 31);
	else if (use_status(ERR_GET) == SUCCESS)
		rt_add_array_slot(&rt->geos, &obj);
	ft_free_tab(&data);
}

void	rt_parse_cylinder(const t_string *line, t_minirt *rt)
{
	t_obj			obj;
	t_string_tab	data;
	t_string		endptr;

	endptr = NULL;
	ft_bzero(&obj, sizeof(t_obj));
	obj.type = CYLINDER;
	data = ft_split(*line + 2, "\t\n\v\f\r ");
	if (ft_string_tab_len(data) != 5)
		use_status(FAILURE);
	if (use_status(ERR_GET) == SUCCESS)
		rt_parse_coords(&data[0], &obj.u_obj.sphere.position);
	if (use_status(ERR_GET) == SUCCESS)
		rt_parse_orientation(&data[1], &obj.u_obj.plane.norm_rot);
	if (use_status(ERR_GET) == SUCCESS)
		obj.u_obj.cylinder.diameter = ft_strtod(data[2], &endptr);
	if (use_status(ERR_GET) == SUCCESS && endptr == NULL)
		obj.u_obj.cylinder.height = ft_strtod(data[3], &endptr);
	if (use_status(ERR_GET) == SUCCESS && endptr == NULL)
		rt_parse_color(&data[4], &obj.u_obj.sphere.color);
	if (use_status(ERR_GET) == FAILURE || endptr)
		write(2, "Error\nError in file sphere line\n", 32);
	else if (use_status(ERR_GET) == SUCCESS)
		rt_add_array_slot(&rt->geos, &obj);
	ft_free_tab(&data);
}

void	rt_parse_ambient_light(const t_string *line, t_minirt *rt)
{
	t_obj			obj;
	t_string_tab	data;
	t_string		endptr;

	endptr = NULL;
	ft_bzero(&obj, sizeof(t_obj));
	obj.type = AMBIENT_LIGHT;
	data = ft_split(*line + 1, "\t\n\v\f\r ");
	if (ft_string_tab_len(data) != 2)
		use_status(FAILURE);
	if (use_status(ERR_GET) == SUCCESS)
		obj.u_obj.ambient_light.brightness = ft_strtod(data[0], &endptr);
	if (use_status(ERR_GET) == SUCCESS && endptr)
		use_status(FAILURE);
	if (use_status(ERR_GET) == SUCCESS)
		rt_parse_color(&data[1], &obj.u_obj.ambient_light.color);
	if (use_status(ERR_GET) == FAILURE)
		write(2, "Error\nError in file ambient light line\n", 39);
	else if (use_status(ERR_GET) == SUCCESS)
		rt_add_array_slot(&rt->lights, &obj);
	ft_free_tab(&data);
}

void	rt_parse_point_light(const t_string *line, t_minirt *rt)
{
	t_obj			obj;
	t_string_tab	data;
	t_string		endptr;

	endptr = NULL;
	ft_bzero(&obj, sizeof(t_obj));
	obj.type = POINT_LIGHT;
	data = ft_split(*line + 1, "\t\n\v\f\r ");
	if (ft_string_tab_len(data) != 3)
		use_status(FAILURE);
	if (use_status(ERR_GET) == SUCCESS)
		rt_parse_coords(&data[0], &obj.u_obj.point_light.position);
	if (use_status(ERR_GET) == SUCCESS)
		obj.u_obj.point_light.brightness = ft_strtod(data[1], &endptr);
	if (use_status(ERR_GET) == SUCCESS && endptr)
		use_status(FAILURE);
	if (use_status(ERR_GET) == SUCCESS)
		rt_parse_color(&data[2], &obj.u_obj.point_light.color);
	if (use_status(ERR_GET) == FAILURE)
		write(2, "Error\nError in file ambient light line\n", 39);
	else if (use_status(ERR_GET) == SUCCESS)
		rt_add_array_slot(&rt->lights, &obj);
	ft_free_tab(&data);
}
