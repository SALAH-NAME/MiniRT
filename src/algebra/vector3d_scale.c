/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d_scale.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 09:25:07 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/02 09:25:17 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_vector3d	vector3d_scale(t_vector3d vec, double scalar)
{
	t_vector3d	scaled_vector;

	scaled_vector.x = vec.x * scalar;
	scaled_vector.y = vec.y * scalar;
	scaled_vector.z = vec.z * scalar;
	return (scaled_vector);
}
