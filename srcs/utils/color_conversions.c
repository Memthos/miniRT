/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 10:17:26 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 17:12:46 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

uint32_t	parse_color(t_uint channels[4], t_status *status)
{
	uint32_t	color;

	if (channels[0] > 255 || channels[1] > 255
		|| channels[2] > 255 || channels[3] > 255)
	{
		if (status)
			*status = OVERFLOW;
		return (0);
	}
	color = channels[0];
	color = (color << 8) | channels[1];
	color = (color << 8) | channels[2];
	color = (color << 8) | channels[3];
	return (color);
}
