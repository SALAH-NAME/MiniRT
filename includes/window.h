#ifndef WINDOW_H
# define WINDOW_H


# include "core.h"
# include "algebra.h"






typedef struct t_rgb
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}               t_rgb;



typedef struct s_space
{
    t_vector3d position;
    t_vector3d forward;
    t_vector3d right;
    t_vector3d up;
    double fov;
}               t_space;


t_space  init_space(t_data *data);
void			draw_image(t_data *data);
unsigned int	rgb_to_int(int *rgb);
unsigned int	get_pixel_color(t_data *data, int x, int y);
void			put_pixel_color(t_data *data, int x, int y, unsigned int color);


// convert betweeen world, camera and screen space
t_vector3d		project(t_vector3d origin, t_camera camera, t_data *data);
t_vector3d		world_to_camera(t_vector3d world, t_camera camera);
t_vector3d		camera_to_screen(t_vector3d camera, t_data *data);
t_vector3d		world_to_screen(t_vector3d world, t_camera camera, t_data *data);

#endif