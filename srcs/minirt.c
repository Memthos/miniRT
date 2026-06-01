/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:17:41 by mperrine          #+#    #+#             */
/*   Updated: 2026/06/01 14:19:35 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_file(t_string s)
{
	size_t	len;
	int		fd;
	char	c;

	len = ft_strlen(s);
	if (len < 4 || ft_strcmp(&s[len - 3], ".rt") != 0)
		return (FAILURE);
	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		use_status(OPEN_FAILURE);
		return (FAILURE);
	}
	if (read(fd, &c, 1) == -1)
		use_status(READ_FAILURE);
	close(fd);
	if (use_status(ERR_GET) != SUCCESS)
		return (FAILURE);
	if (!c)
	{
		use_status(EMPTY_FILE);
		return (FAILURE);
	}
	return (use_status(SUCCESS));
}

void	rt_loop(void *param)
{
	t_minirt	*rt;

	rt = param;
	if (!camera_is_moving(&rt->camera))
	{
		if (1 != rt->scale)
		{
			rt->scale = 1;
			rt->camera.aa.size = 3;
			rt->camera.aa.scale = 1.0 / (double)(rt->camera.aa.size * rt->camera.aa.size);
			rt_render(rt);
		}
		return ;
	}
	rt->scale = 0.1;
	rt->camera.aa.size = 1;
	rt->camera.aa.scale = 1.0 / (double)(rt->camera.aa.size * rt->camera.aa.size);
	camera_update(&rt->camera, rt->dimensions);
	rt_render(rt);
	return ;
}

t_status	minirt(const t_string file)
{
	t_minirt	rt;

	rt = (t_minirt){0};
	rt_parser(file, &rt);
	if (SUCCESS != use_status(ERR_GET))
		return (use_status(ERR_GET));
	rt_init(&rt);
	rt_render(&rt);
	mlx_loop(rt.context);
	rt_quit(&rt);
	return (SUCCESS);
}

int	main(int argc, t_string_tab argv)
{
	if (argc != 2 || check_file(argv[1]))
	{
		write(2 ,"Error\n", 6);
		if (use_status(ERR_GET) != SUCCESS)
			print_status("miniRT");
		else
			write(2, "Use: ./miniRT <file.rt>\n", 24);
		return (1);
	}
	minirt(argv[1]);
	return (use_status(ERR_GET));
}
