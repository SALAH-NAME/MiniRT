/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3_create_rotation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:52:28 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/10 09:52:28 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

static t_vec3	convert_to_radians(t_vec3 angles)
{
	t_vec3	rad_angles;

	rad_angles.x = -angles.x * M_PI;
	rad_angles.y = -angles.y * M_PI;
	rad_angles.z = -angles.z * M_PI;
	return (rad_angles);
}

static void	calculate_cos_sin(t_vec3 rad_angles, t_vec3 *cos_angles,
		t_vec3 *sin_angles)
{
	cos_angles->x = cos(rad_angles.x);
	cos_angles->y = cos(rad_angles.y);
	cos_angles->z = cos(rad_angles.z);
	sin_angles->x = sin(rad_angles.x);
	sin_angles->y = sin(rad_angles.y);
	sin_angles->z = sin(rad_angles.z);
}

static void	build_rotation_matrix(double *matrix, t_vec3 cos_angles,
		t_vec3 sin_angles)
{
	matrix[0] = cos_angles.y * cos_angles.z;
	matrix[1] = cos_angles.y * sin_angles.z;
	matrix[2] = -sin_angles.y;
	matrix[3] = sin_angles.x * sin_angles.y * cos_angles.z - cos_angles.x
		* sin_angles.z;
	matrix[4] = sin_angles.x * sin_angles.y * sin_angles.z + cos_angles.x
		* cos_angles.z;
	matrix[5] = sin_angles.x * cos_angles.y;
	matrix[6] = cos_angles.x * sin_angles.y * cos_angles.z + sin_angles.x
		* sin_angles.z;
	matrix[7] = cos_angles.x * sin_angles.y * sin_angles.z - sin_angles.x
		* cos_angles.z;
	matrix[8] = cos_angles.x * cos_angles.y;
}

void	matrix3_create_rotation(double *matrix, t_vec3 angles)
{
	t_vec3	rad_angles;
	t_vec3	cos_angles;
	t_vec3	sin_angles;

	rad_angles = convert_to_radians(angles);
	calculate_cos_sin(rad_angles, &cos_angles, &sin_angles);
	build_rotation_matrix(matrix, cos_angles, sin_angles);
}
