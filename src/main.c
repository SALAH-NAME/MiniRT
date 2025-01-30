/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:13:42 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/28 16:29:46 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PARSING 0
#if PARSING

# include "core.h"

int	init(t_data *data, char *av)
{
	if (parse_config_init(data))
		return (1);
	if (load_file(data, av))
		return (1);
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
			return (free_all(data),1);
	}
	free_all(data);
	return (0);
}

#else

# include "minirt.h"
# include <stdio.h>
# include <stdlib.h>

int	main(void)
{
	t_render	world;

	// Parsing map
	// Setup mlx
	world.mlx.ptr = mlx_init();
	world.mlx.win = mlx_new_window(world.mlx.ptr, WIDTH, HEIGHT, "miniRT");
	world.mlx.img = mlx_new_image(world.mlx.ptr, WIDTH, HEIGHT);
	world.mlx.addr = mlx_get_data_addr(world.mlx.img, &world.mlx.bits_per_pixel,
			&world.mlx.line_length, &world.mlx.endian);
	// Hooks
	mlx_hook(world.mlx.win, KeyPress, KeyPressMask, &handle_keypress, &world);
	mlx_hook(world.mlx.win, DestroyNotify, StructureNotifyMask, &handle_close,
		&world);
	
	init_scene(&world);
	render_scene(&world);

	mlx_loop(world.mlx.ptr);
	mlx_destroy_image(world.mlx.ptr, world.mlx.img);
	mlx_destroy_window(world.mlx.ptr, world.mlx.win);
	mlx_destroy_display(world.mlx.ptr);
	free(world.mlx.ptr);
	// Free all
	return (0);
}

#endif
