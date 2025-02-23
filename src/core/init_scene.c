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

#ifdef BONUS

void	set_materials(t_object *obj)
{
	obj->material.diffuse_coefficient = 0.7;
	obj->material.shininess = 32.0;
}

#else

void	set_materials(t_object *obj)
{
	obj->material.diffuse_coefficient = 0.7;
	obj->material.specular_coefficient = 0.8;
	obj->material.shininess = 32.0;
}

#endif

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
	t_object	*obj;

	render->scene.is_raytrace = true;
	obj = render->scene.objects;
	while (obj)
	{
		set_materials(obj);
		obj = obj->next;
	}
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
