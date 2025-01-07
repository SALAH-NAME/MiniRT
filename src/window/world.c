/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:41:30 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/07 12:55:42by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "window.h"
# include "algebra.h"

t_vector3d xyz_to_vector3d(double *value)
{
    t_vector3d vec;
    vec.x = value[X];
    vec.y = value[Y];
    vec.z = value[Z];
    return (vec);
}




// using camer's positoin and orientation to init space
t_space init_space(t_data *data)
{
    t_space space;
    t_camera *camera;

    camera = data->scene->camera;
    space.position = xyz_to_vector3d(camera->position);
    space.forward = xyz_to_vector3d(camera->orientation);
    space.right = vector3d_cross(space.forward, xyz_to_vector3d((double[]){0, 1, 0}));
    space.up = vector3d_cross(space.right, space.forward);
    space.direction = vector3d_normalize(vector3d_subtract(space.origin, space.position));
    space.origin = space.position;
    space.fov = camera->fov;
    space.aspect_ratio = (double)data->config->res[X] / (double)data->config->res[Y];
    space.near = 0.1;
    space.far = 1000;






    return (space); 

}



