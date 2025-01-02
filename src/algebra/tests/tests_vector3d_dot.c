/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vector3d_dot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:41:11 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/01 21:43:31 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	tests_vector3d_dot(void)
{
	t_vector3d	v1;
	t_vector3d	v2;
	t_vector3d	v3;
	t_vector3d	v4;

	v1 = (t_vector3d){1, 2, 3};
	v2 = (t_vector3d){4, 5, 6};
	v3 = (t_vector3d){-1, -2, -3};
	v4 = (t_vector3d){0, 0, 0};
	printf("\n-- vector3d_dot --\n");
	test_message(vector3d_dot(v1, v2) == 32, "Dot Product Test 1");
	test_message(vector3d_dot(v1, v3) == -14, "Dot Product Test 2");
	test_message(vector3d_dot(v1, v4) == 0, "Dot Product Test 3");
}
