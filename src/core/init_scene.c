/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:06:16 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/04 13:06:16 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "minirt.h"

t_light	*create_light(t_vec3 position, double intensity, t_color color)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->position = position;
	light->brightness = intensity;
	light->color = color;
	light->next = NULL;
	return (light);
}

t_object	*create_sphere(t_vec3 center, double radius, t_color color, int id)
{
	t_object	*sphere;

	sphere = malloc(sizeof(t_object));
	if (!sphere)
		return (NULL);
	sphere->type = OBJ_SPHERE;
	sphere->transform.position = center;
	sphere->transform.rotation = (t_vec3){0, 0, 0};
	sphere->material.color = color;
	sphere->material.checker_color = (t_color){0.0, 0.0, 0.0};
	sphere->material.checker_scale = 0;
	sphere->material.diffuse_coefficient = 0.7;
	sphere->material.specular_coefficient = 0.8;
	sphere->material.shininess = 32.0;
	sphere->data.sphere.center = center;
	sphere->data.sphere.radius = radius;
	sphere->next = NULL;
	sphere->id = id;
	return (sphere);
}

t_object	*create_plane(t_vec3 center, t_vec3 normal, t_color color, int id)
{
	t_object	*plane;

	plane = malloc(sizeof(t_object));
	if (!plane)
		return (NULL);
	plane->type = OBJ_PLANE;
	plane->transform.position = center;
	plane->transform.rotation = normal;
	plane->material.color = color;
	plane->material.checker_color = (t_color){0.0, 0.0, 0.0};
	plane->material.checker_scale = 0;
	plane->material.diffuse_coefficient = 0.8;
	plane->material.specular_coefficient = 0.2;
	plane->material.shininess = 16.0;
	plane->data.plane.center = center;
	plane->data.plane.normal = vec3_normalize(normal);
	plane->next = NULL;
	plane->id = id;
	return (plane);
}

void	set_materials(t_object *obj)
{
	if (obj->type == OBJ_SPHERE)
	{
		obj->material.diffuse_coefficient = 0.7;
		obj->material.specular_coefficient = 0.8;
		obj->material.shininess = 32.0;
	}
	else if (obj->type == OBJ_PLANE)
	{
		obj->material.diffuse_coefficient = 0.8;
		obj->material.specular_coefficient = 0.2;
		obj->material.shininess = 16.0;
	}
	else if (obj->type == OBJ_CYLINDER)
	{
		;
	}
}

void	init_scene(t_render *render)
{
	t_object	*obj;

	obj = render->scene.objects;
	while (obj)
	{
		set_materials(obj);
		obj = obj->next;
	}
}
