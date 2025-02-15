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
	- Initializes configuration settings for parsing scene elements.
 *
 * elements[] (t_elems):
 *   - Represents different object types that can be parsed from the scene file.
 *   - Each entry consists of:
 *     1. Identifier string (e.g., "A" for Ambient light, "C" for Camera).
 *     2. Type flag (ID, NONE, etc.).
 *     3. Parsing constraints (UN = unlimited instances, 1 = single instance).
 *     4. Expected number of parameters for Identifier.
 *     5. Function pointer to the initializer for that element.
 *
 *   - Breakdown of each element:
 *     - "A"  (Ambient Light): ID, 1 instance max, expects 2 params,
	uses `a_init`
 *     - "C"  (Camera): ID, 1 instance max, expects 3 params, uses `c_init`
 *     - "L"  (Light Source): ID, 1 instance max, expects 3 params,
	uses `l_init`
 *     - "pl" (Plane): ID, unlimited instances, expects 3 params, uses `pl_init`
 *     - "sp" (Sphere): ID, unlimited instances, expects 3 params,
	uses `sp_init`
 *     - "cy" (Cylinder): ID, unlimited instances, expects 5 params,
	uses `cy_init`
 *     - Last entry is a NULL terminator to mark the end of the array.
 *
 * info[] (t_info):
 *   - Defines validation rules for different properties used in scene elements.
 *   - Each entry consists of:
 *     1. Property name (e.g., "RATIO", "AXIS").
 *     2. Type of data (VECTOR, COLOR, DOUBLE, etc.).
 *     3. Valid range for values (double range `d_r` or int range `i_r`).
 *     4. Unused function pointer (NULL for now).
 *
 *   - Breakdown of each info entry:
 *     - "RATIO": VECTOR type, must be between [0.0, 1.0] (e.g.,
	ambient light ratio).
 *     - "AXIS": VECTOR type, must be between [-1.0,
	1.0] (used for direction vectors).
 *     - "COLOR": COLOR type, must be in [0, 255] range for RGB components.
 *     - "DOUBLE": DOUBLE type,
	valid range from INT_MIN to INT_MAX (general purpose).
 *     - Last entry is a NULL terminator.
 *
 */

int	parse_config_init(t_data *data)
{
	static t_elems	elements[ELEM_COUNT];
	static t_info	info[PARAM_COUNT];

	elements[AMBIENT] = (t_elems){"A", ID, 1, 2, &a_init};
	elements[CAMERA] = (t_elems){"C", ID, 1, 3, &c_init};
	elements[LIGHT] = (t_elems){"L", ID, 5, 3, &l_init};
	elements[PLANE] = (t_elems){"pl", ID, UN, 3, &pl_init};
	elements[SPHERE] = (t_elems){"sp", ID, UN, 3, &sp_init};
	elements[CYLINDER] = (t_elems){"cy", ID, UN, 5, &cy_init};
	elements[COMMENT] = (t_elems){"#", UN, UN, UN, &comment};
	info[RATIO] = (t_info){"RATIO", VECTOR, {.d_r = {0.0, 1.0}}};
	info[AXIS] = (t_info){"AXIS", VECTOR, {.d_r = {-1.0, 1.0}}};
	info[COLOR] = (t_info){"COLOR", COLOR, {.i_r = {0, 255}}};
	info[DOUBLE] = (t_info){"DOUBLE", DOUBLE, {.d_r = {FLT_MIN, FLT_MAX}}};
	info[DIAMETER] = (t_info){"DIAMETER", DOUBLE, {.d_r = {0, FLT_MAX}}};
	data->config.elements = elements;
	data->config.info = info;
	return (0);
}
