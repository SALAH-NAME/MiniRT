/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:51:29 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/03 18:51:58 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	print_object(t_object *obj)
{
	printf("\nObject Type: ");
	if (obj->type == OBJ_SPHERE)
	{
		printf("Sphere\n");
		printf("  Center: %f, %f, %f\n", obj->data.sphere.center.x,
			obj->data.sphere.center.y, obj->data.sphere.center.z);
		printf("  Diameter: %f\n", obj->data.sphere.radius);
	}
	else if (obj->type == OBJ_PLANE)
	{
		printf("Plane\n");
		printf("  Center: %f, %f, %f\n", obj->data.plane.center.x,
			obj->data.plane.center.y, obj->data.plane.center.z);
		printf("  Normal: %f, %f, %f\n", obj->data.plane.normal.x,
			obj->data.plane.normal.y, obj->data.plane.normal.z);
	}
	else if (obj->type == OBJ_CYLINDER)
	{
		printf("Cylinder\n");
		printf("  Center: %f, %f, %f\n", obj->data.cylinder.center.x,
			obj->data.cylinder.center.y, obj->data.cylinder.center.z);
		printf("  Normal: %f, %f, %f\n", obj->data.cylinder.normal.x,
			obj->data.cylinder.normal.y, obj->data.cylinder.normal.z);
		printf("  Diameter: %f\n", obj->data.cylinder.radius);
		printf("  Height: %f\n", obj->data.cylinder.height);
	}
	printf("  Material Color: %f, %f, %f\n", obj->material.color.r,
		obj->material.color.g, obj->material.color.b);
	printf("\n");
}

void	print_scene(t_scene *scene)
{
	t_lights	*light;
	t_object	*objects;

	{
		printf("Ambient lights:\n");
		printf("  Ratio: %f\n", scene->ambient.ratio);
		printf("  Color: %f, %f, %f\n", scene->ambient.color.r,
			scene->ambient.color.g, scene->ambient.color.b);
	}
	light = scene->lights;
	while (light)
	{
		printf("Light:\n");
		printf("  Position: %f, %f, %f\n", light->position.x, light->position.y,
			light->position.z);
		printf("  Brightness: %f\n", light->brightness);
		printf("  Color: %f, %f, %f\n", light->color.r, light->color.g,
			light->color.b);
		light = light->next;
	}
	{
		printf("Camera:\n");
		printf("  Position: %f, %f, %f\n", scene->camera.position.x,
			scene->camera.position.y, scene->camera.position.z);
		printf("  Orientation: %f, %f, %f\n", scene->camera.orientation.x,
			scene->camera.orientation.y, scene->camera.orientation.z);
		printf("  Field of View: %d\n", scene->camera.fov);
	}
	objects = scene->objects;
	while (objects)
	{
		print_object(objects);
		objects = objects->next;
	}
}
