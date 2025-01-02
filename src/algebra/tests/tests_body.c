/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:59:54 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/02 09:28:05 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"
#include "tests.h"
#include <stdbool.h>
#include <stdio.h>

bool	vector3d_equals(t_vector3d a, t_vector3d b)
{
	return (a.x == b.x && a.y == b.y && a.z == b.z);
}

void	test_message(bool pass, char *message)
{
	if (pass)
		printf(GREEN "%s Passed\n" RESET, message);
	else
		printf(RED "%s Failed\n" RESET, message);
}

int	main(void)
{
	printf("\n=== TESTS LIB_ALGEBRA ===\n");
	tests_vector3d_addition();
	tests_vector3d_subtraction();
	tests_vector3d_dot();
	tests_vector3d_magnitude();
	tests_vector3d_cross();
	tests_vector3d_normalize();
	tests_vector3d_scale();
	return (0);
}
