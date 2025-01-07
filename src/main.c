/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:13:42 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/07 09:15:45 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
# include "window.h"

void exit_program(t_data *data)
{
	free_all(data);
	exit(0);
}

int	key_press(int keycode, t_data *data)
{
    if (keycode == 65307)  // ESC key for Linux
        exit_program(data);
    return (0);
}

void escape_key(t_data *data)
{
    mlx_hook(data->mlx->win, 2, 1L<<0, &key_press, data);       // Key press events
}


void init_image(t_data *data)
{
	data->mlx->img = mlx_new_image(data->mlx->mlx, data->config->res[0], data->config->res[1]);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bpp, &data->mlx->l_n, &data->mlx->endian);
	data->mlx->width = data->config->res[0];
	data->mlx->height = data->config->res[1];
}




int init_mlx(t_data *data)
{
	data->mlx = ft_calloc(1, sizeof(t_mlx));
	if (!data->mlx)
		return (1);
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
		return (1);
	data->mlx->win = mlx_new_window(data->mlx->mlx, data->config->res[0], data->config->res[1], "miniRT");
	if (!data->mlx->win)
		return (1);
	init_image(data);	
	draw_image(data);
	escape_key(data);
	mlx_loop(data->mlx->mlx);
	return(0);
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
		if (init_mlx(data))	
			return (free_all(data), 1);
		free_all(data);
	}
	return (0);
}
