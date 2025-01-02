/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vector3d_subtract.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:32:25 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/01 16:04:04 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_vector3d_subtraction(void)
{
	t_vector3d	v1;
	t_vector3d	v2;
	t_vector3d	v3;
	t_vector3d	v4;

	v1 = (t_vector3d){1, 2, 3};
	v2 = (t_vector3d){4, 5, 6};
	v3 = (t_vector3d){-1, -2, -3};
	v4 = (t_vector3d){0, 0, 0};
	printf("\n-- vector3d_subtraction --\n");
	test_message(vector3d_equals(vector3d_subtract(v1, v2),
			(t_vector3d){-3, -3, -3}), "Subtraction Test 1");
	test_message(vector3d_equals(vector3d_subtract(v1, v3),
			(t_vector3d){2, 4, 6}), "Subtraction Test 2");
	test_message(vector3d_equals(vector3d_subtract(v1, v4), v1),
		"Subtraction Test 3");
}
