/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:21:59 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/28 16:24:03 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "float.h"

t_hit	init_hit(t_object *obj)
{
	t_hit	hit;

	hit.hit = false;
	hit.t = DBL_MAX;
	hit.point = vec3_create(0, 0, 0);
	hit.normal = vec3_create(0, 0, 0);
	hit.view_dir = vec3_create(0, 0, 0);
	hit.material = obj->material;
	hit.object = NULL;
	return (hit);
}

void	update_hit(t_hit *hit, double t, t_ray ray, t_object *obj)
{
	hit->hit = true;
	hit->t = t;
	hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	hit->normal = vec3_normalize(vec3_sub(hit->point,
				obj->data.sphere.center));
	hit->view_dir = vec3_mul(ray.direction, -1.0);
	hit->object = obj;
	hit->material = obj->material;
}

t_hit	solve_sphere_equation(t_ray ray, t_sphere sphere, t_object *obj)
{
	t_hit	hit;
	t_vec3	oc;
	double	abc[3];
	double	discriminant;
	double	t[2];

	hit = init_hit(obj);
	oc = vec3_sub(ray.origin, sphere.center);
	abc[0] = vec3_dot(ray.direction, ray.direction);
	abc[1] = 2.0 * vec3_dot(oc, ray.direction);
	abc[2] = vec3_dot(oc, oc) - sphere.radius * sphere.radius;
	discriminant = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (discriminant < 0)
		return (hit);
	t[0] = (-abc[1] - sqrt(discriminant)) / (2.0 * abc[0]);
	t[1] = (-abc[1] + sqrt(discriminant)) / (2.0 * abc[0]);
	if (t[0] > EPSILON)
		update_hit(&hit, t[0], ray, obj);
	else if (t[1] > EPSILON)
		update_hit(&hit, t[1], ray, obj);
	return (hit);
}

t_hit	intersect_sphere(t_ray ray, t_object *obj)
{
	return (solve_sphere_equation(ray, obj->data.sphere, obj));
}

t_hit	find_nearest_intersection(t_ray ray, t_scene *scene)
{
	t_hit		nearest_hit;
	t_object	*current;
	t_hit		current_hit;

	nearest_hit = init_hit(scene->objects);
	current = scene->objects;
	while (current)
	{
		if (current->type == OBJ_SPHERE)
		{
			current_hit = intersect_sphere(ray, current);
			if (current_hit.hit && current_hit.t < nearest_hit.t)
				nearest_hit = current_hit;
		}
		current = current->next;
	}
	return (nearest_hit);
}
