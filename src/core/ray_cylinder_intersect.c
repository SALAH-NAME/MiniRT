/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder_intersect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysemlali <ysemlali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 08:32:02 by ysemlali          #+#    #+#             */
/*   Updated: 2025/02/16 08:32:02 by ysemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

typedef struct s_ray_cylinder_vars {
    t_cylinder cylinder;          // The cylinder object
    t_vec3 oc;                    // Vector from ray origin to cylinder center
    t_vec3 axis;                  // Normalized cylinder axis
    t_vec3 d;                     // Ray direction
    t_vec3 oc_proj;               // Projection of oc onto the plane perpendicular to the cylinder axis
    t_vec3 d_proj;                // Projection of ray direction onto the plane perpendicular to the cylinder axis
    double abc[3];                // Coefficients for the quadratic equation (a, b, c)
    double t_side;                // Intersection distance along the ray for the cylinder side
    t_vec3 point_side;            // Intersection point on the cylinder side
    double height_test;           // Height test to check if the intersection is within the cylinder bounds
    double t_caps[2];             // Intersection distances along the ray for the cylinder caps (top and bottom)
    t_vec3 cap_centers[2];        // Centers of the cylinder caps (bottom and top)
    double t_final;               // Final intersection distance (closest valid intersection)
    t_vec3 cap_point;             // Intersection point on the cylinder cap
    t_vec3 hit_point;             // Final intersection point
    t_vec3 hit_normal;           // Normal at the intersection point
} t_ray_cylinder_vars;

bool ray_cylinder_intersect(t_ray ray, t_object *obj, t_hit *hit)
{
    t_ray_cylinder_vars formula;
  formula.cylinder =obj->data.cylinder;
  formula.oc = vec3_sub(ray.origin, cylinder.center);
  formula.axis =  vec3_normalize(cylinder.normal);
  formula.d = ray.direction;
  formula.oc_proj =vec3_sub(oc, vec3_mul(axis, vec3_dot(oc, axis)));
  formula.d_proj = vec3_sub(d, vec3_mul(axis, vec3_dot(d, axis))); 
  formula.abc[0]  =vec3_dot(d_proj, d_proj);
  formula.abc[1] = 2.0 * vec3_dot(oc_proj, d_proj);
  formula.abc[2] =vec3_dot(oc_proj, oc_proj) - (cylinder.radius * cylinder.radius);
  if (!solve_quadratic(formula.abc[0], formula.abc[1], formula.abc[2], &formula.t_side))
    return false;
  formula.point_side = vec3_add(ray.origin, vec3_mul(ray.direction, t_side));
  formula.height_test = vec3_dot(vec3_sub(point_side, cylinder.center), axis);
  if (formula.height_test < 0 || formula.height_test > formula.cylinder.height)
        formula.t_side = -1; // Outside finite cylinder bounds

    formual.cap_centers[2] = {
        formula.cylinder.center,
        vec3_add(formula.cylinder.center, vec3_mul(formula.axis, formula.cylinder.height))
    };

    for (int i = 0; i < 2; i++) {
        double denom = vec3_dot(ray.direction, axis);
        if (fabs(denom) > 1e-6) {
            t_caps[i] = vec3_dot(vec3_sub(cap_centers[i], ray.origin), axis) / denom;
            t_vec3 cap_point = vec3_add(ray.origin, vec3_mul(ray.direction, t_caps[i]));
            if (!(vec3_length(vec3_sub(cap_point, cap_centers[i])) <= cylinder.radius)) 
                t_caps[i] = -1; 
        } else {
            t_caps[i] = -1;
        }
    }

    // Determine closest valid intersection
    double t_final = -1;
    if (t_side > 0) t_final = t_side;
    for (int i = 0; i < 2; i++) {
        if (t_caps[i] > 0 && (t_final < 0 || t_caps[i] < t_final)) {
            t_final = t_caps[i];
        }
    }

    if (t_final < 0)
        return false;
    
    set_values(hit, ray, cylinder, t_final)
    hit->hit = true;
    hit->t = t_final;
    hit->point = vec3_add(ray.origin, vec3_mul(ray.direction, t_final));

    if (t_final == t_side) {
        hit->normal = vec3_normalize(vec3_sub(hit->point, vec3_add(cylinder.center, vec3_mul(axis, height_test))));
    } else {
        hit->normal = vec3_mul(axis, (vec3_dot(ray.direction, axis) < 0) ? 1.0 : -1.0);
    }

    hit->material = obj->material;
    hit->object = obj;
    hit->view_dir = vec3_mul(ray.direction, -1.0);

    return true;
}

