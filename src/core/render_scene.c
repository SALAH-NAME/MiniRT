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

void	calculate_viewport(t_camera *cam, double *v_right, double *v_top)
{
	double	half_fov_tan;

	half_fov_tan = tan((cam->fov * M_PI / 180.0) / 2.0);
	if (WIDTH >= HEIGHT)
	{
		*v_right = half_fov_tan;
		*v_top = half_fov_tan * ((double)HEIGHT / WIDTH);
	}
	else
	{
		*v_top = half_fov_tan;
		*v_right = half_fov_tan / ((double)HEIGHT / WIDTH);
	}
}

t_vec3	get_ray_direction(int x, int y, double v_right, double v_top)
{
	double	px;
	double	py;

	px = (2.0 * ((x + 0.5) / WIDTH) - 1.0) * v_right;
	py = (1.0 - 2.0 * ((y + 0.5) / HEIGHT)) * v_top;
	return (vec3_create(px, py, -1.0));
}

t_ray	generate_ray(t_camera *cam, int x, int y)
{
	double	viewport_right;
	double	viewport_top;
	t_vec3	ray_direction;
	double	rotation_matrix[9];

	calculate_viewport(cam, &viewport_right, &viewport_top);
	ray_direction = get_ray_direction(x, y, viewport_right, viewport_top);
	matrix3_create_rotation(rotation_matrix, cam->orientation);
	ray_direction = matrix3_apply_rotation(rotation_matrix, ray_direction);
	return ((t_ray){.origin = cam->position,
		.direction = vec3_normalize(ray_direction)});
}

void	render_scene(t_render *render)
{
	int		x;
	int		y;
	t_ray	ray;
	t_color	color_rgb;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = generate_ray(&render->scene.camera, x, y);
			color_rgb = ray_intersection_shading(ray, &render->scene);
			put_pixel_to_img(&render->mlx, x, y, color_rgb);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(render->mlx.ptr, render->mlx.win, render->mlx.img,
		0, 0);
}
