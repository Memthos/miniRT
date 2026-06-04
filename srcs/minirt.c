/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:17:41 by mperrine          #+#    #+#             */
/*   Updated: 2026/06/04 17:08:54 by mperrine         ###   ########.fr       */
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
	t_vec2		delta;

	rt = (t_minirt *)param;
	rt->delta_t = get_delta_time();
	delta = mouse_get_delta(rt);
	if (rt->mouse.rotating)
	{
		rt->camera.dir = vec_rotate(rt->camera.dir, (t_vec3){0, 1, 0}, delta.x * deg_to_rad());
		rt->camera.dir = vec_rotate(rt->camera.dir, rt->camera.right, delta.y * deg_to_rad());
	}
	if (true == rt->mv_params.moving && NULL != rt->mv_params.selected)
	{
		if (MOVE == rt->mv_params.move_mode)
			move_object(rt);
		else if (ROTATE == rt->mv_params.move_mode)
			rotate_object(rt);
		else if (SCALE == rt->mv_params.move_mode)
			scale_object(rt);
	}
	if (false == camera_is_moving(&rt->camera) && false == rt->mv_params.moving && !rt->mouse.rotating)
	{
		if (rt->cur_quality == &rt->min_quality || rt->should_render)
		{
			rt->should_render = true;
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
