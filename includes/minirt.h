/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:44:07 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/03 20:12:06 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "algebra.h"
# include "scene.h"
# include <mlx.h>
# include <stdbool.h>


# define WIDTH 480
# define HEIGHT 560

typedef struct s_ray
{
	t_vec3		origin;
	t_vec3		direction;
}				t_ray;

typedef struct s_hit
{
	bool		hit;
	double		t;
	t_vec3		point;
	t_vec3		normal;
	t_vec3		view_dir;
	t_material	material;
	t_object	*object;
}				t_hit;

typedef struct s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct s_render
{
	t_mlx		mlx;
	t_scene		scene;
}				t_render;

typedef bool	(*t_intersect_fn)(t_ray ray, t_object *obj, t_hit *hit);

int				handle_keypress(int keysym, t_render *world);
int				handle_close(t_render *world);

t_color			color_create(float r, float g, float b);
t_color			color_multiply(t_color color, double t);
t_material		material_create(t_color color, double diffuse, double specular, double shininess);
void			init_scene(t_render *render);
void			render_scene(t_render *render);

t_color			calculate_lighting(t_hit *hit, t_scene *scene);
bool			solve_quadratic(double a, double b, double c, double *t);
bool			ray_sphere_intersect(t_ray ray, t_object *obj, t_hit *hit);
bool 			ray_plane_intersect(t_ray ray, t_object *obj, t_hit *hit);
bool 			ray_cylinder_intersect(t_ray ray, t_object *obj, t_hit *hit);
bool			find_nearest_intersection(t_ray ray, t_scene *scene,
					t_hit *hit);
t_color			ray_intersection_shading(t_ray ray, t_scene *scene);
t_intersect_fn	get_intersection_function(t_object_type type);
bool			is_in_shadow(t_vec3 point, t_vec3 light_pos, t_scene *scene,
					t_object *current_obj);
t_color			get_checker_color(t_hit *hit);
t_vec3			perturb_normal(t_vec3 normal, t_vec3 point, t_bump_map *bump);
#endif
