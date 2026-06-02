/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:42 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/02 10:18:45 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

typedef struct s_minirt	t_minirt;

enum e_keys
{
	KEY_ESCAPE = 41,
	KEY_A = 4,
	KEY_D = 7,
	KEY_W = 26,
	KEY_S = 22,
	KEY_SPACE = 44,
	KEY_CTRL = 224,
};

/**
 * @brief Initialises hook events for the window, keyboard, and mouse.
 */
void	rt_init_events(t_minirt *rt);

void	keyup_hook(int key, void *param);
void	keydown_hook(int key, void *param);

#endif
