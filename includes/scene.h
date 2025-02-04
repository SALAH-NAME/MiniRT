/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:19:11 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/03 20:14:27 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "algebra.h"

typedef struct s_color
{
	float				r;
	float				g;
	float				b;
}						t_color;

typedef struct s_transform
{
	t_vec3				position;
	t_vec3				rotation;
}						t_transform;

typedef struct s_ambientlight
{
	int					id;
	double				ratio;
	t_color				color;
}						t_ambientlight;

typedef struct s_camera
{
	int					id;
	t_vec3				position;
	t_vec3				orientation;
	int					fov;
}						t_camera;

typedef struct s_lights
{
	int					id;
	t_vec3				position;
	double				brightness;
	t_color				color;
	struct s_lights		*next;
}						t_lights;

typedef struct s_sphere
{
	t_vec3				center;
	double				radius;
	struct s_sphere		*next;
}						t_sphere;

typedef struct s_plane
{
	t_vec3				center;
	t_vec3				normal;
	struct s_plane		*next;
}						t_plane;

typedef struct s_cylinder
{
	t_vec3				center;
	t_vec3				normal;
	double				radius;
	double				height;
	struct s_cylinder	*next;
}						t_cylinder;

typedef struct s_cone
{
	t_vec3				center;
	double				angle;
	double				height;
}						t_cone;

typedef struct s_count
{
	int					a_c;
	int					c_c;
	int					l_c;
	int					sp_c;
	int					cy_c;
	int					pl_c;
}						t_count;

typedef enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	// OBJ_CONE,
	// OBJ_HYPERBOLOID,
	// OBJ_PARABOLOID
}						t_object_type;

typedef struct s_material
{
	t_color				color;
	double				diffuse_coefficient;
	double				specular_coefficient;
	double				shininess;
}						t_material;

typedef struct s_object
{
	t_object_type		type;
	t_transform			transform;
	t_material			material;
	union				u_object
	{
		t_sphere		sphere;
		t_plane			plane;
		t_cylinder		cylinder;
		t_cone			cone;
	} data;
	struct s_object		*next;
	int					id;
}						t_object;

typedef struct s_scene
{
	t_ambientlight		ambient;
	t_camera			camera;
	t_lights			*lights;

	t_object			*objects;
	t_lights			*selected_light;
	t_object			*selected_obj;
	t_count				count;
}						t_scene;

#endif
