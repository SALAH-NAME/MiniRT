/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:59:46 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/02 09:27:46 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"

# include "algebra.h"
# include <stdbool.h>
# include <stdio.h>

void	test_message(bool pass, char *message);
bool	vec3_equals(t_vec3 a, t_vec3 b);
void	tests_vec3_addition(void);
void	tests_vec3_subtraction(void);
void	tests_vec3_dot(void);
void	tests_vec3_magnitude(void);
void	tests_vec3_cross(void);
void	tests_vec3_normalize(void);
void	tests_vec3_scale(void);

#endif
