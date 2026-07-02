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
	render->sdl.quit = 1;
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

	if (keycode == SDLK_t)
		swap_render_mode(world);
	if (keycode == SDLK_ESCAPE || keycode == SDLK_q)
		return (world->sdl.quit = 1, 0);
	if (keycode == SDLK_1)
		current_mode = MODE_OBJECT_MOVE;
	else if (keycode == SDLK_2)
		current_mode = MODE_OBJECT_ROTATE;
	else if (keycode == SDLK_3)
		current_mode = MODE_CAMERA_MOVE;
	else if (keycode == SDLK_4)
		current_mode = MODE_CAMERA_ROTATE;
	else if (keycode == SDLK_5)
		current_mode = MODE_BUMP_MAP;
	print_mode(current_mode, &last_mode);
	scene_transformations(keycode, world, current_mode);
	return (0);
}
