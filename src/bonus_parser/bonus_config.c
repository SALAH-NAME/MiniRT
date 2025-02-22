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

void	parse_config_init(t_data *data)
{
	static t_elems	elements[ELEM_COUNT];
	static t_info	info[PARAM_COUNT];

	elements[AMBIENT] = (t_elems){"A", ID, 1, 2, &a_init};
	elements[CAMERA] = (t_elems){"C", ID, 1, 3, &c_init};
	elements[LIGHT] = (t_elems){"L", ID, 5, 3, &l_init};
	elements[PLANE] = (t_elems){"pl", ID, UN, 5, &pl_init};
	elements[SPHERE] = (t_elems){"sp", ID, UN, 4, &sp_init};
	elements[CYLINDER] = (t_elems){"cy", ID, UN, 6, &cy_init};
	elements[CONE] = (t_elems){"cn", ID, UN, 6, &cn_init};
	elements[COMMENT] = (t_elems){"#", UN, UN, UN, &comment};
	info[RATIO] = (t_info){"RATIO", VECTOR, {.d_r = {0.0, 1.0}}};
	info[AXIS] = (t_info){"AXIS", VECTOR, {.d_r = {-1.0, 1.0}}};
	info[COLOR] = (t_info){"COLOR", COLOR, {.i_r = {0, 255}}};
	info[DOUBLE] = (t_info){"DOUBLE", DOUBLE, {.d_r = {FLT_MIN, FLT_MAX}}};
	info[DIAMETER] = (t_info){"DIAMETER", DOUBLE, {.d_r = {0, FLT_MAX}}};
	data->config.elements = elements;
	data->config.info = info;
}
