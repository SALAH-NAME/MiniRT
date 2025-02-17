/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere_intersect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:58:13 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/12 15:58:13 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

bool	ray_sphere_intersect(t_ray ray, t_object *obj, t_hit *hit)
{
	t_sphere	sphere;
	t_vec3		oc;
	double		abc[3];
	double		t;

	sphere = obj->data.sphere;
	oc = vec3_sub(ray.origin, sphere.center);
	abc[0] = vec3_dot(ray.direction, ray.direction);
	abc[1] = 2.0 * vec3_dot(oc, ray.direction);
	abc[2] = vec3_dot(oc, oc) - (sphere.radius * sphere.radius);
	if (!solve_quadratic(abc[0], abc[1], abc[2], &t))
		return (false);
	hit->hit = true;
	hit->t = t;
	hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	hit->normal = vec3_normalize(vec3_sub(hit->point, sphere.center));
	if (obj->material.bump.intensity > 0)
		hit->normal = perturb_normal(hit->normal, hit->point, 
			&obj->material.bump);
	hit->material = obj->material;
	hit->object = obj;
	hit->view_dir = vec3_mul(ray.direction, -1.0);
	return (true);
}
