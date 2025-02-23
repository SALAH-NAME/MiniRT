/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_nearest_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:47:21 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/23 23:52:02 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_intersect_fn	get_intersection_function(t_object_type type)
{
	static const t_intersect_fn	intersection_functions[] = {
		ray_sphere_intersect,
		ray_plane_intersect,
		ray_cylinder_intersect,
		ray_cone_intersect,
	};

	if (type > OBJ_CONE)
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
