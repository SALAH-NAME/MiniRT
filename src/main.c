/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:13:42 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/03 20:10:25by ysemlali         ###   ########.fr       */
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
	/*if (load_render(data))*/
	/*return (1);*/
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
	}
	free_all(data);
	return (0);
}

#else

# include "algebra.h"
# include "core.h"
# include "list.h"
# include "minirt.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


static bool	init_mlx(t_render *render)
{
	render->mlx.ptr = mlx_init();
	if (!render->mlx.ptr)
		return (false);
	render->mlx.win = mlx_new_window(render->mlx.ptr, WIDTH, HEIGHT, "miniRT");
	if (!render->mlx.win)
		return (false);
	render->mlx.img = mlx_new_image(render->mlx.ptr, WIDTH, HEIGHT);
	if (!render->mlx.img)
		return (false);
	render->mlx.addr = mlx_get_data_addr(render->mlx.img,
			&render->mlx.bits_per_pixel, &render->mlx.line_length,
			&render->mlx.endian);
	return (true);
}

static void	setup_hooks(t_render *render)
{
	mlx_hook(render->mlx.win, KeyPress, KeyPressMask, &handle_keypress, render);
	mlx_hook(render->mlx.win, DestroyNotify, StructureNotifyMask, &handle_close,
		render);
}

static void	cleanup_render(t_render *render)
{
	if (!render)
		return ;
	if (render->mlx.img)
		mlx_destroy_image(render->mlx.ptr, render->mlx.img);
	if (render->mlx.win)
		mlx_destroy_window(render->mlx.ptr, render->mlx.win);
	if (render->mlx.ptr)
	{
		mlx_destroy_display(render->mlx.ptr);
		free(render->mlx.ptr);
	}
	free_scene(&render->scene);
}

static int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_render	render;

	(void)argv;
	(void)argc;
	/*if (argc != 2)*/
		/*return (ft_error("Usage: ./miniRT <scene.rt>"));*/

	 // if (!parse_scene(&render, argv[1]))
		// return (cleanup(&render), ft_error("Scene parsing failed"));

	if (!init_mlx(&render))
		return (cleanup_render(&render), ft_error("MLX initialization failed"));
	setup_hooks(&render);
	init_scene(&render);
	render_scene(&render);
	mlx_loop(render.mlx.ptr);
	cleanup_render(&render);
	return (0);
}

#endif
