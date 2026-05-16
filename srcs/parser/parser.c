/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:10:19 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/15 16:57:23 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parser(const t_string filename, t_minirt *minirt)
{
	char	*line;
	int		file;

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		use_status(OPEN_FAILURE);
		return ;
	}
	line = get_next_line(file);
	while (line)
		parse_line(line, minirt);
}
