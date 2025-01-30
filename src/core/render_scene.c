/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:52:32 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/28 18:50:33 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
#include <stdio.h>

void	pixel_to_viewport(int x, int y, t_render *render, t_vec3 *direction)
{
	double	px;
	double	py;
	double	viewport_right;
	double	viewport_top;
	double	half_fov_tan;

	half_fov_tan = tan((render->scene.camera.fov * M_PI / 180) / 2.0);
	if (WIDTH >= HEIGHT)
	{
		viewport_top = half_fov_tan;
		viewport_right = viewport_top * (double)WIDTH / (double)HEIGHT;
	}
	else
	{
		viewport_right = half_fov_tan;
		viewport_top = viewport_right * (double)HEIGHT / (double)WIDTH;
	}
	px = (2.0 * ((x + 0.5) / WIDTH) - 1.0) * viewport_right;
	py = (1.0 - 2.0 * ((y + 0.5) / HEIGHT)) * viewport_top;
	*direction = vec3_normalize(vec3_create(px, py, -1.0));
  /*printf("directoin normalized %f %f %f\n", direction->x , direction->y, direction->z);*/
  /*exit(0);*/
}

void	put_pixel_to_img(t_mlx *mlx, int x, int y, t_color color)
{
	char	*destination;
	int		rgb;

	rgb = ((int)(color.r * 255) << 16) | ((int)(color.g
				* 255) << 8) | (int)(color.b * 255);
	destination = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel
				/ 8));
	*(unsigned int *)destination = rgb;
}

void	render_pixel(t_render *render, int x, int y)
{
	t_ray	ray;
	t_hit	hit;
	t_color	color;
	t_vec3	direction;

	pixel_to_viewport(x, y, render, &direction);
	ray = ray_create(render->scene.camera.position, direction);
	hit = find_nearest_intersection(ray, &render->scene);
	color = calculate_lighting(&render->scene, hit);
	put_pixel_to_img(&render->mlx, x, y, color);
}

void	render_scene(t_render *render)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_pixel(render, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(render->mlx.ptr, render->mlx.win, render->mlx.img,
		0, 0);
}
