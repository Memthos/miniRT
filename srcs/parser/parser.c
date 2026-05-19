/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:53:49 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/19 11:17:50 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_coords(const t_string input, t_vec3 *pos);
void	parse_orientation(const t_string input, t_vec3 *norm_rot);

void	parse_sphere(const t_string *line, t_minirt *minirt);
void	parse_plane(const t_string *line, t_minirt *minirt);
void	parse_cylinder(const t_string *line, t_minirt *minirt);
void	parse_ambient_light(const t_string *line, t_minirt *minirt);
void	parse_point_light(const t_string *line, t_minirt *minirt);

void	parse_camera(const t_string *line, t_minirt *minirt)
{
	t_string_tab	data;
	t_string		endptr;

	endptr = NULL;
	data = ft_split(line, "\t\n\v\f\r ");
	if (use_status(ERR_GET) != SUCCESS)
		return ;
	if (!data[0] || !data[1] || !data[2] || !data[3])
	{
		write(2, "Error\nminiRT: Wrong object in map\n", 34);
		use_status(FAILURE);
		return ;
	}
	parse_coords(data[1], &minirt->camera.position);
	parse_orientation(data[2], &minirt->camera.norm_rot);
	if (use_status(ERR_GET) == SUCCESS)
		minirt->camera.fov = ft_strtod(data[3], &endptr);
	if (endptr)
	{
		use_status(FAILURE);
		write(2, "Error\nError on camera line", 26);
		return ;
	}
	ft_free_tab(&data);
}

static t_parse_func	get_parse_func(const t_string *line)
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

void	parse_line(const t_string *line, t_minirt *minirt, int *parsed_cam)
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
	if (func == &parse_camera)
	{
		if (*parsed_cam == 1)
		{
			use_status(FAILURE);
			write(2, "Error\nMultiple cameras in file", 30);
			return ;
		}
		else
			*parsed_cam = 1;
	}
	func(line, minirt);
}

void	parser(const t_string filename, t_minirt *minirt)
{
	char	*line;
	int		file;
	int		parsed_cam;

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		use_status(OPEN_FAILURE);
		return ;
	}
	parsed_cam = 0;
	line = get_next_line(file);
	while (line)
	{
		parse_line(&line, minirt, &parsed_cam);
		line = get_next_line(file);
	}
	close(file);
	if (use_status(ERR_GET) == SUCCESS && parsed_cam == 0)
	{
		write(2, "Error\nNo camera in file", 23);
		use_status(FAILURE);
	}
}
