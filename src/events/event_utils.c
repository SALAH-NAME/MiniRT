/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:36:59 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/24 00:53:43 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "parser.h"

void	print_mode_message(int mode)
{
	char	*colors[5];
	char	*messages[5];
	int		index;

	colors[0] = GREEN;
	colors[1] = BLUE;
	colors[2] = MAGENTA;
	colors[3] = CYAN;
	colors[4] = CYAN;
	messages[0] = "Entering Mode: OBJECT MOVEMENT";
	messages[1] = "Entering Mode: OBJECT ROTATION";
	messages[2] = "Entering Mode: CAMERA MOVEMENT";
	messages[3] = "Entering Mode: CAMERA ROTATION";
	messages[4] = "Entering Mode: BUMP MAP TRANSFORMATIONS";
	if (mode >= MODE_OBJECT_MOVE && mode <= MODE_BUMP_MAP)
	{
		index = mode - MODE_OBJECT_MOVE;
		printf("%s\n-----------\n%s\n-----------\n" RESET, colors[index],
			messages[index]);
	}
}

void	print_mode(int mode, int *last_mode)
{
	if (mode != *last_mode)
	{
		print_mode_message(mode);
		*last_mode = mode;
	}
}

t_vec3	*get_object_position(t_object *object)
{
	if (!object)
		return (NULL);
	if (object->type == OBJ_SPHERE)
		return (&object->data.sphere.center);
	if (object->type == OBJ_PLANE)
		return (&object->data.plane.center);
	if (object->type == OBJ_CYLINDER)
		return (&object->data.cylinder.center);
	if (object->type == OBJ_CONE)
		return (&object->data.cone.center);
	return (NULL);
}

t_object	*switch_objects(t_object *objects)
{
	static t_object	*current = NULL;

	if (!objects)
		return (NULL);
	if (!current)
		current = objects;
	else if (current->next)
		current = current->next;
	else
		current = objects;
	return (current);
}

void	render_scene_on_change(int keycode, t_render *world)
{
	if (keycode == SDLK_s || keycode == SDLK_w || keycode == SDLK_a
		|| keycode == SDLK_d || keycode == SDLK_UP || keycode == SDLK_DOWN
		|| keycode == SDLK_LEFT || keycode == SDLK_RIGHT)
	{
		render_scene(world);
	}
}
