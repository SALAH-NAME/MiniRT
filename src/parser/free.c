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

void	free_objects(t_object *objects)
{
	t_object	*tmp;

	while (objects)
	{
		tmp = objects->next;
		free(objects);
		objects = tmp;
	}
}

void	free_scene(t_scene *scene)
{
	if (scene->lights)
		free(scene->lights);
	free_objects(scene->objects);
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
