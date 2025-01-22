/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec3_scale.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:10:07 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/22 10:10:08 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <math.h>

static void	create_and_run_scale_tests1(void)
{
	t_vec3	v1;
	t_vec3	result;

	v1 = (t_vec3){1, 2, 3};
	result = vec3_scale(v1, 2.0);
	printf("\n-- vec3_scale (Set 1) --\n");
	test_message(result.x == 2 && result.y == 4 && result.z == 6,
		"Scale Test 1");
	v1 = (t_vec3){-1, -2, -3};
	result = vec3_scale(v1, -2.0);
	test_message(result.x == 2 && result.y == 4 && result.z == 6,
		"Scale Test 2");
	v1 = (t_vec3){0, 0, 0};
	result = vec3_scale(v1, 5.0);
	test_message(result.x == 0 && result.y == 0 && result.z == 0,
		"Scale Test 3");
}

static void	create_and_run_scale_tests2(void)
{
	t_vec3	v2;
	t_vec3	result;

	v2 = (t_vec3){1.12345678, 2.23456789, 3.34567890};
	result = vec3_scale(v2, 1.5);
	printf("\n-- vec3_scale (Set 2) --\n");
	test_message(fabs(result.x - 1.68518517) < 1e-8 && fabs(result.y
			- 3.351851835) < 1e-8 && fabs(result.z - 5.01851835) < 1e-8,
		"Scale Test 4");
	v2 = (t_vec3){4.56789012, 5.67890123, 6.78901234};
	result = vec3_scale(v2, 0.5);
	test_message(fabs(result.x - 2.28394506) < 1e-8 && fabs(result.y
			- 2.839450615) < 1e-8 && fabs(result.z - 3.39450617) < 1e-8,
		"Scale Test 5");
}

void	tests_vec3_scale(void)
{
	create_and_run_scale_tests1();
	create_and_run_scale_tests2();
}
