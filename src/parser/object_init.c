/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:57:51 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/05 19:40:54 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	pl_init(t_data *data)
{
	t_plane	*new_plane;

	if (data->file->error == 0)
		return ;
	if (!valid(data->file->row + 1, data->config->elements[3].v_count))
	{
		set_error(data, ERR_MS_VAL_PARAM, *data->file->row, NULL);
		return ;
	}
	new_plane = ft_calloc(1, sizeof(t_plane));
	new_plane->id = data->scene->pl_c++;
	if (data->file->error)
		position_init(data, new_plane->point, data->file->row[1]);
	if (data->file->error)
		vector_init(data, new_plane->normal, data->file->row[2]);
	if (data->file->error)
		color_init(data, new_plane->color, data->file->row[3]);
	new_plane->next = data->scene->planes;
	data->scene->planes = new_plane;
}

void	sp_init(t_data *data)
{
	t_sphere	*new_sphere;
	t_range		range;

	if (data->file->error == 0)
		return ;
	if (!valid(data->file->row + 1, data->config->elements[4].v_count))
	{
		set_error(data, ERR_MS_VAL_PARAM, *data->file->row, NULL);
		return ;
	}
	new_sphere = ft_calloc(1, sizeof(t_sphere));
	new_sphere->id = data->scene->sp_c++;
	range = data->config->info[3].range;
	if (data->file->error)
		position_init(data, new_sphere->center, data->file->row[1]);
	if (data->file->error)
		ratio_init(data, &new_sphere->diameter, data->file->row[2], range);
	if (data->file->error)
		color_init(data, new_sphere->color, data->file->row[3]);
	new_sphere->next = data->scene->spheres;
	data->scene->spheres = new_sphere;
}

void	cy_init(t_data *data)
{
	t_cylinder	*new_cylinder;
	t_range		range;

	if (data->file->error == 0)
		return ;
	if (!valid(data->file->row + 1, data->config->elements[5].v_count))
	{
		set_error(data, ERR_MS_VAL_PARAM, *data->file->row, NULL);
		return ;
	}
	new_cylinder = ft_calloc(1, sizeof(t_cylinder));
	new_cylinder->id = data->scene->cy_c++;
	range = data->config->info[3].range;
	if (data->file->error)
		position_init(data, new_cylinder->base, data->file->row[1]);
	if (data->file->error)
		vector_init(data, new_cylinder->axis, data->file->row[2]);
	if (data->file->error)
		ratio_init(data, &new_cylinder->diameter, data->file->row[3], range);
	if (data->file->error)
		ratio_init(data, &new_cylinder->height, data->file->row[4], range);
	if (data->file->error)
		color_init(data, new_cylinder->color, data->file->row[5]);
	new_cylinder->next = data->scene->cylinders;
	data->scene->cylinders = new_cylinder;
}
