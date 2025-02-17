/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_lighting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souahidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:36:17 by souahidi          #+#    #+#             */
/*   Updated: 2025/02/12 16:36:17 by souahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static t_color	calculate_ambient(t_hit *hit, t_ambientlight *ambient)
{
	t_color	ambient_color;
	t_color	surface_color;

	if (hit->material.checker.scale > 0)
		surface_color = get_checker_color(hit);
	else
		surface_color = hit->material.color;
	ambient_color.r = ambient->color.r * ambient->ratio * surface_color.r;
	ambient_color.g = ambient->color.g * ambient->ratio * surface_color.g;
	ambient_color.b = ambient->color.b * ambient->ratio * surface_color.b;
	return (ambient_color);
}

static t_color	calculate_diffuse(t_hit *hit, t_light *light, t_vec3 light_dir)
{
	t_color	diffuse_color;
	double	diff_factor;
	t_color	surface_color;

	if (hit->material.checker.scale > 0)
		surface_color = get_checker_color(hit);
	else
		surface_color = hit->material.color;
	diff_factor = fmax(vec3_dot(hit->normal, light_dir), 0.0);
	diffuse_color.r = surface_color.r * light->color.r * diff_factor
		* hit->material.diffuse_coefficient * light->brightness;
	diffuse_color.g = surface_color.g * light->color.g * diff_factor
		* hit->material.diffuse_coefficient * light->brightness;
	diffuse_color.b = surface_color.b * light->color.b * diff_factor
		* hit->material.diffuse_coefficient * light->brightness;
	return (diffuse_color);
}

static t_color	calculate_specular(t_hit *hit, t_light *light, t_vec3 light_dir)
{
	t_color	specular_color;
	t_vec3	reflect_dir;
	double	spec_factor;

	reflect_dir = vec3_reflect(vec3_mul(light_dir, -1.0), hit->normal);
	spec_factor = pow(fmax(vec3_dot(hit->view_dir, reflect_dir), 0.0),
			hit->material.shininess);
	specular_color.r = light->color.r * spec_factor
		* hit->material.specular_coefficient * light->brightness;
	specular_color.g = light->color.g * spec_factor
		* hit->material.specular_coefficient * light->brightness;
	specular_color.b = light->color.b * spec_factor
		* hit->material.specular_coefficient * light->brightness;
	return (specular_color);
}

static void	add_light_contribution(t_color *final, t_color *contrib1,
		t_color *contrib2)
{
	final->r += contrib1->r;
	final->g += contrib1->g;
	final->b += contrib1->b;
	final->r += contrib2->r;
	final->g += contrib2->g;
	final->b += contrib2->b;
}

t_color	calculate_lighting(t_hit *hit, t_scene *scene)
{
	t_color	final_color;
	t_light	*light;
	t_vec3	light_dir;
	t_color	diffuse;
	t_color	specular;

	final_color = calculate_ambient(hit, &scene->ambient);
	light = scene->lights;
	while (light)
	{
		if (is_in_shadow(hit->point, light->position, scene, hit->object))
		{
			light = light->next;
			continue ;
		}
		light_dir = vec3_normalize(vec3_sub(light->position, hit->point));
		diffuse = calculate_diffuse(hit, light, light_dir);
		specular = calculate_specular(hit, light, light_dir);
		add_light_contribution(&final_color, &diffuse, &specular);
		light = light->next;
	}
	final_color.r = fmin(final_color.r, 1.0);
	final_color.g = fmin(final_color.g, 1.0);
	final_color.b = fmin(final_color.b, 1.0);
	return (final_color);
}
