/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:53:00 by mperrine          #+#    #+#             */
/*   Updated: 2026/06/30 13:43:45 by mperrine         ###   ########.fr       */
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
# include <sys/time.h> //gettimeofday
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
# include "material.h"
# include "projection.h"
# include "objects.h"
# include "rendering.h"
# include "events.h"
# include "mouse.h"
# include "random.h"
# include "utime.h"

typedef struct s_minirt
{
	bool			should_render;
	bool			size_changed;
	double			aspect_ratio;
	t_utime			delta_t;
	double			sensibility_rot;
	double			sensibility;
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
	t_ambient_light	ambient_light;
	t_camera		camera;
	t_move_obj		mv_params;
}	t_minirt;

void	rt_loop(void *param);

#endif
