/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:23:59 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/28 15:25:49 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	material_create(t_color color, double diffuse, double specular,
		double shininess)
{
	t_material	material;

	material.color = color;
	material.diffuse_coefficient = diffuse;
	material.specular_coefficient = specular;
	material.shininess = shininess;
	return (material);
}
