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

t_AmbientLight	*init_ambient(char **info, t_AmbientLight *ambient)
{
  if(!valid(info,2))
    return(NULL);
	char	**colors;

	colors = ft_split(info[1], ',');
	ambient = ft_calloc(1, sizeof(t_AmbientLight));
	ambient->ratio = strtod(info[0], NULL);
	ambient->color[0] = ft_atoi(colors[0]);
	ambient->color[1] = ft_atoi(colors[1]);
	ambient->color[2] = ft_atoi(colors[2]);
	ft_arrmapi(colors, free);
	return (ambient);
}

t_Light	*init_light(char **info, t_Light *light)
{
  if(!valid(info,3))
    return(NULL);
	char	**positions;
	char	**colors;

	positions = ft_split(info[0], ',');
	colors = ft_split(info[2], ',');
	light = ft_calloc(1, sizeof(t_Light));
	light->position[0] = strtod(positions[0], NULL);
	light->position[1] = strtod(positions[1], NULL);
	light->position[2] = strtod(positions[2], NULL);
	light->brightness = strtod(info[1], NULL);
	light->color[0] = ft_atoi(colors[0]);
	light->color[1] = ft_atoi(colors[0]);
	light->color[2] = ft_atoi(colors[0]);
	ft_arrmapi(positions, free);
	ft_arrmapi(colors, free);
	return (light);
}

t_Camera	*init_camera(char **info, t_Camera *camera)
{
  if(!valid(info,3))
    return(NULL);
	char	**positions;
	char	**orientations;

	positions = ft_split(info[0], ',');
	orientations = ft_split(info[1], ',');
	camera = ft_calloc(1, sizeof(t_Camera));
	camera->position[0] = strtod(positions[0], NULL);
	camera->position[1] = strtod(positions[1], NULL);
	camera->position[2] = strtod(positions[2], NULL);
	camera->orientation[0] = strtod(orientations[0], NULL);
	camera->orientation[1] = strtod(orientations[1], NULL);
	camera->orientation[2] = strtod(orientations[2], NULL);
	camera->fov = ft_atoi(info[2]);
	ft_arrmapi(positions, free);
	ft_arrmapi(orientations, free);
	return (camera);
}

int	init_acl(char **info, t_Scene **scene, char type)
{
  if(!info || !*info)
    return(-1);
	if (type == 'A' && (*scene)->ambient == NULL)
		return ((*scene)->ambient = init_ambient(info, (*scene)->ambient), 0);
	else if (type == 'L' && (*scene)->light == NULL)
		return ((*scene)->light = init_light(info, (*scene)->light), 0);
	else if (type == 'C' && (*scene)->camera == NULL)
		return ((*scene)->camera = init_camera(info, (*scene)->camera), 0);
	return (1);
}
