/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:09:09 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/22 10:09:10 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_vec3	vec3_cross(t_vec3 vec_1, t_vec3 vec_2)
{
	t_vec3	vector;

	vector.x = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
	vector.y = vec_1.z * vec_2.x - vec_1.x * vec_2.z;
	vector.z = vec_1.x * vec_2.y - vec_1.y * vec_2.x;
	return (vector);
}
