/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:24:19 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/23 23:52:25 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "minirt.h"

bool	is_in_shadow(t_vec3 point, t_vec3 light_pos, t_scene *scene,
		t_object *current_obj)
{
	t_vec3		light_dir;
	double		light_distance;
	t_ray		shadow_ray;
	t_hit		shadow_hit;
	t_object	*obj;

	light_dir = vec3_sub(light_pos, point);
	light_distance = vec3_length(light_dir);
	light_dir = vec3_normalize(light_dir);
	shadow_ray.origin = vec3_add(point, vec3_mul(light_dir, EPSILON));
	shadow_ray.direction = light_dir;
	obj = scene->objects;
	while (obj)
	{
		if (obj != current_obj && get_intersection_function(obj->type)
			&& get_intersection_function(obj->type)(shadow_ray, obj,
			&shadow_hit) && shadow_hit.t < light_distance)
			return (true);
		obj = obj->next;
	}
	return (false);
}
