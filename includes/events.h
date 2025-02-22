/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 03:11:27 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/22 06:53:58 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "minirt.h"
# include <X11/keysym.h>
# include <stdio.h>

# define SPEED 0.1

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

typedef enum e_direction
{
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT,
    DIR_FORWARD,
    DIR_BACKWARD
}   t_direction;

typedef enum e_mode
{
    MODE_NONE,
    MODE_OBJECT_MOVE,
    MODE_OBJECT_ROTATE,
    MODE_CAMERA_MOVE,
    MODE_CAMERA_ROTATE
}   t_mode;

// Key handlers
int     handle_keypress(int keycode, t_render *world);
int     close_window(t_render *render);

// Object transformation
void    object_movement(int keycode, t_object *objects, t_render *world);
void    object_rotation(int keycode, t_object *objects, t_render *world);
void    move_direction(t_object *object, int direction, double speed);
void    object_selection(int keycode, t_object *objects, t_object **selected);

// Camera transformation
void    camera_movement(int keycode, t_camera *camera, t_render *world);
void    camera_rotation(int keycode, t_camera *camera, t_render *world);

// Utils
void    print_mode(int mode, int *last_mode);
void    print_selected_object(t_object *object);
t_vec3  *get_object_position(t_object *object);
t_object *switch_objects(t_object *objects);
void render_scene_on_change(int  keycode , t_render *world);
#endif
