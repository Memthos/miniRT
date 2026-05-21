/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:24:38 by juperrin          #+#    #+#             */
/*   Updated: 2026/05/21 15:00:42 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

typedef struct s_minirt	t_minirt;

/**
 * @brief Initialises a minirt structure and return it.
 */
t_minirt	*rt_init(t_minirt *rt);

#endif