/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:13:42 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/05 20:53:54 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"




void create_image(t_data *data)
{
	data->mlx->img = mlx_new_image(data->mlx->mlx, 
								  data->config->res[0], 
								  data->config->res[1]);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, 
									  &data->mlx->bpp, 
									  &data->mlx->line_len, 
									  &data->mlx->endian);
}



// Function to put a pixel
void put_pixel(t_data *data, int x, int y, int color)
{
    char *dst;
    
    if (x >= 0 && x < data->config->res[0] && 
        y >= 0 && y < data->config->res[1])
    {
        dst = data->mlx->addr + (y * data->mlx->line_len + 
              x * (data->mlx->bpp / 8));
        *(unsigned int*)dst = color;
    }
}

// Add this function
void draw_square(t_data *data, int x, int y, int size, int color)
{
    int i;
    int j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            put_pixel(data, x + i, y + j, color);
            j++;
        }
        i++;
    }
}





void open_window(t_data *data)
{
    data->mlx = ft_calloc(1, sizeof(t_mlx));
    if(!data->mlx)
    {
        set_error(data, "Failed to allocate memory for mlx", NULL, NULL);
        return;
    }
    data->mlx->mlx = mlx_init();
    data->mlx->win = mlx_new_window(data->mlx->mlx, 
                                   data->config->res[0], 
                                   data->config->res[1], 
                                   "miniRT");
    create_image(data);
    
    // Draw a 50x50 red square at (100,100)
    draw_square(data, 0, 0, 50, 0x00FF0000);
    
    mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, 
                           data->mlx->img, 0, 0);
}




int	init(t_data *data, char *av)
{
	if (parse_config_init(data))
		return (1);
	if (load(data, av))
		return (free_all(data), 1);
	return (0);
}

int	main(int ac, char **av)
{

	t_data	*data;

	if (ac != 2)
	{
		printf("Usage: %s <file>\n", av[0]);
		return (1);
	}
	if (valid_file_name(av[1]))
		return (1);
	data = ft_calloc(1, sizeof(t_data));
	if (data)
	{
		if (init(data, av[1]))
			return (free_all(data), 1);
		open_window(data);
	}
	mlx_loop(data->mlx->mlx);
	free_all(data);
	return (0);
}
