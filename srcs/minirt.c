/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:17:41 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/13 15:02:09 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_filename(t_string s)
{
	size_t	len;

	len = ft_strlen(s);
	if (len < 4)
		return (1);
	if (s[len - 1] != 't' || s[len - 2] != 'r' || s[len - 3] != '.')
		return (1);
	return (0);
}

static void	camera_init(t_minirt *minirt)
{
	t_vec2		plane;
	t_camera	*camera;

	camera = &minirt->camera;
	*camera = (t_camera){
		.fov = 90.0,
		.clip_planes = {10.0, 100.0}};
	plane.y = camera->clip_planes.x * tan(camera->fov * 0.5 * deg_to_rad()) * 2;
	plane.x = plane.y * minirt->aspect_ratio;
	camera->plane = plane;
}

static t_minirt	global_init(void)
{
	t_minirt	minirt;

	ft_bzero(&minirt, sizeof(t_minirt));
	minirt.aspect_ratio = 16.0 / 9.0;
	minirt.win.x = 1280.0;
	minirt.win.y = minirt.win.x / minirt.aspect_ratio;
	camera_init(&minirt);
	return (minirt);
}

int	main(int argc, t_string_tab argv)
{
	t_minirt	minirt;

	if (argc != 2 || check_filename(argv[1]))
	{
		write(2, "Use: ./miniRT <file.rt>\n", 24);
		return (1);
	}
	minirt = global_init();
	return (0);
}
