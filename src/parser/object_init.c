/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:57:51 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/03 19:52:16 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

t_object	*get_lst_last(t_object *list)
{
	t_object	*current;

	current = list;
	if (!current)
		return (NULL);
	while (current->next)
		current = current->next;
	return (current);
}

void	pl_init(t_data *data)
{
	t_object	*new_object;

	if (data->file->error == 0)
		return ;
	if (!valid(data->file->row + 1, data->config->elements[3].v_count))
	{
		set_error(data, ERR_MS_VAL_PARAM, *data->file->row, NULL);
		return ;
	}
	new_object = ft_calloc(1, sizeof(t_object));
	new_object->id = data->scene->count.pl_c++;
	new_object->type = OBJ_PLANE;
	if (data->file->error)
		position_init(data, &new_object->data.plane.center, data->file->row[1]);
	if (data->file->error)
		vector_init(data, &new_object->data.plane.normal, data->file->row[2]);
	if (data->file->error)
		color_init(data, &new_object->material.color, data->file->row[3]);
	if (data->scene->objects == NULL)
		data->scene->objects = new_object;
	else
		get_lst_last(data->scene->objects)->next = new_object;
}

void	sp_init(t_data *data)
{
	t_object	*new_object;
	t_range		range;

	if (data->file->error == 0)
		return ;
	if (!valid(data->file->row + 1, data->config->elements[4].v_count))
	{
		set_error(data, ERR_MS_VAL_PARAM, *data->file->row, NULL);
		return ;
	}
	new_object = ft_calloc(1, sizeof(t_object));
	new_object->id = data->scene->count.sp_c++;
	new_object->type = OBJ_SPHERE;
	range = data->config->info[3].range;
	if (data->file->error)
		position_init(data, &new_object->data.sphere.center,
			data->file->row[1]);
	if (data->file->error)
		ratio_init(data, &new_object->data.sphere.radios, data->file->row[2],
			range);
	if (data->file->error)
		color_init(data, &new_object->material.color, data->file->row[3]);
	if (data->scene->objects == NULL)
		data->scene->objects = new_object;
	else
		get_lst_last(data->scene->objects)->next = new_object;
}

void	cy_init(t_data *data)
{
	t_object	*new_object;
	t_range		range;

	if (data->file->error == 0)
		return ;
	if (!valid(data->file->row + 1, data->config->elements[5].v_count))
	{
		set_error(data, ERR_MS_VAL_PARAM, *data->file->row, NULL);
		return ;
	}
	new_object = ft_calloc(1, sizeof(t_object));
	new_object->id = data->scene->count.cy_c++;
	new_object->type = OBJ_CYLINDER;
	range = data->config->info[3].range;
	if (data->file->error)
		position_init(data, &new_object->data.cylinder.center,
			data->file->row[1]);
	if (data->file->error)
		vector_init(data, &new_object->data.cylinder.normal,
			data->file->row[2]);
	if (data->file->error)
		ratio_init(data, &new_object->data.cylinder.radios, data->file->row[3],
			range);
	if (data->file->error)
		ratio_init(data, &new_object->data.cylinder.height, data->file->row[4],
			range);
	if (data->file->error)
		color_init(data, &new_object->material.color, data->file->row[5]);
	if (data->scene->objects == NULL)
		data->scene->objects = new_object;
	else
		get_lst_last(data->scene->objects)->next = new_object;
}
