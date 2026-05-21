/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:17:41 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/20 13:24:50 by mperrine         ###   ########.fr       */
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

// static void	camera_init(t_minirt *minirt)
// {
// 	t_vec2		plane;
// 	t_camera	*camera;

// 	camera = &minirt->camera;
// 	*camera = (t_camera){
// 		.fov = 90.0,
// 		.clip_planes = {10.0, 100.0}};
// 	plane.y = camera->clip_planes.x * tan(camera->fov * 0.5 * deg_to_rad()) * 2;
// 	plane.x = plane.y * minirt->aspect_ratio;
// 	camera->plane = plane;
// }

static t_minirt	global_init(void)
{
	t_minirt	rt;

	ft_bzero(&rt, sizeof(t_minirt));
	// rt.aspect_ratio = 16.0 / 9.0;
	// rt.win.x = 1280.0;
	// rt.win.y = rt.win.x / rt.aspect_ratio;
	// camera_init(&rt);
	return (rt);
}

int	main(int argc, t_string_tab argv)
{
	t_minirt	rt;

	if (argc != 2 || check_file(argv[1]))
	{
		write(2 ,"Error\n", 6);
		if (use_status(ERR_GET) != SUCCESS)
			print_status("miniRT");
		else
			write(2, "Use: ./miniRT <file.rt>\n", 24);
		return (1);
	}
	rt = global_init();
	rt_parser(argv[1], &rt);
	return (use_status(ERR_GET));
}
