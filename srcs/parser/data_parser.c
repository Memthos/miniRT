/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 13:52:14 by mperrine          #+#    #+#             */
/*   Updated: 2026/06/06 15:25:11 by juperrin         ###   ########.fr       */
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

void	rt_parse_orientation(const t_string *input, t_vec3 *dir)
{
	t_string_tab	data;
	t_string		endptr;
	double			*values[3];
	size_t			i;

	endptr = NULL;
	data = ft_split(*input, ",");
	if (ft_string_tab_len(data) != 3)
		use_status(FAILURE);
	i = 0;
	values[0] = &dir->x;
	values[1] = &dir->y;
	values[2] = &dir->z;
	while (i++ < 3 && use_status(ERR_GET) == SUCCESS)
	{
		(*values)[i - 1] = ft_strtod(data[i - 1], &endptr);
		if (!use_status(ERR_GET) && ((*values)[i - 1] < -1.0
			|| (*values)[i - 1] > 1.0 || endptr))
			use_status(FAILURE);
	}
	if (dir->x == 0.0 && dir->y == 0.0 && dir->z == 0.0 && !use_status(ERR_GET))
		use_status(FAILURE);
	if (use_status(ERR_GET) == SUCCESS)
		*dir = vec_normalize(*dir);
	ft_free_tab(&data);
}

void	rt_parse_color(const t_string *input, t_rgb *color)
{
	t_string_tab	data;
	int				value;
	size_t			i;

	data = ft_split(*input, ",");
	if (ft_string_tab_len(data) != 3)
		use_status(FAILURE);
	i = 0;
	while (i < 3 && use_status(ERR_GET) == SUCCESS)
	{
		value = ft_atoi(data[i++]);
		if (use_status(ERR_GET) != SUCCESS)
			break ;
		else if (value < 0 || value > 255)
			use_status(FAILURE);
		else if (i == 1)
			color->x = value / 255.0;
		else if (i == 2)
			color->y = value / 255.0;
		else
			color->z = value / 255.0;
	}
	ft_free_tab(&data);
}
