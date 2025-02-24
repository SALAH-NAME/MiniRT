/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:42:01 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/23 23:48:50 by ysemlali         ###   ########.fr       */
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
	t_vec3		p_s;
	double		t_cap1;
	double		t_cap2;
	double		t_final;
}				t_cyl_calc;

typedef struct s_cylinder_hit_info
{
	t_hit		*hit;
	t_cylinder	cyl;
	t_vec3		axis;
	double		t_side;
	double		height_test;
}				t_cylinder_hit_info;

// Cylinder function prototypes
t_vec3			calc_cylinder_axis(t_cylinder cylinder);
double			check_caps(t_ray ray, t_cylinder cyl, t_vec3 axis,
					t_vec3 cap_center);
void			set_hit_normal(t_cylinder_hit_info info);
void			set_cylinder_hit(t_ray ray, t_object *obj, t_cyl_calc *calc,
					t_hit *hit);
bool			ray_cylinder_intersect(t_ray ray, t_object *obj, t_hit *hit);
