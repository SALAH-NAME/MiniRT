/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d_cross.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:29:24 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/02 08:29:41 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_vector3d	vector3d_cross(t_vector3d vec_1, t_vector3d vec_2)
{
	t_vector3d	vector;

	vector.x = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
	vector.y = vec_1.z * vec_2.x - vec_1.x * vec_2.z;
	vector.z = vec_1.x * vec_2.y - vec_1.y * vec_2.x;
	return (vector);
}
