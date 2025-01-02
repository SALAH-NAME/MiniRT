/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d_addition.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:18:29 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/01 13:21:11 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_vector3d	vector3d_addition(t_vector3d vec_1, t_vector3d vec_2)
{
	t_vector3d	vector;

	vector.x = vec_1.x + vec_2.x;
	vector.y = vec_1.y + vec_2.y;
	vector.z = vec_1.z + vec_2.z;
	return (vector);
}
