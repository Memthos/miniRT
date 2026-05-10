/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:54:48 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/10 22:59:51 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef unsigned int	t_uint;

typedef enum e_status
{
	SUCCESS,
	FAILURE,
	OVERFLOW,
	UNDERFLOW,
}	t_status;

#endif
