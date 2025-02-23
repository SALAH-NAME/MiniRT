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

typedef struct s_cyl_calc
{
	t_vec3		axis;
	t_vec3		oc;
	t_vec3		oc_proj;
	t_vec3		d_proj;
	double		abc[3];
	double		t_side;
	double		height_test;
	t_vec3		point_side;
	double		t_cap1;
	double		t_cap2;
	double		t_final;
}				t_cyl_calc;

static t_vec3	get_cylinder_axis(t_vec3 normal)
{
	double	rotation_matrix[9];

	matrix3_create_rotation(rotation_matrix, normal);
	return (vec3_normalize(matrix3_apply_rotation(rotation_matrix,
				vec3_create(0, 1, 0))));
}

static void	init_cylinder_calc(t_cyl_calc *calc, t_ray ray, t_cylinder cyl)
{
	calc->axis = get_cylinder_axis(cyl.normal);
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

static double	check_caps(t_ray ray, t_cylinder cyl, t_vec3 axis,
		t_vec3 cap_center)
{
	double	denom;
	double	t;
	t_vec3	cap_point;

	denom = vec3_dot(ray.direction, axis);
	if (fabs(denom) <= 1e-6)
		return (-1);
	t = vec3_dot(vec3_sub(cap_center, ray.origin), axis) / denom;
	cap_point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	if (vec3_length(vec3_sub(cap_point, cap_center)) > cyl.radius)
		return (-1);
	return (t);
}

static void	set_hit_normal(t_hit *hit, t_cylinder cyl, t_vec3 axis,
		double t_side, double height_test)
{
	if (t_side == hit->t)
	{
		hit->normal = vec3_normalize(vec3_sub(hit->point, vec3_add(cyl.center,
						vec3_mul(axis, height_test))));
		return ;
	}
	if (vec3_dot(hit->view_dir, axis) > 0)
		hit->normal = axis;
	else
		hit->normal = vec3_mul(axis, -1.0);
}

bool	ray_cylinder_intersect(t_ray ray, t_object *obj, t_hit *hit)
{
	t_cylinder	cyl;
	t_cyl_calc	calc;

	cyl = obj->data.cylinder;
	init_cylinder_calc(&calc, ray, cyl);
	if (!solve_quadratic(calc.abc[0], calc.abc[1], calc.abc[2], &calc.t_side))
		return (false);
	calc.point_side = vec3_add(ray.origin, vec3_mul(ray.direction,
				calc.t_side));
	calc.height_test = vec3_dot(vec3_sub(calc.point_side, cyl.center),
			calc.axis);
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
	hit->hit = true;
	hit->t = calc.t_final;
	hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, calc.t_final));
	hit->material = obj->material;
	hit->object = obj;
	hit->view_dir = vec3_mul(ray.direction, -1.0);
	set_hit_normal(hit, cyl, calc.axis, calc.t_side, calc.height_test);
	return (true);
}
