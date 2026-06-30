/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 10:51:41 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/30 17:44:04 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_H
# define RANDOM_H

double	random_double(double min, double max);

t_vec3	random_vec3(double min, double max);

t_vec3	random_unit_vec3(void);

t_vec3	random_surface_vec3(const t_vec3	normal);

#endif
