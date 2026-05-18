/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_array_slot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 13:45:02 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/18 13:11:05 by mperrine         ###   ########.fr       */
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
	tmp = ft_calloc(array.size + 1, sizeof(t_obj *));
	if (use_status(ERR_GET) != SUCCESS)
		return (FAILURE);
	i = 0;
	while (i < array.size)
	{
		tmp[i] = array.objs[i];
		i++;
	}
	free(array.objs);
	array.objs = tmp;
	array.size += 1;
	return (SUCCESS);
}
