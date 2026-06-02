/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:21:37 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/02 11:16:44 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "../libs/lib_tools/includes/math_ops.h"

typedef struct s_mouse_state
{
	bool	rotating;
	t_vec2	oldpos;
}	t_mouse_state;

t_vec2	mouse_get_delta(t_minirt *rt);

#endif
