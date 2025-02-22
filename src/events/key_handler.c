/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:51:24 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/15 03:06:44 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	handle_keypress(int keycode, t_render *world)
{
	t_object	*obj;
	t_object	*selected;

	obj = world->scene.objects;
	while (obj)
		if (obj->type == OBJ_CONE)
			selected = obj;
	if (keycode == XK_Escape || keycode == XK_q)
	{
		mlx_loop_end(world->mlx.ptr);
		return (0);
	}
	if (keycode == XK_w || keycode == XK_W)
	{
		printf("Keycode: %d\n", keycode);
		world->scene.camera.position.z -= MOVE_SPEED;
		render_scene(world);
	}
	if (keycode == XK_s || keycode == XK_S)
	{
		world->scene.camera.position.z += MOVE_SPEED;
		render_scene(world);
	}
	if (keycode == XK_a || keycode == XK_A)
	{
		world->scene.camera.position.x -= MOVE_SPEED;
		render_scene(world);
	}
	if (keycode == XK_d || keycode == XK_D)
	{
		world->scene.camera.position.x += MOVE_SPEED;
		render_scene(world);
	}
	if (keycode == XK_Up)
	{
		world->scene.camera.position.y -= MOVE_SPEED;
		render_scene(world);
	}
	if (keycode == XK_Down)
	{
		world->scene.camera.position.y += MOVE_SPEED;
		render_scene(world);
	}
	if (keycode == 4)
	{
		world->scene.camera.orientation.x += MOVE_SPEED;
		render_scene(world);
	}
	if (keycode == XK_t || keycode == XK_T)
	{
		world->scene.is_raytrace = !world->scene.is_raytrace;
		render_scene(world);
	}
	if (keycode == XK_Left)
	{
		move_selected_up(selected, MOVE_SPEED);
		render_scene(world);
	}
	return (0);
}

// Add this new function
int	handle_mouse(int button, int x, int y, t_render *world)
{
	(void)x; // Unused parameters
	(void)y;
	if (button == 4) // Mouse wheel up
	{
		world->scene.camera.orientation.x += MOVE_SPEED;
		render_scene(world);
	}
	else if (button == 5) // Mouse wheel down
	{
		world->scene.camera.orientation.x -= MOVE_SPEED;
		render_scene(world);
	}
	return (0);
}

// int handle_mouse_move(int x, int y, t_render *world)
// {
//     static int steps = 0;
//     static int last_x = -1;
//     static int last_y = -1;
//     const double sensitivity = 0.05;
	// Adjust this value to change mouse sensitivity

//     if (last_x == -1)
//     {
//         last_x = x;
//         last_y = y;
//         return (0);
//     }

//     // Calculate the delta movement
//     int dx = x - last_x;
//     int dy = y - last_y;

//     // Update camera orientation
//     // Horizontal movement (left/right) affects X rotation
//     world->scene.camera.orientation.x += dx * sensitivity;
//     // Vertical movement (up/down) affects Y rotation
//     world->scene.camera.orientation.y -= dy * sensitivity;
	// Negative for intuitive up/down

//     // Clamp vertical rotation to prevent camera flipping
//     if (world->scene.camera.orientation.y > 89.0)
//         world->scene.camera.orientation.y = 89.0;
//     if (world->scene.camera.orientation.y < -89.0)
//         world->scene.camera.orientation.y = -89.0;

//     // Normalize horizontal rotation
//     while (world->scene.camera.orientation.x > 360.0)
//         world->scene.camera.orientation.x -= 360.0;
//     while (world->scene.camera.orientation.x < 0.0)
//         world->scene.camera.orientation.x += 360.0;

//     // Store current position for next frame
//     last_x = x;
//     last_y = y;

//     // Render less frequently to improve performance
//     if (steps++ % 5 == 0) // Reduced from 10 to 5 for better responsiveness
//         render_scene(world);

//     return (0);
// }
