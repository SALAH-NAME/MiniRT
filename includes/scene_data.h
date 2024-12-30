/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:32:37 by ysemlali          #+#    #+#             */
/*   Updated: 2024/12/30 14:32:37 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_DATA_H
# define SCENE_DATA_H

# include "miniRT.h"

typedef struct AmbientLight
{
	double			ratio;
	int				color[3];
}					t_AmbientLight;

typedef struct Camera
{
	double			position[3];
	double			orientation[3];
	int				fov;
}					t_Camera;

typedef struct Light
{
	double			position[3];
	double			brightness;
	int				color[3];
}					t_Light;

typedef struct Sphere
{
	double			center[3];
	double			diameter;
	int				color[3];
}					t_Sphere;

typedef struct Plane
{
	double			point[3];
	double			normal[3];
	int				color[3];
}					t_Plane;

typedef struct Cylinder
{
	double			base[3];
	double			orientation[3];
	double			diameter;
	double			height;
	int				color[3];
}					t_Cylinder;

typedef struct Scene
{
	t_AmbientLight	*ambient;
	t_Camera		*camera;
	t_Light			*light;
	int				light_count;
	t_Sphere		*spheres;
	int				sphere_count;
	t_Plane			*planes;
	int				plane_count;
	t_Cylinder		*cylinders;
	int				cylinder_count;
}					t_Scene;

#endif
