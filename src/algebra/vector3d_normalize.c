/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d_normalize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:54:48 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/02 08:55:51 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"
#include <math.h>

t_vector3d	vector3d_normalize(t_vector3d vec)
{
	double		magnitude;
	t_vector3d	normalized_vector;

	magnitude = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	if (magnitude == 0)
		normalized_vector = (t_vector3d){0, 0, 0};
	else
	{
		normalized_vector.x = vec.x / magnitude;
		normalized_vector.y = vec.y / magnitude;
		normalized_vector.z = vec.z / magnitude;
	}
	return (normalized_vector);
}
