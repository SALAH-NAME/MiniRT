#ifndef EVENTS_H
# define EVENTS_H

# include "minirt.h"

// Key handler prototypes
int     handle_keypress(int keycode, t_render *world);
int	    handle_esq(int keysym, t_render *world);
int     handle_close(t_render *world);

// Scene movement prototypes
void    move_selected_forward(t_scene *scene, double distance);
void    move_selected_right(t_scene *scene, double distance);
void    move_selected_up(t_scene *scene, double distance);


#endif