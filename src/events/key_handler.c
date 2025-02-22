/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:51:24 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/22 06:54:55 ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int	close_window(t_render *render)
{
	mlx_loop_end(render->mlx.ptr);
	return (0);
}


static t_object *switch_objects(t_object *objects)
{
    static t_object *current = NULL;
    
    if (!objects)
        return NULL;
    
    if (!current)
        current = objects; 
    else if (current->next)
        current = current->next;
    else
        current = objects; 
    return current;
}

static t_vec3 *get_object_position(t_object *object)
{
    if (!object)
        return NULL;
    if(object->type == OBJ_SPHERE)
        return &object->data.sphere.center;
    if(object->type == OBJ_PLANE)
        return &object->data.plane.center;
    if(object->type == OBJ_CYLINDER)
        return &object->data.cylinder.center;
    if(object->type == OBJ_CONE)
        return &object->data.cone.center;   
    return NULL;
}

void move_direction(t_object *object, int direction, double speed)
{
    if (!object)
        return;

    t_vec3 *position = get_object_position(object);

    if (!position)
        return;

    if (direction == DIR_UP)
        position->y += speed;
    if (direction == DIR_DOWN)
        position->y -= speed;
    if(direction == DIR_LEFT)
        position->x -= speed;
    if(direction == DIR_RIGHT)
        position->x += speed;
    if(direction == DIR_FORWARD)
        position->z -= speed;
    if(direction == DIR_BACKWARD)
        position->z += speed;
}

void object_movement(int keycode, t_object *objects, t_render *world)
{
  static t_object *selected = NULL;

  if(keycode == XK_Tab)
  {
    printf("Switching object\n");
    selected = switch_objects(objects);
  }

  if (keycode == XK_w)
    move_direction(selected, DIR_FORWARD, SPEED);
  else if (keycode == XK_s)
    move_direction(selected, DIR_BACKWARD, SPEED);
  else if (keycode == XK_a)
    move_direction(selected, DIR_LEFT, SPEED);
  else if (keycode == XK_d)
    move_direction(selected, DIR_RIGHT, SPEED);
  else if( keycode  == XK_Up)
    move_direction(selected, DIR_UP, SPEED);
  else if( keycode  == XK_Down)
    move_direction(selected, DIR_DOWN, SPEED);
  render_scene(world);
}

void object_rotation(int keycode, t_object *objects)
{
  (void)objects;
    if (keycode == XK_w)
        printf("Rotate up\n");
    else if (keycode == XK_s)
        printf("Rotate down\n");
    else if (keycode == XK_a)
        printf("Rotate left\n");
    else if (keycode == XK_d)
        printf("Rotate right\n");
}

void camera_movement(int keycode, t_camera camera)
{
  (void)camera;
    if (keycode == XK_w)
        printf("Move camera forward\n");
    else if (keycode == XK_s)
        printf("Move camera backward\n");
    else if (keycode == XK_a)
        printf("Move camera left\n");
    else if (keycode == XK_d)
        printf("Move camera right\n");
}

void camera_rotation(int keycode, t_camera camera)
{
  (void)camera;
    if (keycode == XK_w)
        printf("Tilt up\n");
    else if (keycode == XK_s)
        printf("Tilt down\n");
    else if (keycode == XK_a)
        printf("Pan left\n");
    else if (keycode == XK_d)
        printf("Pan right\n");
}




void print_mode(int mode, int *last_mode)
{
    if (mode != *last_mode)
    {
        if (*last_mode != MODE_NONE)
            printf("Exiting mode %d\n", *last_mode);
        printf("Entering mode %d\n", mode);
        *last_mode = mode;
    }
}


int	handle_keypress(int keycode, t_render *world)
{
	static int current_mode = MODE_NONE;
    static int last_mode = MODE_NONE;
	if (keycode == XK_Escape || keycode == XK_q)
	{
		mlx_loop_end(world->mlx.ptr);
		return (0);
	}
	if (keycode == XK_1)
    {
		current_mode = MODE_OBJECT_MOVE;
        print_mode(current_mode, &last_mode);
    }
	else if (keycode == XK_2) 
    {
		current_mode = MODE_OBJECT_ROTATE;
        print_mode(current_mode, &last_mode);
    }
	else if (keycode == XK_3) 
    {
		current_mode = MODE_CAMERA_MOVE;
        print_mode(current_mode, &last_mode);
    }
	else if (keycode == XK_4) 
    {
		current_mode = MODE_CAMERA_ROTATE;
        print_mode(current_mode, &last_mode);
    }

	if (current_mode == MODE_OBJECT_MOVE)
		object_movement(keycode, world->scene.objects, world);
	else if (current_mode == MODE_OBJECT_ROTATE)
		object_rotation(keycode, world->scene.objects);
	else if (current_mode == MODE_CAMERA_MOVE)
		camera_movement(keycode, world->scene.camera);
	else if (current_mode == MODE_CAMERA_ROTATE)
		camera_rotation(keycode, world->scene.camera);
	return (0);
}
