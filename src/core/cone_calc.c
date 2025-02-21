/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:56:40 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/21 08:56:40 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_vec3	calc_cone_axis(t_cone cone)
{
	t_vec3	default_axis;
	t_vec3	axis;
	double	rotation_matrix[9];

	default_axis = (t_vec3){0, 0, -1};
	if (fabs(cone.normal.x) > EPSILON || fabs(cone.normal.y) > EPSILON
		|| fabs(cone.normal.z) > EPSILON)
	{
		matrix3_create_rotation(rotation_matrix, cone.normal);
		axis = matrix3_apply_rotation(rotation_matrix, default_axis);
		return (vec3_normalize(axis));
	}
	return (default_axis);
}

t_cone_calc	init_cone_calc(t_cone cone)
{
	t_cone_calc	calc;

	calc.cone = cone;
	calc.axis = calc_cone_axis(cone);
	calc.half_angle_rad = (cone.angle / 2.0) * M_PI / 180.0;
	calc.cos2_theta = cos(calc.half_angle_rad) * cos(calc.half_angle_rad);
	calc.apex = vec3_add(cone.center, vec3_mul(calc.axis, cone.height));
	calc.height = cone.height;
	return (calc);
}
