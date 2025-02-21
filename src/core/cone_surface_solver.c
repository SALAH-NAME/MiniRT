/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_surface_solver.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:08:49 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/21 09:08:49 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static double	calculate_abc_components(t_ray ray, t_cone_calc calc, t_vec3 co,
		double *abc)
{
	double	dot_d_v;
	double	dot_co_v;

	dot_d_v = vec3_dot(ray.direction, calc.axis);
	dot_co_v = vec3_dot(co, calc.axis);
	abc[0] = dot_d_v * dot_d_v - calc.cos2_theta * vec3_dot(ray.direction,
			ray.direction);
	abc[1] = 2.0 * (dot_d_v * dot_co_v - calc.cos2_theta
			* vec3_dot(ray.direction, co));
	abc[2] = dot_co_v * dot_co_v - calc.cos2_theta * vec3_dot(co, co);
	return (abc[1] * abc[1] - 4 * abc[0] * abc[2]);
}

bool	find_valid_intersection(double t1, double t2, double *t_hit)
{
	if (t1 > EPSILON && t2 > EPSILON)
		*t_hit = fmin(t1, t2);
	else if (t1 > EPSILON)
		*t_hit = t1;
	else if (t2 > EPSILON)
		*t_hit = t2;
	else
		return (false);
	return (true);
}

bool	solve_cone_surface(t_ray ray, t_cone_calc calc, double *t_hit)
{
	t_vec3	co;
	double	abc[3];
	double	discriminant;
	double	t1;
	double	t2;

	co = vec3_sub(ray.origin, calc.apex);
	discriminant = calculate_abc_components(ray, calc, co, abc);
	if (discriminant < 0)
		return (false);
	t1 = (-abc[1] - sqrt(discriminant)) / (2.0 * abc[0]);
	t2 = (-abc[1] + sqrt(discriminant)) / (2.0 * abc[0]);
	return (find_valid_intersection(t1, t2, t_hit));
}
