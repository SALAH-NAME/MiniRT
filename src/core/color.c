/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:20:28 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/28 15:23:26 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

t_color	color_create(float r, float g, float b)
{
	t_color	color;

	color.r = fmin(fmax(r, 0.0f), 1.0f);
	color.g = fmin(fmax(g, 0.0f), 1.0f);
	color.b = fmin(fmax(b, 0.0f), 1.0f);
	return (color);
}

t_color	color_multiply(t_color color, double t)
{
	return (color_create(color.r * t, color.g * t, color.b * t));
}
