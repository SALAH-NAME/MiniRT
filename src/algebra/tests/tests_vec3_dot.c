/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec3_dot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:09:50 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/22 10:09:51 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_vec3_dot(void)
{
	t_vec3	v1;
	t_vec3	v2;
	t_vec3	v3;
	t_vec3	v4;

	v1 = (t_vec3){1, 2, 3};
	v2 = (t_vec3){4, 5, 6};
	v3 = (t_vec3){-1, -2, -3};
	v4 = (t_vec3){0, 0, 0};
	printf("\n-- vec3_dot --\n");
	test_message(vec3_dot(v1, v2) == 32, "Dot Product Test 1");
	test_message(vec3_dot(v1, v3) == -14, "Dot Product Test 2");
	test_message(vec3_dot(v1, v4) == 0, "Dot Product Test 3");
}
