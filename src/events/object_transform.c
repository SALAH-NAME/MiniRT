/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:36:53 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/24 00:01:32 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	move_direction(t_object *object, int direction, double speed)
{
	t_vec3	*position;

	if (!object)
		return ;
	position = get_object_position(object);
	if (!position)
		return ;
	if (direction == DIR_UP)
		position->y += speed;
	if (direction == DIR_DOWN)
		position->y -= speed;
	if (direction == DIR_LEFT)
		position->x -= speed;
	if (direction == DIR_RIGHT)
		position->x += speed;
	if (direction == DIR_FORWARD)
		position->z -= speed;
	if (direction == DIR_BACKWARD)
		position->z += speed;
}

t_vec3	*get_object_normals(t_object *object)
{
	if (!object)
		return (NULL);
	if (object->type == OBJ_SPHERE)
		return (NULL);
	if (object->type == OBJ_PLANE)
		return (&object->data.plane.normal);
	if (object->type == OBJ_CYLINDER)
		return (&object->data.cylinder.normal);
	if (object->type == OBJ_CONE)
		return (&object->data.cone.normal);
	return (NULL);
}

void	rotate_object(t_object *object, double x, double y, double z)
{
	t_vec3	*normal;

	if (!object)
		return ;
	normal = get_object_normals(object);
	if (!normal)
		return ;
	*normal = vec3_add(*normal, vec3_create(x, y, z));
}

void	object_movement(int keycode, t_object *objects, t_render *world)
{
	static t_object	*selected = NULL;

	object_selection(keycode, objects, &selected);
	if (keycode == SDLK_w)
		move_direction(selected, DIR_FORWARD, MV_SPEED);
	else if (keycode == SDLK_s)
		move_direction(selected, DIR_BACKWARD, MV_SPEED);
	else if (keycode == SDLK_a)
		move_direction(selected, DIR_LEFT, MV_SPEED);
	else if (keycode == SDLK_d)
		move_direction(selected, DIR_RIGHT, MV_SPEED);
	else if (keycode == SDLK_UP)
		move_direction(selected, DIR_UP, MV_SPEED);
	else if (keycode == SDLK_DOWN)
		move_direction(selected, DIR_DOWN, MV_SPEED);
	render_scene_on_change(keycode, world);
}

void	object_rotation(int keycode, t_object *objects, t_render *world)
{
	static t_object	*selected = NULL;

	object_selection(keycode, objects, &selected);
	if (keycode == SDLK_w)
		rotate_object(selected, RT_SPEED, 0, 0);
	else if (keycode == SDLK_s)
		rotate_object(selected, 0, -RT_SPEED, 0);
	else if (keycode == SDLK_a)
		rotate_object(selected, 0, 0, RT_SPEED);
	else if (keycode == SDLK_d)
		rotate_object(selected, 0, 0, -RT_SPEED);
	else if (keycode == SDLK_UP)
		rotate_object(selected, RT_SPEED, 0, 0);
	else if (keycode == SDLK_DOWN)
		rotate_object(selected, -RT_SPEED, 0, 0);
	render_scene_on_change(keycode, world);
}
