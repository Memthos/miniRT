/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:17:41 by mperrine          #+#    #+#             */
/*   Updated: 2026/06/03 12:25:53 by juperrin         ###   ########.fr       */
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

void	move_object(t_minirt *rt)
{
	int					mouse_pos[2];
	int					mouse_delta[2];
	double				scale;

	ft_bzero(&mouse_pos, sizeof(int [2]));
	mlx_mouse_get_pos(rt->context, &mouse_pos[0], &mouse_pos[1]);
	mouse_delta[0] = mouse_pos[0] - rt->mv_params.last_mouse_pos[0];
	mouse_delta[1] = mouse_pos[1] - rt->mv_params.last_mouse_pos[1];
	scale = vec_magnitude(vec_sub(rt->mv_params.selected->u_obj.plane.position, rt->camera.pos)) / rt->camera.focal_length;
	rt->mv_params.selected->u_obj.plane.position = vec_add(rt->mv_params.selected->u_obj.plane.position,
		vec_add(vec_scale(rt->camera.right, mouse_delta[0] * scale),
				vec_scale(rt->camera.up, -mouse_delta[1] * scale)));
	rt->mv_params.last_mouse_pos[0] = mouse_pos[0];
	rt->mv_params.last_mouse_pos[1] = mouse_pos[1];
}

void	rt_loop(void *param)
{
	t_minirt		*rt;

	rt = param;
	rt->delta_t = get_delta_time();
	if (rt->mv_params.moving)
		move_object(rt);
	if (!camera_is_moving(&rt->camera) && !rt->mv_params.moving)
	{
		if (rt->cur_quality == &rt->min_quality || rt->should_render)
		{
			rt->cur_quality = &rt->max_quality;
			camera_update(&rt->camera, rt->cur_quality->aa, rt->delta_t, rt->dimensions);
			rt_render(rt, false);
		}
		return ;
	}
	rt->cur_quality = &rt->min_quality;
	camera_update(&rt->camera, rt->cur_quality->aa, rt->delta_t, rt->dimensions);
	rt_render(rt, true);
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
	mlx_loop(rt.context);
	rt_quit(&rt);
	return (SUCCESS);
}

int	main(int argc, t_string_tab argv)
{
	if (argc != 2 || check_file(argv[1]))
	{
		write(2, "Error\n", 6);
		if (use_status(ERR_GET) != SUCCESS)
			print_status("miniRT");
		else
			write(2, "Use: ./miniRT <file.rt>\n", 24);
		return (1);
	}
	minirt(argv[1]);
	return (use_status(ERR_GET));
}
