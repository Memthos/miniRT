/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:54:48 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/12 11:20:52 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef unsigned int	t_uint;
typedef unsigned char	t_uint8;
typedef char *			t_string;
typedef char **			t_string_tab;

typedef enum e_status
{
	SUCCESS,
	FAILURE,
	ALLOCATION_FAILURE,
	OVERFLOW,
	UNDERFLOW,
	ZERO_DIVISION,
	COLOR_RANGE,
}	t_status;

typedef struct	s_minirt
{
	double	aspect_ratio;
	int		screen_wdt;
	int		screen_hgt;
}	t_minirt;

#endif
