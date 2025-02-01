/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:19:11 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/01 12:34:12 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "algebra.h"

typedef struct s_color
{
	float			r;
	float			g;
	float			b;
}					t_color;


typedef struct s_material
{
	t_color				color;
	double			diffuse_coefficient;
	double			specular_coefficient;
	double			shininess;
}					t_material;

typedef struct s_ambientlight
{

	int 			id;
	double				ratio;
  t_color       color;
}						t_ambientlight;

typedef struct s_camera
{
	int 			id;
	t_vec3				position;
	t_vec3				orientation;
	int					fov;
}						t_camera;

typedef struct s_light
{
	int 			id;
	t_vec3				position;
	double				brightness;
  t_color         color;
  t_light         *next;
}						t_light;

typedef struct s_sphere
{
	int 			id;
	t_vec3				center;
	double				radios;
	t_material			material;
	struct s_sphere		*next;
}						t_sphere;

typedef struct s_plane
{
	int 			id;
	t_vec3				center;
	t_vec3				normal;
	t_material		material;
	struct s_plane		*next;
}						t_plane;

typedef struct s_cylinder
{
	int 			id;
	t_vec3				center;
	t_vec3				normal;
	double				radios;
	double				height;
	t_material		material;
	struct s_cylinder	*next;
}						t_cylinder;


typedef struct s_cone
{
	int 			id;
	t_vec3			center;
	double			angle;
	double			height;
	t_material		material;
}					t_cone;


typedef struct s_count
{
	int					a_c;
	int					c_c;
	int					l_c;
	int					sp_c;
	int					cy_c;
	int					pl_c;
} t_count;

typedef struct s_scene
{
	t_ambientlight		*ambient;
	t_camera			*camera;
	t_light				*light;
	t_sphere			*spheres;
	t_plane				*planes;
	t_cylinder			*cylinders;
	t_count				count;
}						t_scene;

#endif
