/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:19:11 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/05 20:02:04 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct s_ambientlight
{
	double				ratio;
	int					color[3];
}						t_ambientlight;

typedef struct s_camera
{
	double				position[3];
	double				orientation[3];
	int					fov;
}						t_camera;

typedef struct s_light
{
	double				position[3];
	double				brightness;
	int					color[3];
}						t_light;

typedef struct s_sphere
{
	int					id;
	double				center[3];
	double				diameter;
	int					color[3];
	struct s_sphere		*next;
}						t_sphere;

typedef struct s_plane
{
	int					id;
	double				point[3];
	double				normal[3];
	int					color[3];
	struct s_plane		*next;
}						t_plane;

typedef struct s_cylinder
{
	int					id;
	double				base[3];
	double				axis[3];
	double				diameter;
	double				height;
	int					color[3];
	struct s_cylinder	*next;
}						t_cylinder;

typedef struct s_scene
{
	int					a_c;
	int					c_c;
	int					l_c;
	int					sp_c;
	int					cy_c;
	int					pl_c;
	t_ambientlight		*ambient;
	t_camera			*camera;
	t_light				*light;
	t_sphere			*spheres;
	t_plane				*planes;
	t_cylinder			*cylinders;
}						t_scene;

#endif
