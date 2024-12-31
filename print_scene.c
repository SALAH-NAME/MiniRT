/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:51:29 by ysemlali          #+#    #+#             */
/*   Updated: 2024/12/31 12:51:29 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
void print_scene(t_Scene *scene)
{
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

    for (int i = 0; i < scene->plane_count; i++)
    {
        printf("Plane:\n");
        printf("  Point: (%.2f, %.2f, %.2f)\n", scene->planes[i]->point[0],
            scene->planes[i]->point[1], scene->planes[i]->point[2]);
        printf("  Normal: (%.2f, %.2f, %.2f)\n", scene->planes[i]->normal[0],
            scene->planes[i]->normal[1], scene->planes[i]->normal[2]);
        printf("  Color: (%d, %d, %d)\n", scene->planes[i]->color[0],
            scene->planes[i]->color[1], scene->planes[i]->color[2]);
    }

    for (int i = 0; i < scene->sphere_count; i++)
    {
        printf("Sphere:\n");
        printf("  Center: (%.2f, %.2f, %.2f)\n", scene->spheres[i]->center[0],
            scene->spheres[i]->center[1], scene->spheres[i]->center[2]);
        printf("  Diameter: (%.2f)\n", scene->spheres[i]->diameter);
        printf("  Color: (%d, %d, %d)\n", scene->spheres[i]->color[0],
            scene->spheres[i]->color[1], scene->spheres[i]->color[2]);
    }

    for (int i = 0; i < scene->cylinder_count; i++)
    {
        printf("Cylinder:\n");
        printf("  Base: (%.2f, %.2f, %.2f)\n", scene->cylinders[i]->base[0],
            scene->cylinders[i]->base[1], scene->cylinders[i]->base[2]);
        printf("  Axis: (%.2f, %.2f, %.2f)\n", scene->cylinders[i]->axis[0],
            scene->cylinders[i]->axis[1], scene->cylinders[i]->axis[2]);
        printf("  Diameter: %.2f\n", scene->cylinders[i]->diameter);
        printf("  Height: %.2f\n", scene->cylinders[i]->height);
        printf("  Color: (%d, %d, %d)\n", scene->cylinders[i]->color[0],
            scene->cylinders[i]->color[1], scene->cylinders[i]->color[2]);
    }
}


