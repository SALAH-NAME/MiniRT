/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:51:25 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/01 13:07:18 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

t_vec3		vec3_addition(t_vec3 vec_1, t_vec3 vec_2);
t_vec3		vec3_subtract(t_vec3 vec_1, t_vec3 vec_2);
t_vec3		vec3_scale(t_vec3 vec_1, double scalar);
t_vec3		vec3_cross(t_vec3 vec_1, t_vec3 vec_2);
t_vec3		vec3_normalize(t_vec3 vec);

double		vec3_magnitude(t_vec3 vec);
double		vec3_dot(t_vec3 vec_1, t_vec3 vec_2);

#endif
