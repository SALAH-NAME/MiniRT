/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane_intersect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:30:08 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/13 14:30:08 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

bool	ray_plane_intersect(t_ray ray, t_object *obj, t_hit *hit)
{
	t_plane	plane;
	double	denom;
	t_vec3	p0l0;
	double	t;

	plane = obj->data.plane;
	denom = vec3_dot(ray.direction, plane.normal);
	if (fabs(denom) < EPSILON)
		return (false);
	p0l0 = vec3_sub(plane.center, ray.origin);
	t = vec3_dot(p0l0, plane.normal) / denom;
	if (t <= EPSILON)
		return (false);
	hit->hit = true;
	hit->t = t;
	hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	if (denom < 0)
		hit->normal = plane.normal;
	else
		hit->normal = vec3_mul(plane.normal, -1.0);
	hit->material = obj->material;
	hit->object = obj;
	hit->view_dir = vec3_mul(ray.direction, -1.0);
	return (true);
}
