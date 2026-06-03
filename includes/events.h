/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:42 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/03 10:12:28 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <stddef.h>

typedef struct s_minirt	t_minirt;

enum e_keys
{
	LEFT_MOUSE = 1,
	RIGHT_MOUSE = 3,
	KEY_ESCAPE = 41,
	KEY_Q = 20,
	KEY_W = 26,
	KEY_E = 8,
	KEY_R = 21,
	KEY_A = 4,
	KEY_S = 22,
	KEY_D = 7,
	KEY_F = 9,
	KEY_SPACE = 44,
	KEY_CTRL = 224,
};

typedef struct	s_move_obj
{
	bool	should_update;
	int		move_mode;
	t_obj	*selected;
	int		last_mouse_pos[2];
	int		moving;
}	t_move_obj;

/**
 * @brief Initialises hook events for the window, keyboard, and mouse.
 */
void	rt_init_events(t_minirt *rt);

void	keyup_hook(int key, void *param);
void	keydown_hook(int key, void *param);

#endif
