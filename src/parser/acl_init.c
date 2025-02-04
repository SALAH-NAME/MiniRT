/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:31:42 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/01 12:21:50 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	a_init(t_data *data)
{
	t_range	range;

	if (!valid(data->file->row + 1, data->config->elements[AMBIENT].v_count))
	{
		set_error(data, ERR_MS_VAL_PARAM, *data->file->row, NULL);
		return ;
	}
	range = data->config->info[0].range;
	data->scene.count.a_c++;
	if (data->file->error)
		ratio_init(data, &data->scene.ambient.ratio, data->file->row[1], range);
	if (data->file->error)
		color_init(data, &data->scene.ambient.color, data->file->row[2]);
}

void	l_init(t_data *data)
{
	t_range	range;
	t_light	*light;

	if (!valid(data->file->row + 1, data->config->elements[LIGHT].v_count))
	{
		set_error(data, ERR_MS_VAL_PARAM, *data->file->row, NULL);
		return ;
	}
	light = ft_calloc(1, sizeof(t_light));
	range = data->config->info[0].range;
	data->scene.count.l_c++;
	if (data->file->error)
		position_init(data, &light->position, data->file->row[1]);
	if (data->file->error)
		ratio_init(data, &light->brightness, data->file->row[2], range);
	if (data->file->error)
		color_init(data, &light->color, data->file->row[3]);
	light->next = data->scene.lights;
	data->scene.lights = light;
}

void	c_init(t_data *data)
{
	if (!valid(data->file->row + 1, data->config->elements[CAMERA].v_count))
	{
		set_error(data, ERR_MS_VAL_PARAM, *data->file->row, NULL);
		return ;
	}
	data->scene.count.c_c++;
	if (data->file->error)
		position_init(data, &data->scene.camera.position, data->file->row[1]);
	if (data->file->error)
		vector_init(data, &data->scene.camera.orientation, data->file->row[2]);
	if (data->file->error)
		degree_init(data, &data->scene.camera.fov, data->file->row[3]);
}
