/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:13:40 by ysemlali          #+#    #+#             */
/*   Updated: 2024/12/30 12:22:04 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

char	*read_file(int fd)
{
	char	*file;
	char	*tmp;
	char	buf[4096];
	int		bytes;

	ft_bzero(buf, 4096);
	tmp = NULL;
	file = ft_strdup("");
	while (1)
	{
		bytes = read(fd, buf, 4096 - 1);
		if (bytes == -1)
			return (perror("read"), NULL);
		else if (bytes == 0)
			break ;
		tmp = ft_strjoin(file, buf);
		if (!tmp)
			return (free(file), NULL);
		free(file);
		file = tmp;
		ft_bzero(buf, 4096);
	}
	return (file);
}

t_file	*file_parse(char *file_name)
{
	t_file	*file;

	file = ft_calloc(1, sizeof(t_file));
	if (file)
	{
		file->fd = open(file_name, O_RDONLY);
		if (file->fd == -1)
			return (perror("open"), NULL);
		file->content = read_file(file->fd);
		printf("%s\n", file->content);
		file->size = file_size(file->content);
	}
	return (file);
}
