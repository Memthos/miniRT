/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:53:49 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/16 17:37:24 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_obj_type	get_object(t_string line)
{
	const t_string	data[] = {"sp", "pl", "cy", "A", "L", "C"};
	size_t			i;

	i = 0;
	while (data[i])
	{
		if (ft_strncmp(data[i], line, ft_strlen(data[i])) == SUCCESS
			&& ft_isspace(line[ft_strlen(data[i]) + 1]) == SUCCESS)
			return (i);
		i++;
	}
	return (-1);
}

void	parse_geo(t_string arg, t_obj_type type, t_minirt *minirt)
{
	t_string_tab	coords;
	size_t			i;

	if (use_status(ERR_GET) != SUCCESS)
		return ;
	coords = ft_split(arg, ",");
	if (use_status(ERR_GET) != SUCCESS)
		return ;
	i = 0;
	while (coords[i])
}

void	parse_line(t_string line, t_minirt *minirt)
{
	size_t			i;
	t_string_tab	args;
	t_obj_type		type;

	type = get_object(line);
	if ((int)type == -1)
	{
		write(2, "miniRT: Wrong object in map\n", 28);
		use_status(FAILURE);
		return ;
	}
	args = ft_split(line, "\t\n\v\f\r ");
	if (use_status(ERR_GET) != SUCCESS)
		return ;
	i = 1;
	while (args[i++])
	{
		if (type == SPHERE || type == PLANE || type == CYLINDER)
			parse_geo(args[i - 1], type, minirt);
		else if (type == AMBIENT_LIGHT || type == POINT_LIGHT)
			parse_light(args[i - 1], type, minirt);
		else
		 	parse_camera(args[i - 1], type, minirt);
	}
	ft_free_tab(&args);
}

void	parser(const t_string filename, t_minirt *minirt)
{
	char	*line;
	int		file;

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		use_status(OPEN_FAILURE);
		return ;
	}
	line = get_next_line(file);
	while (line)
		parse_line(line, minirt);
}
