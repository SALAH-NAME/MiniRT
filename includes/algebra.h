/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:51:25 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/28 14:29:19 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <math.h>
# include <stdbool.h>

# define EPSILON 1e-6

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

t_vec3		vec3_create(double x, double y, double z);
t_vec3		vec3_add(t_vec3 vec_1, t_vec3 vec_2);
t_vec3		vec3_sub(t_vec3 vec_1, t_vec3 vec_2);
t_vec3		vec3_mul(t_vec3 vec_1, double scalar);
t_vec3		vec3_div(t_vec3 v, double scalar);
t_vec3		vec3_cross(t_vec3 vec_1, t_vec3 vec_2);
t_vec3		vec3_normalize(t_vec3 vec);
t_vec3		vec3_reflect(t_vec3 incident, t_vec3 normal);

double		vec3_length(t_vec3 vec);
double		vec3_length_squared(t_vec3 v);
double		vec3_dot(t_vec3 vec_1, t_vec3 vec_2);

bool		vec3_is_zero(t_vec3 v);

void		matrix3_create_rotation(double *matrix, t_vec3 angles);
t_vec3		matrix3_apply_rotation(const double *matrix, t_vec3 v);

#endif
