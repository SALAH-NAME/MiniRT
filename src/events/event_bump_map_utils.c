/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bump_map_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:23:50 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/24 15:23:50 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static t_bump_map	*get_bump_map(t_object *object)
{
	if (!object)
		return (NULL);
	if (object->type == OBJ_SPHERE || object->type == OBJ_PLANE
		|| object->type == OBJ_CYLINDER || object->type == OBJ_CONE)
		return (&object->material.bump);
	return (NULL);
}

static void	bump_map_transform(int keycode, t_render *world)
{
	static t_object	*selected = NULL;
	t_bump_map		*bump;

	object_selection(keycode, world->scene.objects, &selected);
	bump = get_bump_map(selected);
	if (!bump)
		return ;
	if (keycode == SDLK_UP)
		bump->scale += 1;
	if (keycode == SDLK_DOWN)
		bump->scale -= 1;
	if (keycode == SDLK_RIGHT)
		bump->intensity += 0.5;
	if (keycode == SDLK_LEFT)
		bump->intensity -= 0.5;
	if (bump->scale < 0)
		bump->scale = 0;
	if (bump->intensity < 0)
		bump->intensity = 0;
	render_scene_on_change(keycode, world);
}

void	scene_transformations(int keycode, t_render *world, int current_mode)
{
	if (current_mode == MODE_OBJECT_MOVE)
		object_movement(keycode, world->scene.objects, world);
	else if (current_mode == MODE_OBJECT_ROTATE)
		object_rotation(keycode, world->scene.objects, world);
	else if (current_mode == MODE_CAMERA_MOVE)
		camera_movement(keycode, &world->scene.camera, world);
	else if (current_mode == MODE_CAMERA_ROTATE)
		camera_rotation(keycode, &world->scene.camera, world);
	else if (current_mode == MODE_BUMP_MAP)
		bump_map_transform(keycode, world);
}
