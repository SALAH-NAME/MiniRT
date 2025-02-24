/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_print_scene.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:51:29 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/24 00:51:07 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	print_object(t_object *obj)
{
	if (obj->type == OBJ_SPHERE)
		printf("sp %.1f,%.1f,%.1f %.1f %d,%d,%d %.1f\n",
			obj->data.sphere.center.x, obj->data.sphere.center.y,
			obj->data.sphere.center.z, obj->data.sphere.radius,
			(int)(obj->material.color.r * 255),
			(int)(obj->material.color.g * 255),
			(int)(obj->material.color.b * 255),
			obj->material.specular_coefficient);
	else if (obj->type == OBJ_PLANE)
		printf("pl %.1f,%.1f,%.1f %.1f,%.1f,%.1f %d,%d,%d %d,%d,%d %.1f\n",
			obj->data.plane.center.x, obj->data.plane.center.y,
			obj->data.plane.center.z, obj->data.plane.normal.x,
			obj->data.plane.normal.y, obj->data.plane.normal.z,
			(int)(obj->material.color.r * 255),
			(int)(obj->material.color.g * 255),
			(int)(obj->material.color.b * 255), 0, 0, 0,
			obj->material.specular_coefficient);
	else if (obj->type == OBJ_CYLINDER)
		printf("cy %.1f,%.1f,%.1f %.1f,%.1f,%.1f %.1f %.2f %d,%d,%d %.1f\n",
			obj->data.cylinder.center.x, obj->data.cylinder.center.y,
			obj->data.cylinder.center.z, obj->data.cylinder.normal.x,
			obj->data.cylinder.normal.y, obj->data.cylinder.normal.z,
			obj->data.cylinder.radius, obj->data.cylinder.height,
			(int)(obj->material.color.r * 255),
			(int)(obj->material.color.g * 255),
			(int)(obj->material.color.b * 255),
			obj->material.specular_coefficient);
	else if (obj->type == OBJ_CONE)
		printf("cn %.1f,%.1f,%.1f %.1f,%.1f,%.1f %.1f %.2f %d,%d,%d %.1f\n",
			obj->data.cone.center.x, obj->data.cone.center.y,
			obj->data.cone.center.z, obj->data.cone.normal.x,
			obj->data.cone.normal.y, obj->data.cone.normal.z,
			obj->data.cone.angle, obj->data.cone.height,
			(int)(obj->material.color.r * 255),
			(int)(obj->material.color.g * 255),
			(int)(obj->material.color.b * 255),
			obj->material.specular_coefficient);
}

void	print_scene(t_scene *scene)
{
	t_light		*light;
	t_object	*objects;

	printf("\n\n");
	printf("A %.1f %d,%d,%d\n",
		scene->ambient.ratio,
		(int)(scene->ambient.color.r * 255),
		(int)(scene->ambient.color.g * 255),
		(int)(scene->ambient.color.b * 255));

	printf("C %.1f,%.1f,%.1f %.1f,%.1f,%.1f %d\n",
		scene->camera.position.x, scene->camera.position.y,
		scene->camera.position.z, scene->camera.orientation.x,
		scene->camera.orientation.y, scene->camera.orientation.z,
		scene->camera.fov);

	light = scene->lights;
	while (light)
	{
		printf("L %.1f,%.1f,%.1f %.1f %d,%d,%d\n",
			light->position.x, light->position.y, light->position.z,
			light->brightness,
			(int)(light->color.r * 255),
			(int)(light->color.g * 255),
			(int)(light->color.b * 255));
		light = light->next;
	}
	printf("\n");
	printf("\n");
	printf("\n");
	objects = scene->objects;
	while (objects)
	{
		print_object(objects);
		objects = objects->next;
	}
	printf("\n\n");
}
