/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nearest_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:51:19 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/12 15:51:19 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static t_intersect_fn	get_intersection_function(t_object_type type)
{
	static const t_intersect_fn	intersection_functions[] = {
		ray_sphere_intersect
		/*[OBJ_SPHERE] = ray_sphere_intersect,*/
		/*[OBJ_PLANE] = ray_plane_intersect,*/
		/*[OBJ_CYLINDER] = ray_cylinder_intersect,*/
		/*[OBJ_CONE] = ray_cone_intersect*/
	};

	if (type > OBJ_SPHERE)
		return (NULL);
	return (intersection_functions[type]);
}

bool	find_nearest_intersection(t_ray ray, t_scene *scene, t_hit *hit)
{
	t_hit			temp_hit;
	t_object		*obj;
	t_intersect_fn	intersect_fn;

	hit->hit = false;
	hit->t = INFINITY;
	obj = scene->objects;
	while (obj)
	{
		intersect_fn = get_intersection_function(obj->type);
		if (intersect_fn && intersect_fn(ray, obj, &temp_hit)
			&& temp_hit.t < hit->t)
			*hit = temp_hit;
		obj = obj->next;
	}
	return (hit->hit);
}
