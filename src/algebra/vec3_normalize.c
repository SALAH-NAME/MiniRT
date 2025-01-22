/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:54:48 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/22 10:07:15 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"
#include <math.h>

t_vec3	vec3_normalize(t_vec3 vec)
{
	double	magnitude;
	t_vec3	normalized_vector;

	magnitude = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	if (magnitude == 0)
		normalized_vector = (t_vec3){0, 0, 0};
	else
	{
		normalized_vector.x = vec.x / magnitude;
		normalized_vector.y = vec.y / magnitude;
		normalized_vector.z = vec.z / magnitude;
	}
	return (normalized_vector);
}
