/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:36:53 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/22 14:36:53 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	object_selection(int keycode, t_object *objects, t_object **selected)
{
	if (keycode == XK_Tab)
	{
		*selected = switch_objects(objects);
		print_selected_object(*selected);
	}
}

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

void	object_movement(int keycode, t_object *objects, t_render *world)
{
	static t_object	*selected = NULL;

	object_selection(keycode, objects, &selected);
	if (keycode == XK_w)
		move_direction(selected, DIR_FORWARD, SPEED);
	else if (keycode == XK_s)
		move_direction(selected, DIR_BACKWARD, SPEED);
	else if (keycode == XK_a)
		move_direction(selected, DIR_LEFT, SPEED);
	else if (keycode == XK_d)
		move_direction(selected, DIR_RIGHT, SPEED);
	else if (keycode == XK_Up)
		move_direction(selected, DIR_UP, SPEED);
	else if (keycode == XK_Down)
		move_direction(selected, DIR_DOWN, SPEED);
	render_scene_on_change(keycode, world);
}

t_vec3	*get_object_normals(t_object *object)
{
	if (!object)
		return (NULL);
	if (object->type == OBJ_SPHERE)
		;
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

void	object_rotation(int keycode, t_object *objects, t_render *world)
{
	static t_object	*selected = NULL;

	object_selection(keycode, objects, &selected);
	if (keycode == XK_w)
		rotate_object(selected, SPEED, 0, 0);
	else if (keycode == XK_s)
		rotate_object(selected, 0, -SPEED, 0);
	else if (keycode == XK_a)
		rotate_object(selected, 0, 0, SPEED);
	else if (keycode == XK_d)
		rotate_object(selected, 0, 0, -SPEED);
	else if (keycode == XK_Up)
		rotate_object(selected, SPEED, 0, 0);
	else if (keycode == XK_Down)
		rotate_object(selected, -SPEED, 0, 0);
	render_scene_on_change(keycode, world);
}
