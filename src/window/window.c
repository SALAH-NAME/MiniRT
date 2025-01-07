/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:40:26 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/07 09:16:16 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "window.h"


unsigned int	rgb_to_int(t_rgb rgb)
{
	return ((rgb.r << 16) + (rgb.g << 8) + rgb.b);
}

unsigned int	get_pixel_color(t_data *data, int x, int y)
{
	char *dst;

	dst = data->mlx->addr + (y * data->mlx->l_n + x * (data->mlx->bpp/ 8));
	return (*(unsigned int *)dst);
}

void			put_pixel_color(t_data *data, int x, int y, unsigned int color)
{
    char *dst;

    dst = data->mlx->addr + (y * data->mlx->l_n + x * (data->mlx->bpp/ 8));
    *(unsigned int *)dst = color;
}

# define X 0
# define Y 1
void draw_image(t_data *data)
{
	int x;
	int y;
	unsigned int color;
	t_rgb rgb;

	y = 0;
	rgb.r = data->scene->ambient->color[0];
	rgb.g = data->scene->ambient->color[1];
	rgb.b = data->scene->ambient->color[2];
	int horizontal = data->config->res[X] / 2;
	int vertical = data->config->res[Y] / 2;
	while (y < data->config->res[Y])
	{
		x = 0;
		while (x < data->config->res[X])
		{
			color = rgb_to_int(rgb);
			if(y == horizontal)
				put_pixel_color(data, x, y, color);
			if(x == vertical)
				put_pixel_color(data, x, y, color);
			else
				put_pixel_color(data, x, y, 0x000000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, 0, 0);
}



