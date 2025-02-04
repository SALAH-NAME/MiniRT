/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec3_magnitude.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:10:56 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/22 10:10:57 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "tests.h"

static void	create_and_run_tests1(void)
{
	t_vec3	v1;
	t_vec3	v2;
	t_vec3	v3;
	t_vec3	v4;

	v1 = (t_vec3){1, 2, 3};
	v2 = (t_vec3){4, 5, 6};
	v3 = (t_vec3){-1, -2, -3};
	v4 = (t_vec3){0, 0, 0};
	printf("\n-- vec3_magnitude (Set 1) --\n");
	test_message(vec3_magnitude(v1) == sqrt(14), "Magnitude Test 1");
	test_message(vec3_magnitude(v2) == sqrt(77), "Magnitude Test 2");
	test_message(vec3_magnitude(v3) == sqrt(14), "Magnitude Test 3");
	test_message(vec3_magnitude(v4) == sqrt(0), "Magnitude Test 4");
}

static void	create_and_run_tests2(void)
{
	t_vec3	v5;
	t_vec3	v6;
	t_vec3	v7;
	t_vec3	v8;

	v5 = (t_vec3){1.12345678, 2.23456789, 3.34567890};
	v6 = (t_vec3){-1.12345678, -2.23456789, -3.34567890};
	v7 = (t_vec3){4.5678901234567890, 5.6789012345678901, 6.78901234567890123};
	v8 = (t_vec3){-4.5678901234567890, -5.6789012345678901,
		-6.78901234567890123};
	printf("\n-- vec3_magnitude (Set 2) --\n");
	test_message(fabs(vec3_magnitude(v5) - sqrt(17.44901609)) < 1e-8,
		"Magnitude Test 5");
	test_message(fabs(vec3_magnitude(v6) - sqrt(17.44901609)) < 1e-8,
		"Magnitude Test 6");
	test_message(fabs(vec3_magnitude(v7) - sqrt(99.20622804)) < 1e-8,
		"Magnitude Test 7");
	test_message(fabs(vec3_magnitude(v8) - sqrt(99.20622804)) < 1e-9,
		"Magnitude Test 8");
}

void	tests_vec3_magnitude(void)
{
	create_and_run_tests1();
	create_and_run_tests2();
}
