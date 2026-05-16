/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:53:00 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/15 16:55:02 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <sys/time.h> // gettimeofday
# include <sys/stat.h> // open
# include <fcntl.h> // open
# include <unistd.h> // close, read, write
# include <stdio.h> // printf, perror
# include <stdlib.h> // malloc, free, exit
# include <string.h> // strerror

# include "../libs/lib_tools/includes/lib_tools.h" //Lib_tools
# include "../libs/MacroLibX/includes/mlx.h" //Macrolibx
# include "../libs/MacroLibX/includes/mlx_extended.h" //Macrolibx

# include "parser.h"

typedef struct s_minirt
{
	t_array		geos;
	t_array		lights;
	t_camera	camera;
	double	aspect_ratio;
	t_vec2	win;
}	t_minirt;

#endif
