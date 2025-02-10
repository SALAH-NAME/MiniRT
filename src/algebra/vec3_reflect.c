/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_reflect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:49:38 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/10 09:49:38 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_vec3	vec3_reflect(t_vec3 incident, t_vec3 normal)
{
	return (vec3_sub(incident, vec3_mul(normal, 2.0 * vec3_dot(incident,
					normal))));
}
