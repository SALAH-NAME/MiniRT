/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:51:24 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/15 02:13:59 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
# include <stdio.h>
# include "parser.h"

#define MOVE_SPEED 1.0

int    handle_keypress(int keycode, t_render *world)
{
    if (keycode == XK_Escape || keycode == XK_q)
    {
        mlx_loop_end(world->mlx.ptr);
        return (0);
    }

    // WASD controls for X-Z plane movement
    if (keycode == XK_w || keycode == XK_W)
    {
        move_selected_forward(&world->scene, MOVE_SPEED);
        print_scene(&world->scene);
    }
    else if (keycode == XK_s || keycode == XK_S)
    {
        move_selected_forward(&world->scene, -MOVE_SPEED);
        print_scene(&world->scene);
    }
    else if (keycode == XK_a || keycode == XK_A)
    {
        move_selected_right(&world->scene, -MOVE_SPEED);
        print_scene(&world->scene);
    }
    else if (keycode == XK_d || keycode == XK_D)
    {
        move_selected_right(&world->scene, MOVE_SPEED);
        print_scene(&world->scene);
    }
    return (0);
}

int	handle_close(t_render *world)
{
    mlx_loop_end(world->mlx.ptr);
    return (0);
}
