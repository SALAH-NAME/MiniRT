/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:49:38 by ysemlali          #+#    #+#             */
/*   Updated: 2024/12/30 20:21:14 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_ambient(char **information, t_AmbientLight *ambient)
{
	ambient = ft_calloc(1, sizeof(t_AmbientLight));
	ambient->ratio = strtod(*information, NULL);
	information++;
	ambient->color[0] = atoi(*information);
	*information += (ft_strchr(*information, ',') - *information) + 1;
	ambient->color[1] = atoi(*information);
	*information += (ft_strchr(*information, ',') - *information) + 1;
	ambient->color[2] = atoi(*information);
}

void	init_light(char **information, t_Light *light)
{
	light = ft_calloc(1, sizeof(t_Light));
	light->position[0] = strtod(*information, NULL);
	*information += (ft_strchr(*information, ',') - *information) + 1;
	light->position[1] = strtod(*information, NULL);
	*information += (ft_strchr(*information, ',') - *information) + 1;
	light->position[2] = strtod(*information, NULL);
	information++;
	light->brightness = strtod(*information, NULL);
	information++;
	light->color[0] = atoi(*information);
	*information += (ft_strchr(*information, ',') - *information) + 1;
	light->color[1] = atoi(*information);
	*information += (ft_strchr(*information, ',') - *information) + 1;
	light->color[2] = atoi(*information);
}

void	init_camera(char **information, t_Camera *camera)
{
	camera = ft_calloc(1, sizeof(t_Camera));
	camera->position[0] = strtod(*information, NULL);
	*information += (ft_strchr(*information, ',') - *information) + 1;
	camera->position[1] = strtod(*information, NULL);
	*information += (ft_strchr(*information, ',') - *information) + 1;
	camera->position[2] = strtod(*information, NULL);
	information++;
	camera->orientation[0] = strtod(*information, NULL);
	*information += (ft_strchr(*information, ',') - *information) + 1;
	camera->orientation[1] = strtod(*information, NULL);
	*information += (ft_strchr(*information, ',') - *information) + 1;
	camera->orientation[2] = strtod(*information, NULL);
	information++;
	camera->fov = ft_atoi(*information);
}

