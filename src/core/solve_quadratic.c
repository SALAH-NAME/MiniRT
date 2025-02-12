/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:05:27 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/12 16:05:27 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

bool	solve_quadratic(double a, double b, double c, double *t)
{
	double	discriminant;
	double	t1;
	double	t2;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false);
	t1 = (-b - sqrt(discriminant)) / (2.0 * a);
	t2 = (-b + sqrt(discriminant)) / (2.0 * a);
	if (t1 < t2 && t1 > EPSILON)
		*t = t1;
	else
		*t = t2;
	return (*t > EPSILON);
}
