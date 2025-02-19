/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 03:11:27 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/15 03:11:27 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "minirt.h"
# define MOVE_SPEED 1

// Key handler prototypes
int		handle_keypress(int keycode, t_render *world);
int		handle_esq(int keysym, t_render *world);
int		handle_close(t_render *world);

// Scene movement prototypes
void	move_selected_forward(t_object *obj, double distance);
void	move_selected_right(t_object *obj, double distance);
void	move_selected_up(t_object *obj, double distance);

#endif
