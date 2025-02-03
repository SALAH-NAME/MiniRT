/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:51:29 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/01 12:39:50 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	print_scene(t_scene *scene)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;
  t_lights  *lights;

	if (scene->ambient)
	{
		printf("Ambient lights:\n");
		printf("  Ratio: %f\n", scene->ambient->ratio);
		printf("  Color: %f, %f, %f\n", scene->ambient->color.r,
			scene->ambient->color.g, scene->ambient->color.b);
	}
	else
		printf("Ambient lights: Not initialized\n");

  lights  = scene->lights;
	while (lights)
	{
		printf("lights:\n");
		printf("  Position: %f, %f, %f\n", lights->position.x,
			lights->position.y, lights->position.z);
		printf("  Brightness: %f\n", lights->brightness);
		printf("  Color: %f, %f, %f\n", lights->color.r,
			lights->color.g, lights->color.b);
    lights = lights->next;
	}

	if (scene->camera)
	{
		printf("Camera:\n");
		printf("  Position: %f, %f, %f\n", scene->camera->position.x,
			scene->camera->position.y, scene->camera->position.z);
		printf("  Orientation: %f, %f, %f\n", scene->camera->orientation.x,
			scene->camera->orientation.y, scene->camera->orientation.z);
		printf("  Field of View: %d\n", scene->camera->fov);
	}
	else
		printf("Camera: Not initialized\n");

	sphere = scene->spheres;
	while (sphere)
	{
		printf("Sphere:\n");
		printf("  Center: (%f, %f, %f)\n", sphere->center.x, sphere->center.y,
			sphere->center.z);
		printf("  Diameter: %f\n", sphere->radios);
		printf("  Color: (%f, %f, %f)\n", sphere->material.color.r,
			sphere->material.color.g, sphere->material.color.b);
		sphere = sphere->next;
	}

	plane = scene->planes;
	while (plane)
	{
		printf("Plane:\n");
		printf("  Point: (%f, %f, %f)\n", plane->center.x, plane->center.y,
			plane->center.z);
		printf("  Normal: (%f, %f, %f)\n", plane->normal.x, plane->normal.y,
			plane->normal.z);
		printf("  Color: (%f, %f, %f)\n", plane->material.color.r,
			plane->material.color.g, plane->material.color.b);
		plane = plane->next;
	}

	cylinder = scene->cylinders;
	while (cylinder)
	{
		printf("Cylinder:\n");
		printf("  Base: (%f, %f, %f)\n", cylinder->center.x, cylinder->center.y,
			cylinder->center.z);
		printf("  Axis: (%f, %f, %f)\n", cylinder->normal.x, cylinder->normal.y,
			cylinder->normal.z);
		printf("  Diameter: %f\n", cylinder->radios);
		printf("  Height: %f\n", cylinder->height);
		printf("  Color: (%f, %f, %f)\n", cylinder->material.color.r,
			cylinder->material.color.g, cylinder->material.color.b);
		cylinder = cylinder->next;
	}
}
