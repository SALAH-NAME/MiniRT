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
	if(obj->type == OBJ_CYLINDER)
	{
		if(obj->data.cylinder.normal.x == 0 && obj->data.cylinder.normal.y == 0 && obj->data.cylinder.normal.z == 0)
			obj->data.cylinder.normal = 	vec3_create(0, 1, 0);
	}
	if(obj->type == OBJ_CONE)
	{
		if(obj->data.cone.normal.x == 0 && obj->data.cone.normal.y == 0 && obj->data.cone.normal.z == 0)
			obj->data.cone.normal = 	vec3_create(0, 1, 0);
	}
	obj->material.diffuse_coefficient = 0.7;
	obj->material.specular_coefficient = 0.8;
	obj->material.shininess = 32.0;
}

#endif

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
