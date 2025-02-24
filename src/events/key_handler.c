/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:36:46 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/23 23:54:40 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	close_window(t_render *render)
{
	mlx_loop_end(render->mlx.ptr);
	return (0);
}

int	swap_render_mode(t_render *world)
{
	world->scene.is_raytracing = !world->scene.is_raytracing;
	render_scene(world);
	return (0);
}

int	handle_keypress(int keycode, t_render *world)
{
	static int	current_mode = MODE_NONE;
	static int	last_mode = MODE_NONE;

	if (keycode == XK_t)
		swap_render_mode(world);
	if (keycode == XK_Escape || keycode == XK_q)
		return (mlx_loop_end(world->mlx.ptr), 0);
	if (keycode == XK_1)
		current_mode = MODE_OBJECT_MOVE;
	else if (keycode == XK_2)
		current_mode = MODE_OBJECT_ROTATE;
	else if (keycode == XK_3)
		current_mode = MODE_CAMERA_MOVE;
	else if (keycode == XK_4)
		current_mode = MODE_CAMERA_ROTATE;
	else if (keycode == XK_5)
		current_mode = MODE_BUMP_MAP;
	print_mode(current_mode, &last_mode);
	scene_transformations(keycode, world, current_mode);
	return (0);
}
