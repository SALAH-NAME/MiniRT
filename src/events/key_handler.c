/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:51:24 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/15 03:06:44 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "parser.h"
#include <stdio.h>

int	handle_keypress(int keycode, t_render *world)
{
	static t_object	*selction = NULL;

	if (keycode == XK_Escape || keycode == XK_q)
	{
		mlx_loop_end(world->mlx.ptr);
		return (0);
	}
	// WASD controls for X-Z plane movement
	if (keycode == XK_Tab)
	{
		if (selction == NULL)
			selction = world->scene.objects;
		else
			selction = selction->next;
		printf("Selected object: %d\n", selction->id);
	}
	if (keycode == XK_w || keycode == XK_W)
		move_selected_forward(selction, MOVE_SPEED);
	else if (keycode == XK_s || keycode == XK_S)
		move_selected_forward(world->scene.objects, -MOVE_SPEED);
	else if (keycode == XK_a || keycode == XK_A)
		move_selected_right(world->scene.objects, -MOVE_SPEED);
	else if (keycode == XK_d || keycode == XK_D)
		move_selected_right(world->scene.objects, MOVE_SPEED);
	else if (keycode == XK_space)
		move_selected_up(world->scene.objects, MOVE_SPEED);
	else if (keycode == XK_c)
		move_selected_up(world->scene.objects, -MOVE_SPEED);
	render_scene(world);
	return (0);
}

int	handle_close(t_render *world)
{
	mlx_loop_end(world->mlx.ptr);
	return (0);
}
