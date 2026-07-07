/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:21:37 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/05 09:27:05 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "math_ops.h"

typedef struct s_mouse_state
{
	bool	rotating;
	t_vec2	oldpos;
}	t_mouse_state;

void	mouse_init(t_minirt *rt);

t_vec2	mouse_get_delta(t_minirt *rt);

void	mouse_update(t_minirt *rt);

#endif
