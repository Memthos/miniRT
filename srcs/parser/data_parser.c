/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:52:14 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/20 11:05:00 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_parse_coords(const t_string *input, t_vec3 *pos)
{
	t_string_tab	data;
	t_string		endptr;

	endptr = NULL;
	data = ft_split(*input, ",");
	if (ft_string_tab_len(data) != 3)
		use_status(FAILURE);
	if (use_status(ERR_GET) == SUCCESS)
		pos->x = ft_strtod(data[0], &endptr);
	if (use_status(ERR_GET) == SUCCESS && endptr == NULL)
		pos->y = ft_strtod(data[1], &endptr);
	if (use_status(ERR_GET) == SUCCESS && endptr == NULL)
		pos->z = ft_strtod(data[2], &endptr);
	ft_free_tab(&data);
}

void	rt_parse_orientation(const t_string *input, t_vec3 *norm_rot)
{
	t_string_tab	data;
	t_string		endptr;

	endptr = NULL;
	data = ft_split(*input, ",");
	if (ft_string_tab_len(data) != 3)
		use_status(FAILURE);
	if (use_status(ERR_GET) == SUCCESS)
		norm_rot->x = ft_strtod(data[0], &endptr);
	if (use_status(ERR_GET) == SUCCESS && endptr == NULL)
		norm_rot->y = ft_strtod(data[1], &endptr);
	if (use_status(ERR_GET) == SUCCESS && endptr == NULL)
		norm_rot->z = ft_strtod(data[2], &endptr);
	ft_free_tab(&data);
}

void	rt_parse_color(const t_string *input, mlx_color *color)
{
	t_string_tab	data;
	t_string		endptr;

	endptr = NULL;
	data = ft_split(*input, ",");
	if (ft_string_tab_len(data) != 3)
		use_status(FAILURE);
	if (use_status(ERR_GET) == SUCCESS)
		color->r = ft_strtod(data[0], &endptr);
	if (use_status(ERR_GET) == SUCCESS && endptr == NULL)
		color->g = ft_strtod(data[1], &endptr);
	if (use_status(ERR_GET) == SUCCESS && endptr == NULL)
		color->b = ft_strtod(data[2], &endptr);
	if (use_status(ERR_GET) == SUCCESS && endptr == NULL)
		color->a = 0xFF;
	ft_free_tab(&data);
}
