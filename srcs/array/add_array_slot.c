/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_array_slot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 13:45:02 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/17 13:52:32 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_status	add_array_slot(t_array array)
{
	t_obj	*tmp;
	size_t	i;

	if (array.size == 0)
	{
		array.objs = ft_calloc(1, sizeof(t_obj *));
		if (use_status(ERR_GET) != SUCCESS)
			return (FAILURE);
		array.size = 1;
		return (SUCCESS);
	}
	tmp = ft_calloc(ft_array_len(array.objs) + 1, sizeof(t_obj *));
	if (use_status(ERR_GET) != SUCCESS)
		return (FAILURE);
	array.size += 1;
	i = 0;
	while (i < ft_array_len(array.objs))
	{
		tmp[i] = array.objs[i];
		i++;
	}
	free(array.objs);
	array.objs = tmp;
	return (SUCCESS);
}
