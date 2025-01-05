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

int	parse_config_init(t_data *data)
{
	static t_elems	elements[7];
	static t_info	info[5];

	data->config = ft_calloc(1, sizeof(t_config));
	if (!data->config)
		return (1);
	elements[AMBIENT] = (t_elems){"A", ID, 1, 2, &a_init};
	elements[CAMERA] = (t_elems){"C", ID, 1, 3, &c_init};
	elements[LIGHT] = (t_elems){"L", ID, 1, 3, &l_init};
	elements[PLANE] = (t_elems){"pl", ID, UN, 3, &pl_init};
	elements[SPHERE] = (t_elems){"sp", ID, UN, 3, &sp_init};
	elements[CYLINDER] = (t_elems){"cy", ID, UN, 5, &cy_init};
	elements[6] = (t_elems){NULL, NONE, UN, UN, NULL};
	info[RATIO] = (t_info){"RATIO", VECTOR, {.d_r = {0.0, 1.0}}, NULL};
	info[AXIS] = (t_info){"AXIS", VECTOR, {.d_r = {-1.0, 1.0}}, NULL};
	info[COLOR] = (t_info){"COLOR", COLOR, {.i_r = {0, 255}}, NULL};
	info[DOUBLE] = (t_info){"DOUBLE", DOUBLE, {.d_r = {(double)INT_MIN,
		(double)INT_MAX}}, NULL};
	info[4] = (t_info){NULL, NONE, {{UN, UN}, {UN, UN}}, NULL};
	data->config->elements = elements;
	data->config->info = info;
	data->config->res[0] = 1920;
	data->config->res[1] = 1080;
	return (0);
}
