/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 14:37:02 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/22 14:37:02 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	camera_movement(int keycode, t_camera *camera, t_render *world)
{
	if (keycode == XK_w)
		camera->position.z -= MV_SPEED;
	else if (keycode == XK_s)
		camera->position.z += MV_SPEED;
	else if (keycode == XK_a)
		camera->position.x -= MV_SPEED;
	else if (keycode == XK_d)
		camera->position.x += MV_SPEED;
	else if (keycode == XK_Up)
		camera->position.y += MV_SPEED;
	else if (keycode == XK_Down)
		camera->position.y -= MV_SPEED;
	render_scene_on_change(keycode, world);
}

void	camera_rotation(int keycode, t_camera *camera, t_render *world)
{
	if (keycode == XK_w)
		camera->orientation.z -= RT_SPEED;
	else if (keycode == XK_s)
		camera->orientation.z += RT_SPEED;
	else if (keycode == XK_a)
		camera->orientation.y += RT_SPEED;
	else if (keycode == XK_d)
		camera->orientation.y -= RT_SPEED;
	else if (keycode == XK_Up)
		camera->orientation.x += RT_SPEED;
	else if (keycode == XK_Down)
		camera->orientation.x -= RT_SPEED;
	render_scene_on_change(keycode, world);
}
