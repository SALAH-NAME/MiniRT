/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d_normalize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:54:48 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/07 12:37:21 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"
#include <math.h>


// magniture = √(x^2 + y^2 + z^2)
// normalized_vector = (x / magnitude, y / magnitude, z / magnitude)
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
