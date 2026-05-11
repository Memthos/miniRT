/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:17:41 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/11 14:52:04 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_filename(t_string s)
{
	size_t	len;
	
	len = ft_strlen(s);
	if (len < 4)
		return (1);
	if (s[len - 1] != 't' || s[len - 2] != 'r' || s[len - 3] != '.')
		return (1);
	return (0);
}

int	main(int argc, t_string_tab argv)
{
	if (argc != 2 || check_filename(argv[1]))
	{
		write(2, "Use: ./miniRT <file.rt>\n", 24);
		return (1);
	}
	return (0);
}
