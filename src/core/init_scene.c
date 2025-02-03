/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:44:47 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/28 19:03:05by ysouahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_light	*create_light(void)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	light->position = vec3_create(-10, 10, 10);
	light->itensity = vec3_create(0.7, 0.7, 0.7);
	light->color = color_create(1, 1, 1);
	light->next = NULL;
	return (light);
}

static t_object	*create_sphere(t_vec3 pos, double r, t_material material,
		int id)
{
	t_object	*sphere;

	sphere = malloc(sizeof(t_object));
	sphere->type = OBJ_SPHERE;
	sphere->transform.position = vec3_create(0, 0, 0);
	sphere->material = material;
	sphere->data.sphere.center = vec3_create(pos.x, pos.y, pos.z);
	sphere->data.sphere.radius = r;
	sphere->data.sphere.material = material;
	sphere->id = id;
	sphere->next = NULL;
	return (sphere);
}

void	init_scene(t_render *render)
{
	t_light		*light;
	t_material	sphere_material;
	t_object	*sphere1;
	t_object	*sphere2;

	render->scene.camera.position = vec3_create(0, 0, 0);
	render->scene.camera.direction = vec3_create(1, -1, 0);
	render->scene.camera.fov = 60;
	render->scene.ambient.itensity = 0.2;
	render->scene.ambient.color = color_create(1, 1, 1);
	light = create_light();
	render->scene.lights = light;
	render->scene.selected_light = light;
	sphere_material = material_create(color_create(1, 0, 0), 0.7, 1.0, 32.0);
	sphere1 = create_sphere((t_vec3){0, 0, -5}, 1.0, sphere_material, 1);
	sphere_material = material_create(color_create(0, 0, 1), 0.7, 0.0, 32.0);
	sphere2 = create_sphere((t_vec3){-2.1, 0, -5}, 1.0, sphere_material, 2);
	sphere1->next = sphere2;
	render->scene.objects = sphere1;
	render->scene.selected_obj = sphere1;
}
