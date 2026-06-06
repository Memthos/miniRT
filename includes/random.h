/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 10:51:41 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/06 11:34:00 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_H
# define RANDOM_H

double	random_double(void);

double	random_double2(double min, double max);

double	random_normed_double(void);

t_vec3	random_vec3(double min, double max);

t_vec3	random_unit_vec3(void);

t_vec3	random_surface_vec3(const t_vec3	normal);

#endif
