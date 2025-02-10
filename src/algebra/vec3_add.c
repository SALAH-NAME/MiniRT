/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:09:29 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/22 10:09:30 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_vec3	vec3_add(t_vec3 vec_1, t_vec3 vec_2)
{
	t_vec3	vector;

	vector.x = vec_1.x + vec_2.x;
	vector.y = vec_1.y + vec_2.y;
	vector.z = vec_1.z + vec_2.z;
	return (vector);
}
