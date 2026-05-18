/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:53:49 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/18 15:56:56 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_coords(t_string input, t_vec3 *pos);
void	parse_orientation(t_string input, t_vec3 *norm_rot);

void	parse_sphere(t_string *line, t_minirt *minirt);
void	parse_plane(t_string *line, t_minirt *minirt);
void	parse_cylinder(t_string *line, t_minirt *minirt);
void	parse_ambient_light(t_string *line, t_minirt *minirt);
void	parse_point_light(t_string *line, t_minirt *minirt);

void	parse_camera(t_string *line, t_minirt *minirt)
{
	t_string_tab	data;
	t_string		endptr;

	data = ft_split(line, "\t\n\v\f\r ");
	if (use_status(ERR_GET) != SUCCESS)
		return ;
	if (!data[1] || !data[2] || !data[3])
	{
		write(2, "Error\nminiRT: Wrong object in map\n", 34);
		use_status(FAILURE);
		return ;
	}
	parse_coords(data[1], &minirt->camera.position);
	parse_orientation(data[2], &minirt->camera.norm_rot);
	endptr = NULL;
	minirt->camera.fov = ft_strtod(data[3], &endptr);
}

static t_parse_func	get_parse_func(t_string *line)
{
	size_t					i;
	const t_parse_func_id	data[] = {
		{"sp", &parse_sphere},
		{"pl", &parse_plane},
		{"cy", &parse_cylinder},
		{"A", &parse_ambient_light},
		{"L", &parse_point_light},
		{"C", &parse_camera}};

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(data[i].type, *line, ft_strlen(data[i].type)) == 0
			&& ft_isspace((*line)[ft_strlen(data[i].type) + 1]) == SUCCESS)
			return (data[i].func);
		i++;
	}
	return (NULL);
}

void	parse_line(t_string *line, t_minirt *minirt)
{
	t_parse_func	func;

	if (use_status(ERR_GET) != SUCCESS)
		return ;
	func = get_parse_func(line);
	if (NULL == func)
	{
		write(2, "Error\nminiRT: Wrong object in map\n", 34);
		use_status(FAILURE);
		return ;
	}
	func(line, minirt);
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
	{
		parse_line(&line, minirt);
		line = get_next_line(file);
	}
	close(file);
}
