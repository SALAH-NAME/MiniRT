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
# include "scene.h"
# include <X11/keysym.h>
# include <stdio.h>

# define SPEED .2

typedef enum {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT,
    DIR_FORWARD,
    DIR_BACKWARD,
} t_event_dirction;

// Mode Macros
typedef enum {
    MODE_NONE,
    MODE_OBJECT_MOVE,
    MODE_OBJECT_ROTATE,
    MODE_CAMERA_MOVE,
    MODE_CAMERA_ROTATE,
} t_event_mode;

// Key handler prototypes
int		handle_keypress(int keycode, t_render *world);
int		close_window(t_render *render);

// Scene transformation prototypes
void    object_movement(int keycode, t_object *objects, t_render *world);
void	object_rotation(int keycode, t_object *objects);
void	camera_movement(int keycode, t_camera camera);
void	camera_rotation(int keycode, t_camera camera);

#endif
