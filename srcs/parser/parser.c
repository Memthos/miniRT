/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:53:49 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/19 16:37:57 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	rt_parse_camera(const t_string *line, t_minirt *rt)
{
	t_string_tab	data;
	t_string		endptr;

	endptr = NULL;
	ft_bzero(&rt->camera, sizeof(t_camera));
	data = ft_split(*line + 1, "\t\n\v\f\r ");
	if (ft_string_tab_len(data) != 3)
		use_status(FAILURE);
	if (use_status(ERR_GET) == SUCCESS)
		rt_parse_coords(&data[0], &rt->camera.position);
	if (use_status(ERR_GET) == SUCCESS)
		rt_parse_orientation(&data[1], &rt->camera.norm_rot);
	if (use_status(ERR_GET) == SUCCESS)
		rt->camera.fov = ft_strtod(data[2], &endptr);
	if (use_status(ERR_GET) == SUCCESS && endptr)
		use_status(FAILURE);
	if (use_status(ERR_GET) == FAILURE)
		write(2, "Error\nError in file camera line", 31);
	ft_free_tab(&data);
}

static t_parse_func	get_parse_func(const t_string *line)
{
	size_t					i;
	const t_parse_func_id	data[] = {
		{"sp", &rt_parse_sphere},
		{"pl", &rt_parse_plane},
		{"cy", &rt_parse_cylinder},
		{"A", &rt_parse_ambient_light},
		{"L", &rt_parse_point_light},
		{"C", &rt_parse_camera}};

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

static t_status	contain_chars(const t_string *line)
{
	size_t	i;

	i = 0;
	while ((*line)[i])
	{
		if (ft_isspace((*line)[i]) == FAILURE)
			return (SUCCESS);
	}
	return (FAILURE);
}

void	rt_parse_line(const t_string *line, t_minirt *rt, t_unique_obj *objs)
{
	t_parse_func	func;

	if (use_status(ERR_GET) != SUCCESS || contain_chars(line) == FAILURE)
		return ;
	func = get_parse_func(line);
	if (NULL == func)
	{
		write(2, "Error\nminiRT: Wrong object in map\n", 34);
		use_status(FAILURE);
		return ;
	}
	if (func == &rt_parse_camera)
		++objs->camera;
	else if (func == &rt_parse_ambient_light)
		++objs->ambient_light;
	else if (func == &rt_parse_point_light)
		++objs->point_light;
	func(line, rt);
}

void	rt_parser(const t_string filename, t_minirt *rt)
{
	char			*line;
	int				file;
	t_unique_obj	objs;

	file = open(filename, O_RDONLY);
	if (file == -1)
		use_status(OPEN_FAILURE);
	if (file == -1)
		return ;
	ft_bzero(&objs, sizeof(t_unique_obj));
	line = get_next_line(file);
	while (line)
	{
		rt_parse_line(&line, rt, &objs);
		free(line);
		line = get_next_line(file);
	}
	close(file);
	if (use_status(ERR_GET) == SUCCESS
		&& (objs.camera == 0 || objs.ambient_light == 0 || objs.point_light == 0
		|| objs.camera > 1 || objs.ambient_light > 1 || objs.point_light > 1))
	{
		write(2, "Error\nWrong object in file", 25);
		use_status(FAILURE);
	}
}
