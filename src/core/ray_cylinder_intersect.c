/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder_intersect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 08:32:02 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/23 23:48:22 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "cylinder.h"

static void	init_cylinder_calc(t_cyl_calc *calc, t_ray ray, t_cylinder cyl)
{
	calc->axis = calc_cylinder_axis(cyl);
	calc->oc = vec3_sub(ray.origin, cyl.center);
	calc->oc_proj = vec3_sub(calc->oc, vec3_mul(calc->axis, vec3_dot(calc->oc,
					calc->axis)));
	calc->d_proj = vec3_sub(ray.direction, vec3_mul(calc->axis,
				vec3_dot(ray.direction, calc->axis)));
	calc->abc[0] = vec3_dot(calc->d_proj, calc->d_proj);
	calc->abc[1] = 2.0 * vec3_dot(calc->oc_proj, calc->d_proj);
	calc->abc[2] = vec3_dot(calc->oc_proj, calc->oc_proj) - (cyl.radius
			* cyl.radius);
}

bool	ray_cylinder_intersect(t_ray ray, t_object *obj, t_hit *hit)
{
	t_cylinder	cyl;
	t_cyl_calc	calc;

	cyl = obj->data.cylinder;
	init_cylinder_calc(&calc, ray, cyl);
	if (!solve_quadratic(calc.abc[0], calc.abc[1], calc.abc[2], &calc.t_side))
		return (false);
	calc.p_s = vec3_add(ray.origin, vec3_mul(ray.direction, calc.t_side));
	calc.height_test = vec3_dot(vec3_sub(calc.p_s, cyl.center), calc.axis);
	if (calc.height_test < 0 || calc.height_test > cyl.height)
		calc.t_side = -1;
	calc.t_cap1 = check_caps(ray, cyl, calc.axis, cyl.center);
	calc.t_cap2 = check_caps(ray, cyl, calc.axis, vec3_add(cyl.center,
				vec3_mul(calc.axis, cyl.height)));
	calc.t_final = -1;
	if (calc.t_side > 0)
		calc.t_final = calc.t_side;
	if (calc.t_cap1 > 0 && (calc.t_final < 0 || calc.t_cap1 < calc.t_final))
		calc.t_final = calc.t_cap1;
	if (calc.t_cap2 > 0 && (calc.t_final < 0 || calc.t_cap2 < calc.t_final))
		calc.t_final = calc.t_cap2;
	if (calc.t_final < 0)
		return (false);
	set_cylinder_hit(ray, obj, &calc, hit);
	return (true);
}
