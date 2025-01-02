/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d_subtract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:44:44 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/01 15:45:05 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_vector3d	vector3d_subtract(t_vector3d vec_1, t_vector3d vec_2)
{
	t_vector3d	vector;

	vector.x = vec_1.x - vec_2.x;
	vector.y = vec_1.y - vec_2.y;
	vector.z = vec_1.z - vec_2.z;
	return (vector);
}
