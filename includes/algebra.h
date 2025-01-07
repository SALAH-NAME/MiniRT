/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:51:25 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/07 12:52:19 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

typedef struct s_vector3d
{
	double	x;
	double	y;
	double	z;
}			t_vector3d;

t_vector3d	vector3d_addition(t_vector3d vec_1, t_vector3d vec_2);
t_vector3d	vector3d_subtract(t_vector3d vec_1, t_vector3d vec_2);
t_vector3d	vector3d_scale(t_vector3d vec_1, double scalar);
t_vector3d	vector3d_cross(t_vector3d vec_1, t_vector3d vec_2);
t_vector3d	vector3d_normalize(t_vector3d vec);

double		vector3d_magnitude(t_vector3d vec);
double		vector3d_dot(t_vector3d vec_1, t_vector3d vec_2);

#endif
