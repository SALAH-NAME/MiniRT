/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:57:44 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/05 19:40:54 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	ratio_init(t_data *data, double *ratio, char *val, t_range range)
{
	if (!val)
		set_error(data, ERR_MS_RATIO, val, NULL);
	if (v_valid(val) == 0)
		set_error(data, ERR_RATIO_V, val, NULL);
	if (ft_strtod_safe(val, ratio) == 0)
		set_error(data, ERR_RATIO_R, val, NULL);
	if (*ratio < range.d_r[0] || *ratio > range.d_r[1])
		set_error(data, ERR_RATIO_R, val, NULL);
}

void	color_init(t_data *data, int *color, char *val)
{
	char	**split;

	if (!val)
		set_error(data, ERR_MS_COLOR, val, NULL);
	split = ft_split(val, ',');
	data->file->split = split;
	if (ft_arrlen(split) != 3)
		set_error(data, ERR_MS_COLOR, val, NULL);
	if (v_valid(split[0]) == 0 || v_valid(split[1]) == 0
		|| v_valid(split[2]) == 0)
		set_error(data, ERR_COLOR_V, val, NULL);
	if (ft_atoi_safe(split[0], &color[0]) == 0 || color[0] < 0
		|| color[0] > 255)
		set_error(data, ERR_COLOR_R, split[0], NULL);
	if (ft_atoi_safe(split[1], &color[1]) == 0 || color[1] < 0
		|| color[1] > 255)
		set_error(data, ERR_COLOR_R, split[1], NULL);
	if (ft_atoi_safe(split[2], &color[2]) == 0 || color[2] < 0
		|| color[2] > 255)
		set_error(data, ERR_COLOR_R, split[2], NULL);
	ft_arrmapi(split, free);
	data->file->split = NULL;
}

void	position_init(t_data *data, double *pos, char *val)
{
	char	**split;

	if (!val)
		set_error(data, ERR_MS_COORD, val, NULL);
	split = ft_split(val, ',');
	data->file->split = split;
	if (ft_arrlen(split) != 3)
		set_error(data, ERR_MS_COORD, val, NULL);
	if (v_valid(split[0]) == 0 || v_valid(split[1]) == 0
		|| v_valid(split[2]) == 0)
		set_error(data, ERR_COORD_V, val, NULL);
	if (ft_strtod_safe(split[0], &pos[0]) == 0)
		set_error(data, ERR_COORD_R, split[0], NULL);
	if (ft_strtod_safe(split[1], &pos[1]) == 0)
		set_error(data, ERR_COORD_R, split[1], NULL);
	if (ft_strtod_safe(split[2], &pos[2]) == 0)
		set_error(data, ERR_COORD_R, split[2], NULL);
	ft_arrmapi(split, free);
	data->file->split = NULL;
}

void	degree_init(t_data *data, int *degree, char *val)
{
	if (!val)
		set_error(data, ERR_MS_DEGREE, val, NULL);
	if (v_valid(val) == 0)
		set_error(data, ERR_DEGREE_V, val, NULL);
	if (ft_atoi_safe(val, degree) == 0)
		set_error(data, ERR_DEGREE_V, val, NULL);
	if (*degree < 0.0 || *degree > 180.0)
		set_error(data, ERR_DEGREE_R, val, NULL);
}

void	vector_init(t_data *data, double *vector, char *val)
{
	char	**split;

	if (!val)
		set_error(data, ERR_MS_VECTOR, val, NULL);
	split = ft_split(val, ',');
	data->file->split = split;
	if (ft_arrlen(split) != 3)
		set_error(data, ERR_MS_VECTOR, val, NULL);
	if (v_valid(split[0]) == 0 || v_valid(split[1]) == 0
		|| v_valid(split[2]) == 0)
		set_error(data, ERR_VECTOR_V, val, NULL);
	if (ft_strtod_safe(split[0], &vector[0]) == 0)
		set_error(data, ERR_VECTOR_R, split[0], NULL);
	if (ft_strtod_safe(split[1], &vector[1]) == 0)
		set_error(data, ERR_VECTOR_R, split[1], NULL);
	if (ft_strtod_safe(split[2], &vector[2]) == 0)
		set_error(data, ERR_VECTOR_R, split[2], NULL);
	if (vector[0] < -1.0 || vector[0] > 1.0)
		set_error(data, ERR_VECTOR_R, split[0], NULL);
	if (vector[1] < -1.0 || vector[1] > 1.0)
		set_error(data, ERR_VECTOR_R, split[1], NULL);
	if (vector[2] < -1.0 || vector[2] > 1.0)
		set_error(data, ERR_VECTOR_R, split[2], NULL);
	ft_arrmapi(split, free);
	data->file->split = NULL;
}
