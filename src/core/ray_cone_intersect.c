/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cone_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:12:01 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/21 09:12:01 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

bool	handle_cone_hit(t_ray ray, t_hit *hit, t_cone_calc calc, double t)
{
	set_cone_surface_hit(ray, hit, calc, t);
	hit->material = hit->object->material;
	hit->view_dir = vec3_mul(ray.direction, -1.0);
	return (true);
}

bool	handle_base_hit(t_ray ray, t_hit *hit, t_cone_calc calc, double t)
{
	set_base_hit(ray, hit, calc, t);
	hit->material = hit->object->material;
	hit->view_dir = vec3_mul(ray.direction, -1.0);
	return (true);
}

bool	ray_cone_intersect(t_ray ray, t_object *obj, t_hit *hit)
{
	t_cone_calc	calc;
	double		t_cone;
	double		t_base;
	bool		hit_cone;
	bool		hit_base;

	hit->object = obj;
	calc = init_cone_calc(obj->data.cone);
	hit_cone = solve_cone_surface(ray, calc, &t_cone) && is_valid_cone_hit(ray,
			calc, t_cone);
	hit_base = solve_base_hit(ray, calc, &t_base);
	if (hit_cone && hit_base)
	{
		if (t_base < t_cone)
			return (handle_base_hit(ray, hit, calc, t_base));
		else
			return (handle_cone_hit(ray, hit, calc, t_cone));
	}
	else if (hit_cone)
		return (handle_cone_hit(ray, hit, calc, t_cone));
	else if (hit_base)
		return (handle_base_hit(ray, hit, calc, t_base));
	return (false);
}
