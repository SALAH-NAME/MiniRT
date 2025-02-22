/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder_intersect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 08:32:02 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/16 08:32:02 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

bool	ray_cylinder_intersect(t_ray ray, t_object *obj, t_hit *hit)
{
	t_cylinder	cylinder;
	t_vec3		oc;
	t_vec3		d;
	t_vec3		oc_proj;
	t_vec3		d_proj;
	double		abc[3];
	double		t_side;
	t_vec3		point_side;
	double		height_test;
	double		t_caps[2];
	t_vec3		cap_centers[2] = {cylinder.center, vec3_add(cylinder.center,
					vec3_mul(axis, cylinder.height))};
	double		denom;
	t_vec3		cap_point;
	double		t_final;

	cylinder = obj->data.cylinder;
	oc = vec3_sub(ray.origin, cylinder.center);
	t_vec3 axis = vec3_normalize(cylinder.normal);
		// Cylinder axis (assumed normalized)
	d = ray.direction;
	oc_proj = vec3_sub(oc, vec3_mul(axis, vec3_dot(oc, axis)));
	d_proj = vec3_sub(d, vec3_mul(axis, vec3_dot(d, axis)));
	abc[0] = vec3_dot(d_proj, d_proj);
	abc[1] = 2.0 * vec3_dot(oc_proj, d_proj);
	abc[2] = vec3_dot(oc_proj, oc_proj) - (cylinder.radius * cylinder.radius);
	if (!solve_quadratic(abc[0], abc[1], abc[2], &t_side))
		return (false);
	point_side = vec3_add(ray.origin, vec3_mul(ray.direction, t_side));
	height_test = vec3_dot(vec3_sub(point_side, cylinder.center), axis);
	if (height_test < 0 || height_test > cylinder.height)
		t_side = -1; // Outside finite cylinder bounds
	// Check intersection with caps (top and bottom circles)
	for (int i = 0; i < 2; i++)
	{
		denom = vec3_dot(ray.direction, axis);
		if (fabs(denom) > 1e-6)
		{
			t_caps[i] = vec3_dot(vec3_sub(cap_centers[i], ray.origin), axis)
				/ denom;
			cap_point = vec3_add(ray.origin, vec3_mul(ray.direction,
						t_caps[i]));
			if (!(vec3_length(vec3_sub(cap_point,
							cap_centers[i])) <= cylinder.radius))
				t_caps[i] = -1;
		}
		else
		{
			t_caps[i] = -1;
		}
	}
	// Determine closest valid intersection
	t_final = -1;
	if (t_side > 0)
		t_final = t_side;
	for (int i = 0; i < 2; i++)
	{
		if (t_caps[i] > 0 && (t_final < 0 || t_caps[i] < t_final))
		{
			t_final = t_caps[i];
		}
	}
	if (t_final < 0)
		return (false); // No valid intersection
	hit->hit = true;
	hit->t = t_final;
	hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t_final));
	if (t_final == t_side)
	{
		hit->normal = vec3_normalize(vec3_sub(hit->point,
					vec3_add(cylinder.center, vec3_mul(axis, height_test))));
	}
	else
	{
		hit->normal = vec3_mul(axis, (vec3_dot(ray.direction, axis) < 0) ? 1.0 :
				-1.0);
	}
	hit->material = obj->material;
	hit->object = obj;
	hit->view_dir = vec3_mul(ray.direction, -1.0);
	return (true);
}
