/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:13:40 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/24 00:46:42 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void	parse_line(t_data *data)
{
	int	i;

	i = 0;
	if (!data->file.line[0])
		return ;
	data->file.row = ft_split(data->file.line, ' ');
	while (data->config.elements[i].name != NULL && data->file.row[0] != NULL)
	{
		if (ft_strcmp(data->file.row[0], data->config.elements[i].name) == 0)
		{
			if (data->file.error)
				data->config.elements[i].init_func(data);
			ft_arrmapi(data->file.row, free);
			return ;
		}
		i++;
	}
	set_error(data, ERR_UNREC_OBJ_TYPE, data->file.row[0], NULL);
	ft_arrmapi(data->file.row, free);
}

static void	scene_data(t_data *data)
{
	ft_bzero(&data->scene, sizeof(t_scene));
	data->file.error = 1;
	data->file.line = NULL;
	data->file.line_index = 0;
	data->file.line = get_next_line(data->file.fd);
	while (data->file.line)
	{
		data->file.line_index++;
		if (data->file.error)
			parse_line(data);
		free(data->file.line);
		data->file.line = get_next_line(data->file.fd);
	}
	free(data->file.line);
	check_errors(data);
}

static bool	valid_file_name(char *file_name)
{
	char	*ext;

	if (ft_strcmp(file_name, ".rt") == 0)
		return (ft_putstr_fd("File must have a name\n", 2), false);
	ext = ft_strrchr(file_name, '.');
	if (ext == NULL || ft_strcmp(ext, EXT))
		return (ft_putstr_fd("File type not supported\n", 2), false);
	return (true);
}

bool	parse_scene(t_render *render, char *file_name)
{
	t_data	data;

	if (valid_file_name(file_name) == false)
		return (false);
	parse_config_init(&data);
	data.file.file_name = file_name;
	data.file.fd = open(file_name, O_RDONLY);
	if (data.file.fd == -1)
		return (perror(file_name), false);
	scene_data(&data);
	close(data.file.fd);
	render->scene = data.scene;
	if (!data.file.error)
		free_all(&data);
	return (data.file.error != 0);
}
