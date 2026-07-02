/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:47:31 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/24 00:50:45 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static bool	init_sdl(t_render *render)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (false);
	render->sdl.win = SDL_CreateWindow("miniRT",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!render->sdl.win)
		return (SDL_Quit(), false);
	render->sdl.surface = SDL_GetWindowSurface(render->sdl.win);
	if (!render->sdl.surface)
		return (SDL_DestroyWindow(render->sdl.win), SDL_Quit(), false);
	render->sdl.quit = 0;
	return (true);
}

static void	cleanup_render(t_render *render)
{
	if (!render)
		return ;
	if (render->sdl.win)
		SDL_DestroyWindow(render->sdl.win);
	SDL_Quit();
	free_scene(&render->scene);
}

static int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	write(2, "\n", 1);
	return (1);
}

static void	sdl_event_loop(t_render *render)
{
	SDL_Event	event;

	while (!render->sdl.quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				render->sdl.quit = 1;
			else if (event.type == SDL_KEYDOWN)
				handle_keypress((int)event.key.keysym.sym, render);
		}
		SDL_Delay(16);
	}
}

int	main(int argc, char *argv[])
{
	t_render	render;

	if (argc != 2)
		return (ft_error("Usage: ./miniRT <scene.rt>"));
	if (parse_scene(&render, argv[1]) == false)
		return (ft_error("Scene parsing failed"), 1);
	if (!init_sdl(&render))
		return (cleanup_render(&render), ft_error("SDL initialization failed"));
	init_scene(&render);
	render_scene(&render);
	print_transformation_instructions();
	sdl_event_loop(&render);
	cleanup_render(&render);
	return (0);
}
