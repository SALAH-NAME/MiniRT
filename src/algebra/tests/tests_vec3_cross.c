/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec3_cross.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:10:21 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/22 10:10:22 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <math.h>

static void	create_and_run_cross_tests1(void)
{
	t_vec3	v1;
	t_vec3	v2;
	t_vec3	result;

	v1 = (t_vec3){1, 2, 3};
	v2 = (t_vec3){4, 5, 6};
	result = vec3_cross(v1, v2);
	printf("\n-- vec3_cross (Set 1) --\n");
	test_message(result.x == -3 && result.y == 6 && result.z == -3,
		"Cross Product Test 1");
	v1 = (t_vec3){-1, -2, -3};
	v2 = (t_vec3){1, 2, 3};
	result = vec3_cross(v1, v2);
	test_message(result.x == 0 && result.y == 0 && result.z == 0,
		"Cross Product Test 2");
	v1 = (t_vec3){0, 0, 0};
	v2 = (t_vec3){1, 2, 3};
	result = vec3_cross(v1, v2);
	test_message(result.x == 0 && result.y == 0 && result.z == 0,
		"Cross Product Test 3");
}

static void	create_and_run_cross_tests2(void)
{
	t_vec3	v3;
	t_vec3	v4;
	t_vec3	result;

	v3 = (t_vec3){1.12345678, 2.23456789, 3.34567890};
	v4 = (t_vec3){4.56789012, 5.67890123, 6.78901234};
	result = vec3_cross(v3, v4);
	printf("\n-- vec3_cross (Set 2) --\n");
	test_message(fabs(result.x - (-3.829271041)) < 1e-8 && fabs(result.y
			- (7.655531649)) < 1e-8 && fabs(result.z - (-3.827260497)) < 1e-8,
		"Cross Product Test 4");
	result = vec3_cross(v4, v3);
	test_message(fabs(result.x - (3.829271041)) < 1e-8 && fabs(result.y
			- (-7.655531649)) < 1e-8 && fabs(result.z - (3.827260497)) < 1e-8,
		"Cross Product Test 5");
	v3 = (t_vec3){-1.12345678, -2.23456789, -3.34567890};
	v4 = (t_vec3){4.56789012, 5.67890123, 6.78901234};
	result = vec3_cross(v3, v4);
	test_message(fabs(result.x - (3.829271041)) < 1e-8 && fabs(result.y
			- (-7.655531649)) < 1e-8 && fabs(result.z - (3.827260497)) < 1e-8,
		"Cross Product Test 6");
}

void	tests_vec3_cross(void)
{
	create_and_run_cross_tests1();
	create_and_run_cross_tests2();
}
