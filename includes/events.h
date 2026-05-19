/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:21:42 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/19 15:21:42 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

typedef struct s_minirt	t_minirt;

/**
 * @brief Initialises hook events for the window, keyboard, and mouse.
 */
void	rt_init_events(t_minirt *rt);

#endif
