/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 10:17:36 by mperrine          #+#    #+#             */
/*   Updated: 2026/06/03 11:05:26 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	keydown_move(int key, t_minirt *rt)
{
	if (KEY_A == key && !rt->camera.move.moving[MOVING_LEFT])
	{
		rt->camera.move.moving[MOVING_LEFT] = true;
		rt->camera.move.velocity.x -= 1.0;
	}
	else if (KEY_D == key && !rt->camera.move.moving[MOVING_RIGHT])
	{
		rt->camera.move.moving[MOVING_RIGHT] = true;
		rt->camera.move.velocity.x += 1.0;
	}
	else if (KEY_W == key && !rt->camera.move.moving[MOVING_FORWARD])
	{
		rt->camera.move.moving[MOVING_FORWARD] = true;
		rt->camera.move.velocity.z += 1.0;
	}
	else if (KEY_S == key && !rt->camera.move.moving[MOVING_BACKWARD])
	{
		rt->camera.move.moving[MOVING_BACKWARD] = true;
		rt->camera.move.velocity.z -= 1.0;
	}
}

void	keydown_hook(int key, void *param)
{
	t_minirt	*rt;

	rt = (t_minirt *)param;
	if (KEY_ESCAPE == key)
		mlx_loop_end(rt->context);
	else if (KEY_SPACE == key && !rt->camera.move.moving[MOVING_UP])
	{
		rt->camera.move.moving[MOVING_UP] = true;
		rt->camera.move.velocity.y += 1.0;
	}
	else if (KEY_CTRL == key && !rt->camera.move.moving[MOVING_DOWN])
	{
		rt->camera.move.moving[MOVING_DOWN] = true;
		rt->camera.move.velocity.y -= 1.0;
	}
	else
		keydown_move(key, rt);
}

static void	keyup_move(int key, t_minirt *rt)
{
	if (KEY_A == key && rt->camera.move.moving[MOVING_LEFT])
	{
		rt->camera.move.moving[MOVING_LEFT] = false;
		rt->camera.move.velocity.x += 1.0;
	}
	else if (KEY_D == key && rt->camera.move.moving[MOVING_RIGHT])
	{
		rt->camera.move.moving[MOVING_RIGHT] = false;
		rt->camera.move.velocity.x -= 1.0;
	}
	else if (KEY_W == key && rt->camera.move.moving[MOVING_FORWARD])
	{
		rt->camera.move.moving[MOVING_FORWARD] = false;
		rt->camera.move.velocity.z -= 1.0;
	}
	else if (KEY_S == key && rt->camera.move.moving[MOVING_BACKWARD])
	{
		rt->camera.move.moving[MOVING_BACKWARD] = false;
		rt->camera.move.velocity.z += 1.0;
	}
}

void	keyup_hook(int key, void *param)
{
	t_minirt	*rt;

	rt = (t_minirt *)param;
	if (KEY_SPACE == key && rt->camera.move.moving[MOVING_UP])
	{
		rt->camera.move.moving[MOVING_UP] = false;
		rt->camera.move.velocity.y -= 1.0;
	}
	else if (KEY_CTRL == key && rt->camera.move.moving[MOVING_DOWN])
	{
		rt->camera.move.moving[MOVING_DOWN] = false;
		rt->camera.move.velocity.y += 1.0;
	}
	else if (KEY_Q == key)
		rt->mv_params.move_mode = MOVE;
	else if (KEY_E == key)
		rt->mv_params.move_mode = ROTATE;
	else if (KEY_R == key)
		rt->mv_params.move_mode = SCALE;
	else if (KEY_F == key)
		rt->mv_params.move_mode = NONE;
	else
		keyup_move(key, rt);
}
