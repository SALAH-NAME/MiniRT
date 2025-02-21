/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_hit_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:09:26 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/21 09:09:26 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

bool	is_within_base_circle(t_vec3 to_hit, t_vec3 axis, double base_radius)
{
	t_vec3	projected;
	double	proj;
	double	hit_dist_sq;
	double	radius_sq;

	proj = vec3_dot(to_hit, axis);
	projected = vec3_sub(to_hit, vec3_mul(axis, proj));
	hit_dist_sq = vec3_dot(projected, projected);
	radius_sq = base_radius * base_radius;
	return (hit_dist_sq <= radius_sq);
}

bool	is_valid_cone_hit(t_ray ray, t_cone_calc calc, double t_cone)
{
	t_vec3	hit_point;
	t_vec3	hit_to_apex;
	double	proj_on_axis;

	if (t_cone <= EPSILON)
		return (false);
	hit_point = vec3_add(ray.origin, vec3_mul(ray.direction, t_cone));
	hit_to_apex = vec3_sub(calc.apex, hit_point);
	proj_on_axis = vec3_dot(hit_to_apex, calc.axis);
	if (proj_on_axis < 0 || proj_on_axis > calc.height)
		return (false);
	return (true);
}

bool	solve_base_hit(t_ray ray, t_cone_calc calc, double *t_hit)
{
	t_vec3	base_normal;
	t_vec3	base_hit;
	t_vec3	to_hit;
	double	denom;
	double	base_radius;

	base_normal = vec3_mul(calc.axis, -1.0);
	denom = vec3_dot(ray.direction, base_normal);
	if (fabs(denom) <= EPSILON)
		return (false);
	*t_hit = vec3_dot(vec3_sub(calc.cone.center, ray.origin), base_normal)
		/ denom;
	if (*t_hit <= EPSILON)
		return (false);
	base_hit = vec3_add(ray.origin, vec3_mul(ray.direction, *t_hit));
	to_hit = vec3_sub(base_hit, calc.cone.center);
	base_radius = calc.height * tan(calc.half_angle_rad);
	return (is_within_base_circle(to_hit, calc.axis, base_radius));
}

void	set_cone_surface_hit(t_ray ray, t_hit *hit, t_cone_calc calc,
		double t_cone)
{
	t_vec3	hit_to_apex;
	double	proj_on_axis;

	hit->hit = true;
	hit->t = t_cone;
	hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t_cone));
	hit_to_apex = vec3_sub(calc.apex, hit->point);
	proj_on_axis = vec3_dot(hit_to_apex, calc.axis);
	hit->normal = vec3_normalize(vec3_sub(hit_to_apex, vec3_mul(calc.axis,
					proj_on_axis / calc.cos2_theta)));
	if (vec3_dot(hit->normal, ray.direction) > 0)
		hit->normal = vec3_mul(hit->normal, -1.0);
}

void	set_base_hit(t_ray ray, t_hit *hit, t_cone_calc calc, double t_base)
{
	t_vec3	base_normal;

	hit->hit = true;
	hit->t = t_base;
	hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t_base));
	base_normal = vec3_mul(calc.axis, -1.0);
	hit->normal = base_normal;
	if (vec3_dot(hit->normal, ray.direction) > 0)
		hit->normal = vec3_mul(hit->normal, -1.0);
}
