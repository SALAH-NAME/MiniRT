/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:13:40 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/05 20:11:45 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	parse_line(t_data *data)
{
	int	i;

	i = 0;
	if (!data->file->line[0])
		return ;
	data->file->row = ft_split(data->file->line, ' ');
	while (data->config->elements[i].name != NULL && data->file->row[0] != NULL)
	{
		if (ft_strcmp(data->file->row[0], data->config->elements[i].name) == 0)
		{
			if (data->file->error)
				data->config->elements[i].init_func(data);
			ft_arrmapi(data->file->row, free);
			return ;
		}
		i++;
	}
	set_error(data, ERR_UNREC_OBJ_TYPE, data->file->row[0], NULL);
	ft_arrmapi(data->file->row, free);
}

void	scene_data(t_data *data)
{
	ft_bzero(&data->scene, sizeof(t_scene));
	data->file->error = 1;
	data->file->line = NULL;
	data->file->line_index = 0;
	data->file->line = get_next_line(data->file->fd);
	while (data->file->line)
	{
		data->file->line_index++;
		if (data->file->error)
			parse_line(data);
		free(data->file->line);
		data->file->line = get_next_line(data->file->fd);
	}
	print_scene(&data->scene);
	free(data->file->line);
	check_errors(data);
}

int	valid_file_name(char *file_name)
{
	char	*ext;

	if (ft_strcmp(file_name, ".rt") == 0)
		return (ft_putstr_fd("File must have a name\n", 2), 1);
	ext = ft_strrchr(file_name, '.');
	if (ext == NULL || ft_strcmp(ext, EXT))
		return (ft_putstr_fd("File type not supported\n", 2), 1);
	return (0);
}

int	load_file(t_data *data, char *file_name)
{
	t_file	*file;

	file = ft_calloc(1, sizeof(t_file));
	if (file)
	{
		data->file = file;
		file->file_name = file_name;
		file->fd = open(file_name, O_RDONLY);
		if (file->fd == -1)
			return (perror(file_name), 1);
		scene_data(data);
		close(file->fd);
	}
	return (0);
}
