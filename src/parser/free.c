/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:04:45 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/05 19:40:54 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	free_spheres(t_sphere *spheres)
{
	t_sphere	*tmp;

	while (spheres)
	{
		tmp = spheres->next;
		free(spheres);
		spheres = tmp;
	}
}

void	free_planes(t_plane *planes)
{
	t_plane	*tmp;

	while (planes)
	{
		tmp = planes->next;
		free(planes);
		planes = tmp;
	}
}

void	free_cylinders(t_cylinder *cylinders)
{
	t_cylinder	*tmp;

	while (cylinders)
	{
		tmp = cylinders->next;
		free(cylinders);
		cylinders = tmp;
	}
}

void	free_scene(t_scene *scene)
{
	if (scene->ambient)
		free(scene->ambient);
	if (scene->light)
		free(scene->light);
	if (scene->camera)
		free(scene->camera);
	free_spheres(scene->spheres);
	free_planes(scene->planes);
	free_cylinders(scene->cylinders);
}

void	free_all(t_data *data)
{
	if (data)
	{
		if (data->config)
			free(data->config);
		if (data->file)
		{
			if (data->file->split)
			{
				ft_arrmapi(data->file->split, free);
				free(data->file->split);
				data->file->split = NULL;
			}
			free(data->file);
		}
		if (data->scene)
		{
			free_scene(data->scene);
			free(data->scene);
		}
		free(data);
	}
}
