/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:52:14 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/20 16:03:18 by mperrine         ###   ########.fr       */
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
	int				value;
	size_t			i;

	data = ft_split(*input, ",");
	if (ft_string_tab_len(data) != 3)
		use_status(FAILURE);
	color->a = 0xFF;
	i = 0;
	while (i < 3)
	{
		value = ft_atoi(data[i++]);
		if (use_status(ERR_GET) == SUCCESS && value >= 0 && value <= 255)
		{
			if (i == 1)
				color->r = value;
			else if (i == 2)
				color->g = value;
			else
				color->b = value;
		}
		else
			break ;
	}
	ft_free_tab(&data);
}
