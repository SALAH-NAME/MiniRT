/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec3_subtract.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:10:41 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/22 10:10:42 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_vec3_subtraction(void)
{
	t_vec3	v1;
	t_vec3	v2;
	t_vec3	v3;
	t_vec3	v4;

	v1 = (t_vec3){1, 2, 3};
	v2 = (t_vec3){4, 5, 6};
	v3 = (t_vec3){-1, -2, -3};
	v4 = (t_vec3){0, 0, 0};
	printf("\n-- vec3_subtraction --\n");
	test_message(vec3_equals(vec3_subtract(v1, v2), (t_vec3){-3, -3, -3}),
		"Subtraction Test 1");
	test_message(vec3_equals(vec3_subtract(v1, v3), (t_vec3){2, 4, 6}),
		"Subtraction Test 2");
	test_message(vec3_equals(vec3_subtract(v1, v4), v1), "Subtraction Test 3");
}
