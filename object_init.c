/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 11:02:56 by ysemlali          #+#    #+#             */
/*   Updated: 2024/12/31 11:02:56 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


t_Plane	*init_plane(char **info, int *plane_count)
{
	char	**point;
	char	**normals;
	char	**rgb;
	t_Plane	*plane;

	if (!valid(info, 3))
		return (NULL);
	*plane_count += 1;
	point = ft_split(info[0], ',');
	normals = ft_split(info[1], ',');
	rgb = ft_split(info[2], ',');
	plane = ft_calloc(1, sizeof(t_Plane));
	plane->point[0] = strtod(point[0], NULL);
	plane->point[1] = strtod(point[1], NULL);
	plane->point[2] = strtod(point[2], NULL);
	plane->normal[0] = strtod(normals[0], NULL);
	plane->normal[1] = strtod(normals[1], NULL);
	plane->normal[2] = strtod(normals[2], NULL);
	plane->color[0] = ft_atoi(rgb[0]);
	plane->color[1] = ft_atoi(rgb[1]);
	plane->color[2] = ft_atoi(rgb[2]);
	ft_arrmapi(point, free);
	ft_arrmapi(normals, free);
	ft_arrmapi(rgb, free);
	return (plane);
}

t_Sphere	*init_sphere(char **info, int *sphere_count)
{
	char		**center;
	char		**rgb;
	t_Sphere	*sphere;

	if (!valid(info, 3))
		return (NULL);
	*sphere_count += 1;
	center = ft_split(info[0], ',');
	rgb = ft_split(info[2], ',');
	sphere = ft_calloc(1, sizeof(t_Sphere));
	sphere->center[0] = strtod(center[0], NULL);
	sphere->center[1] = strtod(center[1], NULL);
	sphere->center[2] = strtod(center[2], NULL);
	sphere->diameter = strtod(info[1], NULL);
	sphere->color[0] = ft_atoi(rgb[0]);
	sphere->color[1] = ft_atoi(rgb[1]);
	sphere->color[2] = ft_atoi(rgb[2]);
	ft_arrmapi(center, free);
	ft_arrmapi(rgb, free);
	return (sphere);
}

void	init_rest(t_Cylinder *cylinder, char **info)
{
	char	**rgb;

	rgb = ft_split(info[4], ',');
	cylinder->diameter = strtod(info[2], NULL);
	cylinder->height = strtod(info[3], NULL);
	cylinder->color[0] = ft_atoi(rgb[0]);
	cylinder->color[1] = ft_atoi(rgb[1]);
	cylinder->color[2] = ft_atoi(rgb[2]);
	ft_arrmapi(rgb, free);
}

t_Cylinder	*init_cylinder(char **info, int *cylinder_count)
{
	char		**base;
	char		**axis;
	t_Cylinder	*cylinder;

	if (!valid(info, 5))
		return (NULL);
	*cylinder_count += 1;
	base = ft_split(info[0], ',');
	axis = ft_split(info[1], ',');
	cylinder = ft_calloc(1, sizeof(t_Cylinder));
	cylinder->base[0] = strtod(base[0], NULL);
	cylinder->base[1] = strtod(base[1], NULL);
	cylinder->base[2] = strtod(base[2], NULL);
	cylinder->axis[0] = strtod(axis[0], NULL);
	cylinder->axis[1] = strtod(axis[1], NULL);
	cylinder->axis[2] = strtod(axis[2], NULL);
	init_rest(cylinder, info);
	ft_arrmapi(base, free);
	ft_arrmapi(axis, free);
	return (cylinder);
}
