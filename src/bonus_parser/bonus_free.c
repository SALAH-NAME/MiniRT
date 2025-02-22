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
	t_light	*tmp;

	if (scene->lights)
	{
		while (scene->lights)
		{
			tmp = scene->lights->next;
			free(scene->lights);
			scene->lights = tmp;
		}
	}
	free_objects(scene->objects);
}

void	free_all(t_data *data)
{
	if (data)
	{
		if (data->file.split)
		{
			ft_arrmapi(data->file.split, free);
			free(data->file.split);
			data->file.split = NULL;
		}
		free_scene(&data->scene);
	}
}
