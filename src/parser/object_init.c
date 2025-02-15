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

static t_object	*get_lst_last(t_object *list)
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
	t_object	*obj;

	if (data->file.error == 0)
		return ;
	if (!valid(data->file.row + 1, data->config.elements[3].v_count))
	{
		set_error(data, ERR_MS_VAL_PARAM, *data->file.row, NULL);
		return ;
	}
	obj = ft_calloc(1, sizeof(t_object));
	obj->id = data->scene.count.pl_c++;
	obj->type = OBJ_PLANE;
	position_init(data, &obj->data.plane.center, data->file.row[1]);
	vector_init(data, &obj->data.plane.normal, data->file.row[2]);
	color_init(data, &obj->material.color, data->file.row[3]);
	if (data->scene.objects == NULL)
		data->scene.objects = obj;
	else
		get_lst_last(data->scene.objects)->next = obj;
}

void	sp_init(t_data *data)
{
	t_object	*obj;

	if (data->file.error == 0)
		return ;
	if (!valid(data->file.row + 1, data->config.elements[4].v_count))
	{
		set_error(data, ERR_MS_VAL_PARAM, *data->file.row, NULL);
		return ;
	}
	obj = ft_calloc(1, sizeof(t_object));
	obj->id = data->scene.count.sp_c++;
	obj->type = OBJ_SPHERE;
	position_init(data, &obj->data.sphere.center, data->file.row[1]);
	radius_init(data, &obj->data.sphere.radius, data->file.row[2]);
	color_init(data, &obj->material.color, data->file.row[3]);
	if (data->scene.objects == NULL)
		data->scene.objects = obj;
	else
		get_lst_last(data->scene.objects)->next = obj;
}

void	cy_init(t_data *data)
{
	t_object	*obj;
	t_range		range;

	if (data->file.error == 0)
		return ;
	if (!valid(data->file.row + 1, data->config.elements[5].v_count))
	{
		set_error(data, ERR_MS_VAL_PARAM, *data->file.row, NULL);
		return ;
	}
	obj = ft_calloc(1, sizeof(t_object));
	obj->id = data->scene.count.cy_c++;
	obj->type = OBJ_CYLINDER;
	range = data->config.info[DOUBLE].range;
	position_init(data, &obj->data.cylinder.center, data->file.row[1]);
	vector_init(data, &obj->data.cylinder.normal, data->file.row[2]);
	radius_init(data, &obj->data.cylinder.radius, data->file.row[3]);
	ratio_init(data, &obj->data.cylinder.height, data->file.row[4], range);
	color_init(data, &obj->material.color, data->file.row[5]);
	if (data->scene.objects == NULL)
		data->scene.objects = obj;
	else
		get_lst_last(data->scene.objects)->next = obj;
}
