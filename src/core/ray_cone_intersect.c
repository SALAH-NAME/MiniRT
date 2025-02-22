/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cone_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:32:14 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/18 22:32:14 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static bool	solve_cone_side(t_ray ray, t_cone cone, double *t_side)
{
	t_vec3	axis;
	t_vec3	oc;
	double	tan2;
	double	m1;
	double	m2;
	double	abc[3];

	axis = cone.normal;
	oc = vec3_sub(ray.origin, cone.center);
	tan2 = (cone.radius / cone.height) * (cone.radius / cone.height);
	m1 = vec3_dot(ray.direction, axis);
	m2 = vec3_dot(oc, axis);
	abc[0] = vec3_dot(ray.direction, ray.direction) - (1.0 + tan2) * (m1 * m1);
	abc[1] = 2.0 * (vec3_dot(ray.direction, oc) - (1.0 + tan2) * m1 * m2);
	abc[2] = vec3_dot(oc, oc) - (1.0 + tan2) * (m2 * m2);
	if (!solve_quadratic(abc[0], abc[1], abc[2], t_side))
		return (false);
	return (true);
}

static void	check_cone_side_range(t_ray ray, t_cone cone, double *t_side)
{
	double	height;
	t_vec3	p;
	t_vec3	axis;

	axis = cone.normal;
	p = vec3_add(ray.origin, vec3_mul(ray.direction, *t_side));
	height = vec3_dot(vec3_sub(p, cone.center), axis);
	if (height < 0.0 || height > cone.height)
		*t_side = -1.0;
}

static double	check_cone_bottom(t_ray ray, t_cone cone)
{
	t_vec3	axis;
	t_vec3	bottom_center;
	double	den;
	double	t_b;
	t_vec3	p;

	axis = vec3_normalize(cone.normal);
	bottom_center = vec3_add(cone.center, vec3_mul(axis, cone.height));
	den = vec3_dot(ray.direction, axis);
	if (fabs(den) < 1e-6)
		return (-1.0);
	t_b = vec3_dot(vec3_sub(bottom_center, ray.origin), axis) / den;
	if (t_b < 0.0)
		return (-1.0);
	p = vec3_add(ray.origin, vec3_mul(ray.direction, t_b));
	if (vec3_length(vec3_sub(p, bottom_center)) > cone.radius)
		return (-1.0);
	return (t_b);
}

static double	get_closest(double t_side, double t_bottom)
{
	double	t_final;

	t_final = -1.0;
	if (t_side > 0.0)
		t_final = t_side;
	if (t_bottom > 0.0 && (t_final < 0.0 || t_bottom < t_final))
		t_final = t_bottom;
	return (t_final);
}
static void	fill_hit_cone(t_ray ray, t_hit *hit, t_cone cone, double t_final,
		double t_side)
{
	t_vec3	axis;
	t_vec3	p;
	double	h;
	double	tan2;

	axis = cone.normal;
	hit->t = t_final;
	hit->hit = true;
	hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t_final));
	if (t_final == t_side)
	{
		p = vec3_sub(hit->point, cone.center);
		h = vec3_dot(p, axis);
		tan2 = (cone.radius / cone.height) * (cone.radius / cone.height);
		hit->normal = vec3_add(p, vec3_mul(axis, -h * (1.0 + tan2)));
		if (vec3_dot(hit->normal, ray.direction) > 0.0)
			hit->normal = vec3_mul(hit->normal, -1.0);
		hit->normal = vec3_normalize(hit->normal);
	}
	else
	{
		hit->normal = vec3_mul(axis, (vec3_dot(ray.direction,
						axis) < 0.0) ? 1.0 : -1.0);
	}
	hit->view_dir = vec3_mul(ray.direction, -1.0);
}

bool	ray_cone_intersect(t_ray ray, t_object *obj, t_hit *hit)
{
	t_cone	cone;
	double	t_side;
	double	t_bottom;
	double	t_final;
	cone = obj->data.cone;
 	double rotation_matrix[9]; 
    matrix3_create_rotation(rotation_matrix, cone.normal);
    cone.normal = vec3_normalize(matrix3_apply_rotation(rotation_matrix, vec3_create(0, 1, 0)));
 

	if (!solve_cone_side(ray, cone, &t_side))
		return (false);
	check_cone_side_range(ray, cone, &t_side);
	t_bottom = check_cone_bottom(ray, cone);
	t_final = get_closest(t_side, t_bottom);
	if (t_final < 0.0)
		return (false);
	hit->object = obj;
	hit->material = obj->material;
	fill_hit_cone(ray, hit, cone, t_final, t_side);
	return (true);
}
