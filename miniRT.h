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

# include "libft/libft.h"
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
  t_Scene *scene;
}			t_file;

// parse
t_file		*file_parse(char *file_name);
void		free_all(t_file *file);

#endif
