/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   */
/*   Created: 2025/02/23 23:44:33 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/23 23:44:35 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "cylinder.h"

t_vec3	calc_cylinder_axis(t_cylinder cylinder)
{
	t_vec3	default_axis;
	t_vec3	axis;
	double	rotation_matrix[9];

	default_axis = (t_vec3){0.0, 0.0, 1.0};
	if (fabs(cylinder.normal.x) > EPSILON || fabs(cylinder.normal.y) > EPSILON
		|| fabs(cylinder.normal.z) > EPSILON)
	{
		matrix3_create_rotation(rotation_matrix, cylinder.normal);
		axis = matrix3_apply_rotation(rotation_matrix, cylinder.normal);
		return (vec3_normalize(axis));
	}
	return (default_axis);
}

double	check_caps(t_ray ray, t_cylinder cyl, t_vec3 axis, t_vec3 cap_center)
{
	double	denom;
	double	t;
	t_vec3	cap_point;

	denom = vec3_dot(ray.direction, axis);
	if (fabs(denom) <= EPSILON)
		return (-1);
	t = vec3_dot(vec3_sub(cap_center, ray.origin), axis) / denom;
	cap_point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	if (vec3_length(vec3_sub(cap_point, cap_center)) > cyl.radius)
		return (-1);
	return (t);
}

void	set_hit_normal(t_cylinder_hit_info info)
{
	if (info.t_side == info.hit->t)
	{
		info.hit->normal = vec3_normalize(vec3_sub(info.hit->point,
					vec3_add(info.cyl.center, vec3_mul(info.axis,
							info.height_test))));
		return ;
	}
	if (vec3_dot(info.hit->view_dir, info.axis) > 0)
		info.hit->normal = info.axis;
	else
		info.hit->normal = vec3_mul(info.axis, -1.0);
}

void	set_cylinder_hit(t_ray ray, t_object *obj, t_cyl_calc *calc, t_hit *hit)
{
	t_cylinder_hit_info	info;

	info.hit = hit;
	info.cyl = obj->data.cylinder;
	info.axis = calc->axis;
	info.t_side = calc->t_side;
	info.height_test = calc->height_test;
	hit->hit = true;
	hit->t = calc->t_final;
	hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, calc->t_final));
	hit->material = obj->material;
	hit->object = obj;
	hit->view_dir = vec3_mul(ray.direction, -1.0);
	set_hit_normal(info);
}
