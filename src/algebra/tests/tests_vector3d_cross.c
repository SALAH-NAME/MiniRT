/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vector3d_cross.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:31:39 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/02 08:53:42 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <math.h>

static void	create_and_run_cross_tests1(void)
{
	t_vector3d	v1;
	t_vector3d	v2;
	t_vector3d	result;

	v1 = (t_vector3d){1, 2, 3};
	v2 = (t_vector3d){4, 5, 6};
	result = vector3d_cross(v1, v2);
	printf("\n-- vector3d_cross (Set 1) --\n");
	test_message(result.x == -3 && result.y == 6 && result.z == -3,
		"Cross Product Test 1");
	v1 = (t_vector3d){-1, -2, -3};
	v2 = (t_vector3d){1, 2, 3};
	result = vector3d_cross(v1, v2);
	test_message(result.x == 0 && result.y == 0 && result.z == 0,
		"Cross Product Test 2");
	v1 = (t_vector3d){0, 0, 0};
	v2 = (t_vector3d){1, 2, 3};
	result = vector3d_cross(v1, v2);
	test_message(result.x == 0 && result.y == 0 && result.z == 0,
		"Cross Product Test 3");
}

static void	create_and_run_cross_tests2(void)
{
	t_vector3d	v3;
	t_vector3d	v4;
	t_vector3d	result;

	v3 = (t_vector3d){1.12345678, 2.23456789, 3.34567890};
	v4 = (t_vector3d){4.56789012, 5.67890123, 6.78901234};
	result = vector3d_cross(v3, v4);
	printf("\n-- vector3d_cross (Set 2) --\n");
	test_message(fabs(result.x - (-3.829271041)) < 1e-8 && fabs(result.y
			- (7.655531649)) < 1e-8 && fabs(result.z - (-3.827260497)) < 1e-8,
		"Cross Product Test 4");
	result = vector3d_cross(v4, v3);
	test_message(fabs(result.x - (3.829271041)) < 1e-8 && fabs(result.y
			- (-7.655531649)) < 1e-8 && fabs(result.z - (3.827260497)) < 1e-8,
		"Cross Product Test 5");
	v3 = (t_vector3d){-1.12345678, -2.23456789, -3.34567890};
	v4 = (t_vector3d){4.56789012, 5.67890123, 6.78901234};
	result = vector3d_cross(v3, v4);
	test_message(fabs(result.x - (3.829271041)) < 1e-8 && fabs(result.y
			- (-7.655531649)) < 1e-8 && fabs(result.z - (3.827260497)) < 1e-8,
		"Cross Product Test 6");
}

void	tests_vector3d_cross(void)
{
	create_and_run_cross_tests1();
	create_and_run_cross_tests2();
}
