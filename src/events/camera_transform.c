#include "events.h"

void    camera_movement(int keycode, t_camera *camera, t_render *world)
{   
    if(keycode == XK_w)
        camera->position.z -= SPEED;
    else if(keycode == XK_s)
        camera->position.z += SPEED;
    else if(keycode == XK_a)
        camera->position.x -= SPEED;
    else if(keycode == XK_d)
        camera->position.x += SPEED;
    else if(keycode == XK_Up)
        camera->position.y += SPEED;
    else if(keycode == XK_Down)
        camera->position.y -= SPEED;
    render_scene_on_change(keycode , world);
}

void camera_rotation(int keycode, t_camera *camera, t_render *world)
{
    double rotation_matrix[9];
    t_vec3 rotation_angles = {0, 0, 0};

    if (keycode == XK_Up)
        rotation_angles.x = -SPEED;
    else if (keycode == XK_Down)
        rotation_angles.x = SPEED;
    else if (keycode == XK_Left)
        rotation_angles.y = -SPEED;
    else if (keycode == XK_Right)
        rotation_angles.y = SPEED;

    matrix3_create_rotation(rotation_matrix, rotation_angles);
    camera->orientation = matrix3_apply_rotation(rotation_matrix, camera->orientation);
    render_scene_on_change(keycode , world);

}