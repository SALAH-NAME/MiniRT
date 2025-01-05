/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:51:29 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/05 19:40:54 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	print_scene(t_scene *scene)
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylinder;

	if (scene->ambient)
	{
		printf("Ambient Light:\n");
		printf("  Ratio: %f\n", scene->ambient->ratio);
		printf("  Color: %d, %d, %d\n", scene->ambient->color[0],
			scene->ambient->color[1], scene->ambient->color[2]);
	}
	else
		printf("Ambient Light: Not initialized\n");
	if (scene->light)
	{
		printf("Light:\n");
		printf("  Position: %f, %f, %f\n", scene->light->position[0],
			scene->light->position[1], scene->light->position[2]);
		printf("  Brightness: %f\n", scene->light->brightness);
		printf("  Color: %d, %d, %d\n", scene->light->color[0],
			scene->light->color[1], scene->light->color[2]);
	}
	else
		printf("Light: Not initialized\n");
	if (scene->camera)
	{
		printf("Camera:\n");
		printf("  Position: %f, %f, %f\n", scene->camera->position[0],
			scene->camera->position[1], scene->camera->position[2]);
		printf("  Orientation: %f, %f, %f\n", scene->camera->orientation[0],
			scene->camera->orientation[1], scene->camera->orientation[2]);
		printf("  Field of View: %d\n", scene->camera->fov);
	}
	else
		printf("Camera: Not initialized\n");
	sphere = scene->spheres;
	while (sphere)
	{
		printf("Sphere:\n");
		printf("  Center: (%f, %f, %f)\n", sphere->center[0], sphere->center[1],
			sphere->center[2]);
		printf("  Diameter: (%f)\n", sphere->diameter);
		printf("  Color: (%d, %d, %d)\n", sphere->color[0], sphere->color[1],
			sphere->color[2]);
		sphere = sphere->next;
	}
	plane = scene->planes;
	while (plane)
	{
		printf("Plane:\n");
		printf("  Point: (%f, %f, %f)\n", plane->point[0], plane->point[1],
			plane->point[2]);
		printf("  Normal: (%f, %f, %f)\n", plane->normal[0], plane->normal[1],
			plane->normal[2]);
		printf("  Color: (%d, %d, %d)\n", plane->color[0], plane->color[1],
			plane->color[2]);
		plane = plane->next;
	}
	cylinder = scene->cylinders;
	while (cylinder)
	{
		printf("Cylinder:\n");
		printf("  Base: (%f, %f, %f)\n", cylinder->base[0], cylinder->base[1],
			cylinder->base[2]);
		printf("  Axis: (%f, %f, %f)\n", cylinder->axis[0], cylinder->axis[1],
			cylinder->axis[2]);
		printf("  Diameter: %f\n", cylinder->diameter);
		printf("  Height: %f\n", cylinder->height);
		printf("  Color: (%d, %d, %d)\n", cylinder->color[0],
			cylinder->color[1], cylinder->color[2]);
		cylinder = cylinder->next;
	}
}
