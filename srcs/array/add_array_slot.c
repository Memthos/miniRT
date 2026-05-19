/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_array_slot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 13:45:02 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/19 17:08:38 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_status	rt_add_array_slot(t_array *array, t_obj obj)
{
	t_obj	*tmp;
	size_t	i;

	if (!array)
		return (SUCCESS);
	if (array->size == 0)
	{
		array->objs = ft_calloc(1, sizeof(t_obj *));
		if (use_status(ERR_GET) != SUCCESS)
			return (FAILURE);
		array->size = 1;
		ft_memcpy(&array[0], &obj, sizeof(t_obj));
		return (SUCCESS);
	}
	tmp = ft_calloc(array->size + 1, sizeof(t_obj *));
	if (use_status(ERR_GET) != SUCCESS)
		return (FAILURE);
	array->size += 1;
	ft_memcpy(&tmp[array->size - 1], &obj, sizeof(t_obj));
	i = 0;
	while (i++ < array->size - 1)
		tmp[i - 1] = array->objs[i - 1];
	free(array->objs);
	array->objs = tmp;
	return (SUCCESS);
}
