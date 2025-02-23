/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:04:02 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/23 23:42:15 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "algebra.h"
# include "minirt.h"
# include <math.h>
# include <stdbool.h>

typedef struct s_cone_calc
{
	t_cone	cone;
	t_vec3	axis;
	t_vec3	apex;
	double	cos2_theta;
	double	half_angle_rad;
	double	height;
}			t_cone_calc;

t_vec3		calc_cone_axis(t_cone cone);
t_cone_calc	init_cone_calc(t_cone cone);

bool		find_valid_intersection(double t1, double t2, double *t_hit);
bool		solve_cone_surface(t_ray ray, t_cone_calc calc, double *t_hit);

bool		is_within_base_circle(t_vec3 to_hit, t_vec3 axis,
				double base_radius);
bool		is_valid_cone_hit(t_ray ray, t_cone_calc calc, double t_cone);

bool		solve_base_hit(t_ray ray, t_cone_calc calc, double *t_hit);

void		set_cone_surface_hit(t_ray ray, t_hit *hit, t_cone_calc calc,
				double t_cone);
void		set_base_hit(t_ray ray, t_hit *hit, t_cone_calc calc,
				double t_base);

bool		handle_cone_hit(t_ray ray, t_hit *hit, t_cone_calc calc, double t);
bool		handle_base_hit(t_ray ray, t_hit *hit, t_cone_calc calc, double t);

bool		ray_cone_intersect(t_ray ray, t_object *obj, t_hit *hit);

#endif
