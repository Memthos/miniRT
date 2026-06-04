/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 09:16:16 by mperrine          #+#    #+#             */
/*   Updated: 2026/06/04 09:17:02 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include "../libs/lib_tools/includes/math_ops.h"

typedef struct s_minirt		t_minirt;

t_vec2	project_to_screen(t_minirt *rt, t_vec3 pos);

#endif
