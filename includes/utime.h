/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utime.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juperrin <juperrin@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 10:47:57 by juperrin          #+#    #+#             */
/*   Updated: 2026/06/03 12:16:50 by juperrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIME_H
# define UTIME_H

typedef unsigned long	t_utime;

t_utime	get_utime(void);

t_utime	get_delta_time(void);

#endif
