/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:36:59 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/24 00:03:48 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	print_transformation_instructions(void)
{
	printf(YELLOW "📜 Transformation instructions:\n" RESET);
	printf(GREEN "🚀 Press 1 to enter object movement mode\n" RESET);
	printf(BLUE "🔄 Press 2 to enter object rotation mode\n" RESET);
	printf(MAGENTA "📷 Press 3 to enter camera movement mode\n" RESET);
	printf(CYAN "🔄 Press 4 to enter camera rotation mode\n" RESET);
	printf(CYAN "🔵 Select object: Tab\n" RESET);
	printf(GREEN "Use W, A, S,D ");
	printf("to move objects and camera horizontally \n" RESET);
	printf(GREEN "Use Up and Down arrow keys");
	printf(" to move objects and camera vertically \n" RESET);
}

void	print_selected_object(t_object *object)
{
	if (!object)
		return ;
	if (object->type == OBJ_SPHERE)
		printf(GREEN "🔵 Selected object: Sphere, id: %d\n" RESET, object->id);
	else if (object->type == OBJ_PLANE)
		printf(BLUE "🟦 Selected object: Plane, id: %d\n" RESET, object->id);
	else if (object->type == OBJ_CYLINDER)
		printf(YELLOW "🟡 Selected object: Cylinder, id: %d\n" RESET,
			object->id);
	else if (object->type == OBJ_CONE)
		printf(RED "🔺 Selected object: Cone, id: %d\n" RESET, object->id);
}

void	object_selection(int keycode, t_object *objects, t_object **selected)
{
	if (keycode == XK_Tab)
	{
		*selected = switch_objects(objects);
		print_selected_object(*selected);
	}
}
