/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inits_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 22:04:26 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/08 22:04:26 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	ratio_init(t_data *data, double *ratio, char *val, t_range range)
{
	if (!val)
		set_error(data, ERR_MS_RATIO, val, NULL);
	if (float_valid(val) == 0)
		set_error(data, ERR_RATIO_V, val, NULL);
	if (ft_strtod_safe(val, ratio) == 0)
		set_error(data, ERR_RATIO_R, val, NULL);
	if (*ratio < range.d_r[0] || *ratio > range.d_r[1])
		set_error(data, ERR_RATIO_R, val, NULL);
}

void	radius_init(t_data *data, double *radius, char *val)
{
	if (!val)
		set_error(data, ERR_MS_RADIUS, val, NULL);
	if (float_valid(val) == 0)
		set_error(data, ERR_RADIUS_V, val, NULL);
	if (ft_strtod_safe(val, radius) == 0)
		set_error(data, ERR_RADIUS_R, val, NULL);
	if (*radius < 0.0 || *radius > FLT_MAX)
		set_error(data, ERR_RADIUS_R, val, NULL);
}
