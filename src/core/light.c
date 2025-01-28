/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:52:01 by souahidi          #+#    #+#             */
/*   Updated: 2025/01/28 20:21:52 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	apply_ambient(t_hit hit, t_scene *scene)
{
	return (color_multiply(hit.material.color, scene->ambient.itensity));
}

t_color	calculate_diffuse(t_hit hit, t_vec3 light_dir, double coef)
{
	double	n_dot_l;

	n_dot_l = vec3_dot(hit.normal, light_dir);
	if (n_dot_l > 0)
		return (color_multiply(hit.material.color, n_dot_l
				* hit.material.diffuse_coefficient * coef));
	return (color_create(0, 0, 0));
}

t_color	calculate_specular(t_hit hit, t_vec3 light_dir, double coef)
{
	t_vec3	reflect_dir;
	double	spec;
	double	n_dot_l;

	n_dot_l = vec3_dot(hit.normal, light_dir);
	if (n_dot_l <= 0)
		return (color_create(0, 0, 0));
	reflect_dir = vec3_subtract(vec3_scale(hit.normal, 2.0 * n_dot_l),
			light_dir);
	spec = pow(fmax(vec3_dot(hit.view_dir, reflect_dir), 0.0),
			hit.material.shininess) * hit.material.specular_coefficient * coef;
	return (color_multiply(hit.material.color, spec));
}

void	add_light_contribution(t_color *final, t_color contrib)
{
	final->r += contrib.r;
	final->g += contrib.g;
	final->b += contrib.b;
}

t_color	calculate_lighting(t_scene *scene, t_hit hit)
{
	t_color	final;
	t_light	*light;
	t_vec3	light_dir;
	double	light_dist;
	t_hit	shadow;

	if (!hit.hit)
		return (color_create(0.2, 0.2, 0.2));
	final = apply_ambient(hit, scene);
	light = scene->lights;
	while (light)
	{
		light_dir = vec3_subtract(light->position, hit.point);
		light_dist = vec3_magnitude(light_dir);
		light_dir = vec3_normalize(light_dir);
		shadow = find_nearest_intersection((t_ray){hit.point, light_dir},
				scene);
		if (!shadow.hit || shadow.t >= light_dist)
		{
			add_light_contribution(&final, calculate_diffuse(hit, light_dir,
					1.0));
		}
		light = light->next;
	}
	final = color_create(fmin(final.r, 1.0), fmin(final.g, 1.0), fmin(final.b,
				1.0));
	return (final);
}
