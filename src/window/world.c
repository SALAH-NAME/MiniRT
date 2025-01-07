/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:41:30 by ysemlali          #+#    #+#             */
/*   Updated: 2025/01/07 12:55:50 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "window.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
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

    space.forward = vector3d_normalize(space.forward);
    space.right = vector3d_normalize(space.right);
    space.up = vector3d_normalize(space.up);


    printf("position: %f, %f, %f\n", space.position.x, space.position.y, space.position.z);
    printf("forward: %f, %f, %f\n", space.forward.x, space.forward.y, space.forward.z);
    printf("right: %f, %f, %f\n", space.right.x, space.right.y, space.right.z);
    printf("up: %f, %f, %f\n", space.up.x, space.up.y, space.up.z);

    exit(0);
    return (space); 

}



