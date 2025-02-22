/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:51:24 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/22 06:54:55 ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	close_window(t_render *render)
{
	mlx_loop_end(render->mlx.ptr);
	return (0);
}

int	handle_keypress(int keycode, t_render *world)
{
	static int current_mode = MODE_NONE;
  static int last_mode = MODE_NONE;

	if (keycode == XK_Escape || keycode == XK_q)
	{
		mlx_loop_end(world->mlx.ptr);
		return (0);
	}
	if (keycode == XK_1)
		current_mode = MODE_OBJECT_MOVE;
	else if (keycode == XK_2) 
		current_mode = MODE_OBJECT_ROTATE;
	else if (keycode == XK_3) 
		current_mode = MODE_CAMERA_MOVE;
	else if (keycode == XK_4) 
		current_mode = MODE_CAMERA_ROTATE;

	print_mode(current_mode, &last_mode);

	if (current_mode == MODE_OBJECT_MOVE)
		object_movement(keycode, world->scene.objects, world);
	else if (current_mode == MODE_OBJECT_ROTATE)
		object_rotation(keycode, world->scene.objects, world);
	else if (current_mode == MODE_CAMERA_MOVE)
		camera_movement(keycode, &world->scene.camera, world);
	else if (current_mode == MODE_CAMERA_ROTATE)
		camera_rotation(keycode, &world->scene.camera, world);
	return (0);
}

