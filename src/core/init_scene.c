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
