/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 03:09:17 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/15 03:09:21 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stddef.h>

typedef struct s_data	t_data;
typedef struct s_range	t_range;

typedef struct s_file
{
	char				*file_name;
	int					fd;
	char				*line;
	size_t				line_index;
	char				**row;
	char				**split;
	int					error;
}						t_file;

// parse and init
bool					parse_scene(t_render *render, char *file_name);
// obj-init
void					a_init(t_data *data);
void					l_init(t_data *data);
void					c_init(t_data *data);
void					cy_init(t_data *data);
void					pl_init(t_data *data);
void					sp_init(t_data *data);
void					cn_init(t_data *data);
void					comment(t_data *data);
// info-init
void					color_init(t_data *data, t_color *color, char *val);
void					ratio_init(t_data *data, double *ratio, char *line,
							t_range range);
void					position_init(t_data *data, t_vec3 *pos, char *val);
void					vector_init(t_data *data, t_vec3 *vector, char *val);
void					degree_init(t_data *data, int *degree, char *val);
void					radius_init(t_data *data, double *radius, char *val);
void					spec_init(t_data *data, double *ratio, char *val);
void					angle_init(t_data *data, double *angle, char *val);

// utils
int						valid(char **info, int count);
void					free_all(t_data *file);
int						float_valid(char *val);
int						int_valid(char *val);
int						comma_count(char *val);
t_color					color_normalize(t_color vec);

// testing utils
void					set_error(t_data *data, char *desc, char *pr,
							char *hint);
void					free_scene(t_scene *scene);
void					free_all(t_data *file);
void					init_scene(t_render *render);

#endif
