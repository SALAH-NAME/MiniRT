#ifndef WINDOW_H
# define WINDOW_H

# include "core.h"

typedef struct t_rgb
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
}               t_rgb;



void			draw_image(t_data *data);
unsigned int	rgb_to_int(t_rgb rgb);
unsigned int	get_pixel_color(t_data *data, int x, int y);
void			put_pixel_color(t_data *data, int x, int y, unsigned int color);

#endif