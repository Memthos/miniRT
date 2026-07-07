/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 15:30:27 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/02 10:01:36 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUIT_H
# define QUIT_H

typedef struct s_minirt	t_minirt;

/**
 * @brief Destroys allocated ressources in rt.
 */
void	rt_quit(t_minirt *rt);

#endif
