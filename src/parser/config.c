/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:57:36 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/05 20:24:21 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

/**
 * parse_config_init
 * Initializes configuration settings for parsing scene elements.
 *
 * elements[] (t_elems):
 *   - Identifier string, Type flag, Parsing constraints, Expected params, Initializer function.
 *   - "A" (Ambient Light): ID, 1 instance, 2 params, `a_init`
 *   - "C" (Camera): ID, 1 instance, 3 params, `c_init`
 *   - "L" (Light Source): ID, 1 instance, 3 params, `l_init`
 *   - "pl" (Plane): ID, unlimited, 3 params, `pl_init`
 *   - "sp" (Sphere): ID, unlimited, 3 params, `sp_init`
 *   - "cy" (Cylinder): ID, unlimited, 5 params, `cy_init`
 *   - "#" (Comment): ID, unlimited, 0 params, `comment`
 *
 * info[] (t_info):
 *   - Property name, Data type, Valid range.
 *   - "RATIO": VECTOR, [0.0, 1.0]
 *   - "AXIS": VECTOR, [-1.0, 1.0]
 *   - "COLOR": COLOR, [0, 255]
 *   - "DOUBLE": DOUBLE, [FLT_MIN, FLT_MAX]
 *   - "DIAMETER": DOUBLE, [0, FLT_MAX]
 */

int	parse_config_init(t_data *data)
{
	static t_elems	elements[ELEM_COUNT];
	static t_info	info[PARAM_COUNT];

	elements[AMBIENT] = (t_elems){"A", ID, 1, 2, &a_init};
	elements[CAMERA] = (t_elems){"C", ID, 1, 3, &c_init};
	elements[LIGHT] = (t_elems){"L", ID, 1, 3, &l_init};
	elements[PLANE] = (t_elems){"pl", ID, UN, 3, &pl_init};
	elements[SPHERE] = (t_elems){"sp", ID, UN, 3, &sp_init};
	elements[CYLINDER] = (t_elems){"cy", ID, UN, 5, &cy_init};
	elements[COMMENT] = (t_elems){"#", ID, UN, 0, &comment};
	info[RATIO] = (t_info){"RATIO", VECTOR, {.d_r = {0.0, 1.0}}};
	info[AXIS] = (t_info){"AXIS", VECTOR, {.d_r = {-1.0, 1.0}}};
	info[COLOR] = (t_info){"COLOR", COLOR, {.i_r = {0, 255}}};
	info[DOUBLE] = (t_info){"DOUBLE", DOUBLE, {.d_r = {FLT_MIN, FLT_MAX}}};
	info[DIAMETER] = (t_info){"DIAMETER", DOUBLE, {.d_r = {0, FLT_MAX}}};
	info[ANGLE] = (t_info){"ANGLE", DOUBLE, {.d_r = {0, 175}}};
	data->config.elements = elements;
	data->config.info = info;
	return (0);
}
