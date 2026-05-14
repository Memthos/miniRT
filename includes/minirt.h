/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:53:00 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 16:27:03 by mperrine         ###   ########.fr       */
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

# include "../libs/libft_tools/includes/lib_tools.h" //Libft
# include "../libs/MacroLibX/includes/mlx.h" //Macrolibx
# include "../libs/MacroLibX/includes/mlx_extended.h" //Macrolibx

# include "camera.h"
# include "vectors.h"

typedef struct s_minirt
{
	double		aspect_ratio;
	t_vec2		win;
	t_camera	camera;
}	t_minirt;

#endif
