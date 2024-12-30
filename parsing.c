/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:13:40 by ysemlali          #+#    #+#             */
/*   Updated: 2024/12/30 13:13:10 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


void free_information(char **information)
{
  char **tmp = information;
  
  while (tmp && *tmp) 
  {
    if(*tmp)
    {
      printf("%s\n",*tmp);
      free(*tmp);
    }
    tmp++;
  }
}



t_Scene	*scene_info(char **elements)
{
	t_Scene	*scene;
	char	**information;
  char **tmp;

	scene = ft_calloc(1, sizeof(t_Scene));
	if (scene)
	{
		while (*elements)
		{
      printf("%s\n",*elements);
			information = ft_split(*elements, ' ');
      tmp = information;
			if (strcmp(*information, "L") == 0)
				init_light(information+1, scene->light);
			else if (strcmp(*information, "C") == 0)
				init_camera(information+1, scene->camera);
			else if (strcmp(*information, "A") == 0)
				init_ambient(information+1, scene->ambient);
			elements++;
      free_information(tmp);
		}
	}
	return (scene);
}

int	valid_file_name(char *file_name)
{
	char	*name;
	char	*ext;

	name = ft_strmapi(file_name, toggle);
	ext = ft_strchr(name, '.');
	if (ext == NULL || ft_strcmp(ext, EXT))
		return (free(name), printf("file type not supported\n"), 1);
	return (free(name), 0);
}

char	*read_file(int fd)
{
	char	*file;
	char	*tmp;
	char	buf[KB_4];
	int		bytes;

	ft_bzero(buf, KB_4);
	tmp = NULL;
	file = ft_strdup("");
	while (1)
	{
		bytes = read(fd, buf, KB_4 - 1);
		if (bytes == -1)
			return (perror("read"), NULL);
		else if (bytes == 0)
			break ;
		tmp = ft_strjoin(file, buf);
		if (!tmp)
			return (free(file), NULL);
		free(file);
		file = tmp;
		ft_bzero(buf, KB_4);
	}
	return (file);
}

t_file	*file_parse(char *file_name)
{
	t_file	*file;

	if (valid_file_name(file_name))
		return (NULL);
	file = ft_calloc(1, sizeof(t_file));
	if (file)
	{
		file->fd = open(file_name, O_RDONLY);
		if (file->fd == -1)
			return (perror("open"), free(file), NULL);
		file->content = read_file(file->fd);
		file->lines = ft_split(file->content, '\n');
		file->scene = scene_info(file->lines);
	}
	return (file);
}
