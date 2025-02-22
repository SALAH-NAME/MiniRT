#include "minirt.h"
#include <stdio.h>

void	translate_vec(t_vec3 *vec, double x, double y, double z)
{
	vec->x = vec->x + x;
	vec->y = vec->y + y;
	vec->z = vec->z + z;
}

void	move_selected_forward(t_object *obj, double distance)
{
	t_vec3	*center;

	if (!obj)
		return ;
	switch (obj->type)
	{
	case OBJ_PLANE:
		center = &obj->data.plane.center;
		break ;
	case OBJ_SPHERE:
		center = &obj->data.sphere.center;
		break ;
	case OBJ_CYLINDER:
		center = &obj->data.cylinder.center;
		break ;
	default:
		return ;
	}
	translate_vec(center, 0.0, 0.0, distance);
}

void	move_selected_right(t_object *obj, double distance)
{
	t_vec3	*center;

	if (!obj)
		return ;
	switch (obj->type)
	{
	case OBJ_PLANE:
		center = &obj->data.plane.center;
		break ;
	case OBJ_SPHERE:
		center = &obj->data.sphere.center;
		break ;
	case OBJ_CYLINDER:
		center = &obj->data.cylinder.center;
		break ;
	default:
		return ;
	}
	translate_vec(center, distance, 0.0, 0.0);
}

void	move_selected_up(t_object *obj, double distance)
{
	t_vec3	*center;

	if (!obj)
		return ;
	switch (obj->type)
	{
	case OBJ_PLANE:
		center = &obj->data.plane.center;
		break ;
	case OBJ_SPHERE:
		center = &obj->data.sphere.center;
		break ;
	case OBJ_CYLINDER:
		center = &obj->data.cylinder.center;
		break ;
	case OBJ_CONE:
		center = &obj->data.cone.center;
		break ;
	default:
		return ;
	}
	translate_vec(center, 0.0, distance, 0.0);
}
