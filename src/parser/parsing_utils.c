/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:56:17 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/05 19:40:54 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_color	color_normalize(t_color vec)
{
	double	magnitude;
	t_color	normalized_color;

	magnitude = 255.0;
	normalized_color.r = vec.r / magnitude;
	normalized_color.g = vec.g / magnitude;
	normalized_color.b = vec.b / magnitude;
	return (normalized_color);
}

int	comma_count(char *val)
{
	int	count;

	count = 0;
	if (val)
	{
		while (*val)
		{
			if (*val == ',')
				count++;
			val++;
		}
	}
	return (count == 2);
}

int	valid(char **info, int count)
{
	int	i;

	i = 0;
	if (!info)
		return (0);
	while (info[i])
		i++;
	return (i == count);
}

int	float_valid(char *val)
{
	if (!val || !*val)
		return (0);
	if (*val == '-' || *val == '+')
		val++;
	if (!*val)
		return (0);
	while (*val)
	{
		if (!ft_isdigit(*val) && *val != '.')
			return (0);
		val++;
	}
	return (1);
}

int	int_valid(char *val)
{
	if (!val || !*val)
		return (0);
	if (*val == '-' || *val == '+')
		val++;
	if (!*val)
		return (0);
	while (*val)
	{
		if (!ft_isdigit(*val))
			return (0);
		val++;
	}
	return (1);
}

int	syntax_error(char **data)
{
	char	**row;
	char	*col;

	if (!data || !*data)
		return (1);
	row = data;
	col = *data;
	while (*row)
	{
		while (ft_isdigit(*col) || ft_isspace(*col) || *col == ','
			|| *col == '.')
			col++;
		if (*col != '\0')
			return (1);
	}
	return (row == NULL);
}

// void	*get_line(t_data *data)
// {
// 	static size_t	index = 1;
// 	size_t			line_len;

// 	line_len = 0;
// 	if (data->file->content)
// 	{
// 		if (*data->file->content == '\0')
// 			return (data->file->line = NULL, data->file->error = 0, NULL);
// 		line_len = ft_strcspn(data->file->content, "\n\0");
// 		data->file->line = ft_strndup(data->file->content, line_len);
// 		data->file->content += line_len + 1;
// 		if (*data->file->content == '\n')
// 			data->file->content++;
// 		data->file->line_index = index++;
// 		return (data->file->line);
// 	}
// 	return (NULL);
// }
