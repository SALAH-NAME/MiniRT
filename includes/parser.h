/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:42:49 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/01 12:14:09 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "core.h"
# include "scene.h"

typedef struct s_file
{
	char	*file_name;
	int		fd;
	char	*line;
	size_t	line_index;
	char	**row;
	char	**split;
	int		error;
}			t_file;

// parse and init
int	parse_scene(t_render *render, char *file_name);
int			load_file(t_data *data, char *file_name);
int			valid_file_name(char *file_name);
// obj-init
void		a_init(t_data *data);
void		l_init(t_data *data);
void		c_init(t_data *data);
void		cy_init(t_data *data);
void		pl_init(t_data *data);
void		sp_init(t_data *data);
// info-init
void		color_init(t_data *data, t_color *color, char *val);
void		ratio_init(t_data *data, double *ratio, char *line, t_range range);
void		position_init(t_data *data, t_vec3 *pos, char *val);
void		vector_init(t_data *data, t_vec3 *vector, char *val);
void		degree_init(t_data *data, int *degree, char *val);
void		radius_init(t_data *data, double *radius, char *val);

// utils
int			valid(char **info, int count);
void		free_all(t_data *file);
int			float_valid(char *val);
int			int_valid(char *val);
int			comma_count(char *val);
t_color		color_normalize(t_color vec);

// testing utils
void		set_error(t_data *data, char *desc, char *pr, char *hint);

#endif
