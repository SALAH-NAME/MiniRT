/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:59:41 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/25 16:08:56 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdlib.h>

int	handle_keypress(int keysym, t_render *world)
{
	(void)world;
	if (keysym == XK_Escape || keysym == XK_q)
		mlx_loop_end(world->mlx.ptr);
	return (0);
}

int	handle_close(t_render *world)
{
	mlx_loop_end(world->mlx.ptr);
	return (0);
}
