/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:39:41 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/17 13:39:41 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static double	noise(int x, int y, int z)
{
	int		n;
	double	result;

	n = x + y * 57 + z * 57 * 57;
	n = (n << 13) ^ n;
	result = (1.0 - ((n * (n * n * 15731 + 789221) + 1376312589) & 0x7fffffff)
			/ 1073741824.0);
	return (result);
}

static double	trilinear_interpolate(double pts[8], t_vec3 f)
{
	double	x_interp[4];
	double	y_interp[2];

	x_interp[0] = pts[0] * (1 - f.x) + pts[1] * f.x;
	x_interp[1] = pts[2] * (1 - f.x) + pts[3] * f.x;
	x_interp[2] = pts[4] * (1 - f.x) + pts[5] * f.x;
	x_interp[3] = pts[6] * (1 - f.x) + pts[7] * f.x;
	y_interp[0] = x_interp[0] * (1 - f.y) + x_interp[1] * f.y;
	y_interp[1] = x_interp[2] * (1 - f.y) + x_interp[3] * f.y;
	return (y_interp[0] * (1 - f.z) + y_interp[1] * f.z);
}

static double	smooth_noise(double x, double y, double z)
{
	t_vec3	i;
	t_vec3	f;
	double	pts[8];

	i.x = floor(x);
	i.y = floor(y);
	i.z = floor(z);
	f.x = x - i.x;
	f.y = y - i.y;
	f.z = z - i.z;
	pts[0] = noise(i.x, i.y, i.z);
	pts[1] = noise(i.x + 1, i.y, i.z);
	pts[2] = noise(i.x, i.y + 1, i.z);
	pts[3] = noise(i.x + 1, i.y + 1, i.z);
	pts[4] = noise(i.x, i.y, i.z + 1);
	pts[5] = noise(i.x + 1, i.y, i.z + 1);
	pts[6] = noise(i.x, i.y + 1, i.z + 1);
	pts[7] = noise(i.x + 1, i.y + 1, i.z + 1);
	return (trilinear_interpolate(pts, f));
}

static void	create_tangent_space(t_vec3 normal, t_vec3 *tangent,
		t_vec3 *bitangent)
{
	if (fabs(normal.y) > 0.9)
		*tangent = vec3_normalize((t_vec3){1, 0, 0});
	else
		*tangent = vec3_normalize(vec3_cross(normal, (t_vec3){0, 1, 0}));
	*bitangent = vec3_cross(normal, *tangent);
}

t_vec3	perturb_normal(t_vec3 normal, t_vec3 point, t_bump_map *bump)
{
	t_vec3	tangent;
	t_vec3	bitangent;
	t_vec3	noise_vec;
	t_vec3	perturbed;

	noise_vec.x = smooth_noise(point.x * bump->scale, point.y * bump->scale,
			point.z * bump->scale);
	noise_vec.y = smooth_noise(point.x * bump->scale + 100, point.y
			* bump->scale + 100, point.z * bump->scale + 100);
	noise_vec.z = smooth_noise(point.x * bump->scale + 200, point.y
			* bump->scale + 200, point.z * bump->scale + 200);
	create_tangent_space(normal, &tangent, &bitangent);
	perturbed = vec3_add(normal, vec3_add(vec3_mul(tangent, noise_vec.x
					* bump->intensity), vec3_add(vec3_mul(bitangent, noise_vec.y
						* bump->intensity), vec3_mul(normal, noise_vec.z
						* bump->intensity))));
	return (vec3_normalize(perturbed));
}
