/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 08:24:52 by mperrine          #+#    #+#             */
/*   Updated: 2026/07/01 08:25:15 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_hit_obj(t_minirt *rt, t_point3 pixel_point, const t_interval i)
{
	t_interval		_i;
	t_hit_point		tmp;
	t_uint			index;
	t_ray			ray;

	_i = i;
	index = 0;
	rt->mv_params.selected = NULL;
	ray = (t_ray){rt->camera.pos, vec_sub(pixel_point, rt->camera.pos)};
	while (index < rt->geos.size || index < rt->lights.size)
	{
		if (index < rt->geos.size
			&& rt->geos.objs[index].hit(&ray, &rt->geos.objs[index], _i, &tmp))
		{
			_i.max = tmp.t;
			rt->mv_params.selected = &rt->geos.objs[index];
		}
		if (index < rt->lights.size && rt->lights.objs[index].hit(
				&ray, &rt->lights.objs[index], _i, &tmp))
		{
			_i.max = tmp.t;
			rt->mv_params.selected = &rt->lights.objs[index];
		}
		++index;
	}
}
