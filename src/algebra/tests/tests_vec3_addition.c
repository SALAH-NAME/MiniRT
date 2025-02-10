/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec3_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:10:32 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/22 10:10:33 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_vec3_add(void)
{
	t_vec3	v1;
	t_vec3	v2;
	t_vec3	v3;
	t_vec3	v4;

	v1 = (t_vec3){1, 2, 3};
	v2 = (t_vec3){4, 5, 6};
	v3 = (t_vec3){-1, -2, -3};
	v4 = (t_vec3){0, 0, 0};
	printf("\n-- vec3_add --\n");
	test_message(vec3_equals(vec3_add(v1, v2), (t_vec3){5, 7, 9}),
		"Addition Test 1");
	test_message(vec3_equals(vec3_add(v1, v3), (t_vec3){0, 0, 0}),
		"Addition Test 2");
	test_message(vec3_equals(vec3_add(v1, v4), v1), "Addition Test 3");
}
