/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:57:44 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/01 11:49:51 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	color_init(t_data *data, t_color *color, char *val)
{
	char	**split;

	if (!val || !comma_count(val))
		set_error(data, ERR_MS_COLOR, val, NULL);
	split = ft_split(val, ',');
	data->file.split = split;
	if (ft_arrlen(split) != 3)
		set_error(data, ERR_MS_COLOR, val, NULL);
	if (int_valid(split[0]) == 0 || int_valid(split[1]) == 0
		|| int_valid(split[2]) == 0)
		set_error(data, ERR_COLOR_V, val, NULL);
	if (ft_strtod_safe(split[0], &color->r) == 0 || color->r < 0
		|| color->r > 255)
		set_error(data, ERR_COLOR_R, split[0], NULL);
	if (ft_strtod_safe(split[1], &color->g) == 0 || color->g < 0
		|| color->g > 255)
		set_error(data, ERR_COLOR_R, split[1], NULL);
	if (ft_strtod_safe(split[2], &color->b) == 0 || color->b < 0
		|| color->b > 255)
		set_error(data, ERR_COLOR_R, split[2], NULL);
	*color = color_normalize(*color);
	ft_arrmapi(split, free);
	data->file.split = NULL;
}

void	position_init(t_data *data, t_vec3 *pos, char *val)
{
	char	**split;

	if (!val || !comma_count(val))
		set_error(data, ERR_MS_COORD, val, NULL);
	split = ft_split(val, ',');
	data->file.split = split;
	if (ft_arrlen(split) != 3)
		set_error(data, ERR_MS_COORD, val, NULL);
	if (float_valid(split[0]) == 0 || float_valid(split[1]) == 0
		|| float_valid(split[2]) == 0)
		set_error(data, ERR_COORD_V, val, NULL);
	if (ft_strtod_safe(split[0], &pos->x) == 0)
		set_error(data, ERR_COORD_R, split[0], NULL);
	if (ft_strtod_safe(split[1], &pos->y) == 0)
		set_error(data, ERR_COORD_R, split[1], NULL);
	if (ft_strtod_safe(split[2], &pos->z) == 0)
		set_error(data, ERR_COORD_R, split[2], NULL);
	ft_arrmapi(split, free);
	data->file.split = NULL;
}

void	degree_init(t_data *data, int *degree, char *val)
{
	if (!val)
		set_error(data, ERR_MS_DEGREE, val, NULL);
	if (int_valid(val) == 0)
		set_error(data, ERR_DEGREE_V, val, NULL);
	if (ft_atoi_safe(val, degree) == 0)
		set_error(data, ERR_DEGREE_V, val, NULL);
	if (*degree < 0.0 || *degree > 180.0)
		set_error(data, ERR_DEGREE_R, val, NULL);
}

void	vector_init(t_data *data, t_vec3 *vector, char *val)
{
	char	**split;

	if (!val || !comma_count(val))
		set_error(data, ERR_MS_VECTOR, val, NULL);
	split = ft_split(val, ',');
	data->file.split = split;
	if (ft_arrlen(split) != 3)
		set_error(data, ERR_MS_VECTOR, val, NULL);
	if (float_valid(split[0]) == 0 || float_valid(split[1]) == 0
		|| float_valid(split[2]) == 0)
		set_error(data, ERR_VECTOR_V, val, NULL);
	if (ft_strtod_safe(split[0], &vector->x) == 0)
		set_error(data, ERR_VECTOR_R, split[0], NULL);
	if (ft_strtod_safe(split[1], &vector->y) == 0)
		set_error(data, ERR_VECTOR_R, split[1], NULL);
	if (ft_strtod_safe(split[2], &vector->z) == 0)
		set_error(data, ERR_VECTOR_R, split[2], NULL);
	if (vector->x < -1.0 || vector->x > 1.0)
		set_error(data, ERR_VECTOR_R, split[0], NULL);
	if (vector->y < -1.0 || vector->y > 1.0)
		set_error(data, ERR_VECTOR_R, split[1], NULL);
	if (vector->z < -1.0 || vector->z > 1.0)
		set_error(data, ERR_VECTOR_R, split[2], NULL);
	ft_arrmapi(split, free);
	data->file.split = NULL;
}
