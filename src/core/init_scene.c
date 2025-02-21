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
	sphere->material.checker.color = (t_color){0.0, 0.0, 0.0};
	sphere->material.checker.scale = 0;
	sphere->material.diffuse_coefficient = 0.7;
	sphere->material.specular_coefficient = 0.8;
	sphere->material.shininess = 32.0;
	sphere->material.bump.intensity = 0.0;
	sphere->material.bump.scale = 0.0;
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
	plane->material.checker.color = (t_color){0.0, 0.0, 0.0};
	plane->material.checker.scale = 0;
	plane->material.diffuse_coefficient = 0.8;
	plane->material.specular_coefficient = 0.2;
	plane->material.shininess = 16.0;
	plane->data.plane.center = center;
	plane->data.plane.normal = vec3_normalize(normal);
	plane->next = NULL;
	plane->id = id;
	return (plane);
}

t_object	*create_cone(t_vec3 center, double angle, double height)
{
	t_object	*cone;

	cone = malloc(sizeof(t_object));
	if (!cone)
		return (NULL);
	cone->type = OBJ_CONE;
	cone->material.color = (t_color){0.9, 0.5, 0.1};
	cone->material.checker.color = (t_color){0.0, 0.0, 0.0};
	cone->material.checker.scale = 0.0;
	cone->material.diffuse_coefficient = 0.7;
	cone->material.specular_coefficient = 0.0;
	cone->material.shininess = 24.0;
	cone->data.cone.center = center;
	cone->data.cone.normal = (t_vec3){-0.3, -0.2, 0.0};
	cone->data.cone.angle = angle;
	cone->data.cone.height = height;
	cone->next = NULL;
	cone->id = 0;
	return (cone);
}

#if 1
void	init_scene(t_render *render)
{
	t_light		*main_light;
	t_light		*fill_light;
	t_object	*floor;
	t_object	*sphere1;
	t_object	*sphere2;
	t_object	*sphere3;
	t_object	*cone;

	render->scene.camera.position = (t_vec3){1.0, 2.0, 5.0};
	render->scene.camera.orientation = (t_vec3){-0.0, 0.00, 0.0};
	render->scene.camera.fov = 70.0;
	render->scene.ambient.ratio = 0.1;
	render->scene.ambient.color = (t_color){1.0, 1.0, 1.0};
	main_light = create_light((t_vec3){-3, 4, 1}, 0.7, (t_color){1.0, 1.0,
			1.0});
	fill_light = create_light((t_vec3){3, 4, 1}, 0.3, (t_color){1.0, 1.0, 1.0});
	main_light->next = fill_light;
	render->scene.lights = main_light;
	render->scene.selected_light = main_light;
	floor = create_plane((t_vec3){-3.1000, 0, -0}, (t_vec3){1, 0, 0},
			(t_color){0.0, 1.0, 1.0}, 1);
	sphere1 = create_sphere((t_vec3){0.0, -50.5, 0.0}, 50.0, (t_color){1.0, 0.0,
			0.0}, 2);
	sphere1->material.checker.scale = 1;
	sphere2 = create_sphere((t_vec3){1.0, 1.0, 0}, 0.8, (t_color){0.0, 0.0,
			1.0}, 3);
	sphere2->material.specular_coefficient = 0.0;
	sphere2->material.bump.intensity = 1.5;
	sphere2->material.bump.scale = 7.0;
	sphere3 = create_sphere((t_vec3){2.2, 0.0, 0}, 0.2, (t_color){0.0, 1.0,
			0.0}, 3);
	cone = create_cone((t_vec3){-1, 1, 0}, 15, 2);
	floor->next = sphere1;
	sphere1->next = sphere2;
	sphere2->next = sphere3;
	sphere3->next = cone;
	render->scene.objects = floor;
	render->scene.selected_obj = sphere1;
}

#else

void	init_scene(t_render *render)
{
	t_light		*main_light;
	t_object	*floor;
	t_object	*cone;

	render->scene.camera.position = (t_vec3){1.0, 2.0, 5.0};
	render->scene.camera.orientation = (t_vec3){-0.0, 0.00, 0.0};
	render->scene.camera.fov = 70.0;
	render->scene.ambient.ratio = 0.1;
	render->scene.ambient.color = (t_color){1.0, 1.0, 1.0};
	main_light = create_light((t_vec3){-3, 4, 1}, 0.7, (t_color){1.0, 1.0,
			1.0});
	render->scene.lights = main_light;
	floor = create_plane((t_vec3){0.0, 0.0, 0.0}, (t_vec3){0.0, 1.0, 0.0},
			(t_color){0.5, 0.5, 0.5}, 1);
	cone = create_cone((t_vec3){0.0, 1.0, -1.0}, 15, 2);
	cone->data.cone.normal = (t_vec3){ 1.0, 0.0, 0.0};
	floor->next = cone;
	render->scene.objects = floor;
	render->scene.selected_obj = cone;
	render->scene.selected_light = main_light;
}
#endif
