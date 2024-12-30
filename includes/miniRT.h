/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:13:37 by ysemlali          #+#    #+#             */
/*   Updated: 2024/12/30 12:13:38 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "scene_data.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define KB_4 4096
# define EXT ".rt"

typedef struct s_file
{
	char	*name;
	int		fd;
	char	*content;
	char	**lines;
	size_t	size;
	t_Scene	*scene;
}			t_file;

// parse and init
t_file		*file_parse(char *file_name);
void		free_all(t_file *file);
int			parse_ambient(char *ambient);
int			parse_light(char *light);
int			parse_camera(char *camera);
void		init_light(char **information, t_Light *light);
void		init_camera(char **information, t_Camera *camera);
void		init_ambient(char **information, t_AmbientLight *ambient);

#endif
