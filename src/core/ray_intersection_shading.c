/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection_shading.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:45:50 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/12 15:45:50 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

t_color	ray_intersection_shading(t_ray ray, t_scene *scene)
{
	t_hit	hit;

	if (find_nearest_intersection(ray, scene, &hit))
	{
		if (scene->is_raytrace)
			return (calculate_lighting(&hit, scene));
		return (hit.material.color);
	}
	return ((t_color){0, 0, 0});
}
