/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3_apply_rotation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:54:26 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/10 09:54:26 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_vec3	matrix3_apply_rotation(const double *matrix, t_vec3 v)
{
	return ((t_vec3){matrix[0] * v.x + matrix[1] * v.y + matrix[2] * v.z,
		matrix[3] * v.x + matrix[4] * v.y + matrix[5] * v.z, matrix[6] * v.x
		+ matrix[7] * v.y + matrix[8] * v.z});
}
