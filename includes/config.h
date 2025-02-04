/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:52:30 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/01 11:51:29 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

typedef struct s_data	t_data;

# define UN -1 // for undefined values or unused values
# define EPSILON 1e-6

enum					e_obj
{
	AMBIENT,
	CAMERA,
	LIGHT,
	PLANE,
	SPHERE,
	CYLINDER,
};

enum					e_elem
{
	RATIO,
	AXIS,
	COLOR,
	DOUBLE,
	VECTOR,
	ID,
	NONE,
};

typedef struct s_range
{
	double				d_r[2];
	int					i_r[2];

}						t_range;

typedef void			(*t_init_func)(t_data *data);
typedef struct s_elems
{
	const char			*name;
	int					elem_type;
	int					max_count;
	int					v_count;
	t_init_func			init_func;
}						t_elems;

typedef struct s_info
{
	const char			*name;
	int					type;
	t_range				range;
	const char			*hint;
}						t_info;

typedef struct s_config
{
	int					res[2];
	const t_elems		*elements;
	const t_info		*info;
}						t_config;

int						parse_config_init(t_data *data);
#endif
