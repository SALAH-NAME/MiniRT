/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:44:07 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/28 18:52:46 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "algebra.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdlib.h>

# define WIDTH 1080
# define HEIGHT 1920
# define EPSILON 1e-6

typedef struct s_color
{
	float			r;
	float			g;
	float			b;
}					t_color;

typedef struct s_ambient
{
	double			itensity;
	t_color			color;
}					t_ambient;

typedef struct s_material
{
	t_color			color;
	// double ambient_coefficient;
	double			diffuse_coefficient;
	double			specular_coefficient;
	double			shininess;
	// int is_checkerboard;
}					t_material;

typedef struct s_ray
{
	t_vec3			origin;
	t_vec3			direction;
}					t_ray;

typedef enum e_object_type
{
	OBJ_SPHERE,
	OBJ_PLANE,
	OBJ_CYLINDER,
	OBJ_CONE,
	OBJ_HYPERBOLOID,
	OBJ_PARABOLOID
}					t_object_type;

typedef struct s_sphere
{
	t_vec3			center;
	double			radius;
	t_material		material;
}					t_sphere;

typedef struct s_plane
{
	t_vec3			center;
	t_vec3			normal;
	t_material		material;
}					t_plane;

typedef struct s_cylinder
{
	t_vec3			center;
	t_vec3			normal;
	double			diameter;
	double			height;
	t_material		material;
}					t_cylinder;

typedef struct s_cone
{
	t_vec3			center;
	t_material		material;
	double			angle;
	double			height;
}					t_cone;

typedef struct s_transform
{
	t_vec3			position;
	t_vec3			rotation;
	// ...
}					t_transform;

typedef struct s_object
{
	t_object_type	type;
	t_transform		transform;
	t_material		material;
	union			u_object
	{
		t_sphere	sphere;
		t_plane		plane;
		t_cylinder	cylinder;
		t_cone		cone;
	} data;
	struct s_object	*next;
	int				id;
}					t_object;

typedef struct s_camera
{
	t_vec3			position;
	t_vec3			direction;
	double			fov;
}					t_camera;

typedef struct s_light
{
	t_vec3			position;
	t_vec3			itensity;
	t_color			color;
	struct s_light	*next;
}					t_light;

typedef struct s_hit
{
	bool			hit;
	double			t;
	t_vec3			point;
	t_vec3			normal;
	t_vec3			view_dir;
	t_material		material;
	t_object		*object;
}					t_hit;

typedef struct s_scene
{
	t_camera		camera;
	t_ambient		ambient;
	t_light			*lights;
	t_light			*selected_light;
	t_object		*objects;
	t_object		*selected_obj;
}					t_scene;

typedef struct s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_mlx;

typedef struct s_render
{
	t_mlx			mlx;
	t_scene			scene;
}					t_render;

int					handle_keypress(int keysym, t_render *world);
int					handle_close(t_render *world);

t_color				color_create(float r, float g, float b);
t_color				color_multiply(t_color color, double t);
t_material			material_create(t_color color, double diffuse,
						double specular, double shininess);

void				init_scene(t_render *render);
void				render_scene(t_render *render);
t_ray				ray_create(t_vec3 origin, t_vec3 direction);
t_color				calculate_lighting(t_scene *scene, t_hit hit);
t_hit				find_nearest_intersection(t_ray ray, t_scene *scene);

#endif
