/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:53:00 by mperrine          #+#    #+#             */
/*   Updated: 2026/06/02 11:17:38 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h> // printf, perror
# include <stdlib.h> // malloc, free, exit
# include <stdint.h>
# include <string.h> // strerror
# include <unistd.h> // close, read, write
# include <sys/stat.h> // open
# include <fcntl.h> // open

# include "../libs/lib_tools/includes/lib_tools.h" //Lib_tools
# include "../libs/MacroLibX/includes/mlx.h" //Macrolibx
# include "../libs/MacroLibX/includes/mlx_extended.h" //Macrolibx

# include "init.h"
# include "quit.h"
# include "parser.h"
# include "camera.h"
# include "interval.h"
# include "ray.h"
# include "objects.h"
# include "rendering.h"
# include "events.h"
# include "mouse.h"
# include "random.h"

typedef struct s_minirt
{
	bool			should_render;
	double			aspect_ratio;
	t_vec2			dimensions;
	t_mouse_state	mouse;
	t_quality		max_quality;
	t_quality		min_quality;
	t_quality		*cur_quality;
	mlx_context		context;
	mlx_window		window;
	mlx_image		render;
	t_array			geos;
	t_array			lights;
	t_camera		camera;
	t_obj			*selected;
}	t_minirt;

void	rt_loop(void *param);

#endif
