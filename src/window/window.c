/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:40:26 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/07 18:18:10 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "window.h"
# include "algebra.h"


unsigned int	rgb_to_int(int *rgb)
{
	return((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}
void put_pixel_color(t_data *data, int x, int y, unsigned int color)
{
    if (x < 0 || y < 0 || x >= data->config->res[X] || y >= data->config->res[Y])
    {
        printf("put_pixel_color: Coordinates out of bounds: (%d, %d)\n", x, y);
        return;
    }

    char *dst = data->mlx->addr + (y * data->mlx->l_n + x * (data->mlx->bpp / 8));
    *(unsigned int *)dst = color;
}
