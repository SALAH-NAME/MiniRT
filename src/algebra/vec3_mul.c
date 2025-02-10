/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:08:53 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/22 10:08:54 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_vec3	vec3_mul(t_vec3 vec, double scalar)
{
	t_vec3	scaled_vector;

	scaled_vector.x = vec.x * scalar;
	scaled_vector.y = vec.y * scalar;
	scaled_vector.z = vec.z * scalar;
	return (scaled_vector);
}
