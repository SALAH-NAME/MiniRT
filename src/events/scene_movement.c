#include "minirt.h"
# include <stdio.h>

void translate_vec(t_vec3 *vec, double x, double y, double z)
{
    vec->x += x;
    vec->y += y;
    vec->z += z;
}

void    move_selected_forward(t_scene *scene, double distance)
{
  printf("  hello\n");
    if (scene->selected_obj)
        translate_vec(&scene->selected_obj->data.plane.center, 0, distance, 0);
}

void    move_selected_right(t_scene *scene, double distance)
{
  printf("  hello\n");
    if (scene->selected_obj)
        translate_vec(&scene->selected_obj->data.plane.center, 0, distance, 0);
}

void    move_selected_up(t_scene *scene, double distance)
{
    if (scene->selected_obj)
        translate_vec(&scene->selected_obj->data.plane.center, 0, distance, 0);
}
