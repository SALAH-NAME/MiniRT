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

bool	vec3_equals(t_vec3 a, t_vec3 b)
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
	tests_vec3_addition();
	tests_vec3_subtraction();
	tests_vec3_dot();
	tests_vec3_magnitude();
	tests_vec3_cross();
	tests_vec3_normalize();
	tests_vec3_scale();
	return (0);
}
