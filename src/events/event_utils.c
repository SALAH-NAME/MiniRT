/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:40:06 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/22 09:40:06 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void    print_mode(int mode, int *last_mode)
{
    if (mode != *last_mode)
    {
        if (mode == MODE_OBJECT_MOVE)
        {
            printf(GREEN "\n-----------🚀 Entering Mode: OJBECT MOVEMENT-----------\n" RESET);
            printf(YELLOW "Press Tab to switch between objects\n" RESET);
        }
        if (mode == MODE_OBJECT_ROTATE)
        {
            printf(BLUE "\n-----------🚀 Entering Mode: OBJECT ROTATION-----------\n" RESET);
            printf(YELLOW "Press Tab to switch between objects\n" RESET);
        }
        if (mode == MODE_CAMERA_MOVE)
            printf(MAGENTA "\n-----------📷 Entering Mode: CAMERA MOVEMENT-----------\n" RESET);
        if (mode == MODE_CAMERA_ROTATE)
            printf(CYAN "\n-----------📷 Entering Mode: CAMERA ROTATION-----------\n" RESET);
        *last_mode = mode;
    }
}

void    print_selected_object(t_object *object)
{
    if (!object)
        return;
    if (object->type == OBJ_SPHERE)
        printf(GREEN "🔵 Selected object: Sphere, id: %d\n" RESET, object->id);
    else if (object->type == OBJ_PLANE)
        printf(BLUE "🟦 Selected object: Plane, id: %d\n" RESET, object->id);
    else if (object->type == OBJ_CYLINDER)
        printf(YELLOW "🟡 Selected object: Cylinder, id: %d\n" RESET, object->id);
    else if (object->type == OBJ_CONE)
        printf(RED "🔺 Selected object: Cone, id: %d\n" RESET, object->id);
}

t_vec3  *get_object_position(t_object *object)
{
    if (!object)
        return NULL;
    if (object->type == OBJ_SPHERE)
        return &object->data.sphere.center;
    if (object->type == OBJ_PLANE)
        return &object->data.plane.center;
    if (object->type == OBJ_CYLINDER)
        return &object->data.cylinder.center;
    if (object->type == OBJ_CONE)
        return &object->data.cone.center;   
    return NULL;
}

t_object    *switch_objects(t_object *objects)
{
    static t_object *current = NULL;
    
    if (!objects)
        return NULL;
    if (!current)
        current = objects; 
    else if (current->next)
        current = current->next;
    else
        current = objects; 
    return current;
}



void render_scene_on_change(int  keycode , t_render *world)
{
    if( keycode  == XK_s || keycode == XK_w || keycode == XK_a || keycode == XK_d || keycode == XK_Up || keycode == XK_Down)
        render_scene(world);
}