/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:54:48 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/12 10:02:45 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef unsigned int	t_uint;
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
}	t_status;

#endif
