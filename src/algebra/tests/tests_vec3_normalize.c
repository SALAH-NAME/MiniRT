/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec3_normalize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:06:09 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/22 10:07:01 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <math.h>

static void	create_and_run_normalize_tests1(void)
{
	t_vec3	v1;
	t_vec3	result;

	v1 = (t_vec3){3, 0, 0};
	result = vec3_normalize(v1);
	printf("\n-- vec3_normalize (Set 1) --\n");
	test_message(result.x == 1.0 && result.y == 0.0 && result.z == 0.0,
		"Normalize Test 1");
	v1 = (t_vec3){0, 4, 0};
	result = vec3_normalize(v1);
	test_message(result.x == 0.0 && result.y == 1.0 && result.z == 0.0,
		"Normalize Test 2");
	v1 = (t_vec3){1, 2, 2};
	result = vec3_normalize(v1);
	test_message(fabs(result.x - (1.0 / 3.0)) < 1e-8 && fabs(result.y - (2.0
				/ 3.0)) < 1e-8 && fabs(result.z - (2.0 / 3.0)) < 1e-8,
		"Normalize Test 3");
	v1 = (t_vec3){0, 0, 0};
	result = vec3_normalize(v1);
	test_message(result.x == 0.0 && result.y == 0.0 && result.z == 0.0,
		"Normalize Test 4");
}

static void	create_and_run_normalize_tests2(void)
{
	t_vec3	v1;
	t_vec3	result;
	double	length;

	v1 = (t_vec3){1.12345678, 2.23456789, 3.34567890};
	length = 17.44901609;
	result = vec3_normalize(v1);
	printf("\n-- vec3_normalize (Set 2) --\n");
	test_message(fabs(result.x - (v1.x / sqrt(length))) < 1e-8 && fabs(result.y
			- (v1.y / sqrt(length))) < 1e-8 && fabs(result.z - (v1.z
				/ sqrt(length))) < 1e-8, "Normalize Test 5");
	v1 = (t_vec3){4.56789012, 5.67890123, 6.78901234};
	result = vec3_normalize(v1);
	length = 99.20622788;
	test_message(fabs(result.x - (v1.x / sqrt(length))) < 1e-8 && fabs(result.y
			- (v1.y / sqrt(length))) < 1e-8 && fabs(result.z - (v1.z
				/ sqrt(length))) < 1e-8, "Normalize Test 6");
}

void	tests_vec3_normalize(void)
{
	create_and_run_normalize_tests1();
	create_and_run_normalize_tests2();
}
