/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:33:11 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/15 01:07:27 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "algebra.h"
# include "config.h"
# include "error.h"
# include "libft.h"
# include "minirt.h"
# include "parser.h"
# include "scene.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

# define KB_4 4096
# define EXT ".rt"

typedef struct s_data
{
	t_file		file;
	t_scene		scene;
	t_error		error;
	t_render	*render;
	t_config	config;
}				t_data;

// testing utils
void			print_scene(t_scene *scene);
void  	free_scene(t_scene *scene);
void			free_all(t_data *file);

#endif
