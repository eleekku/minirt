#include "../inc/minirt.h"

t_intersections *cylinder_intersect(t_object *plane, float **ray)
{
    t_intersections	*cross;
    float a;

    a = pow(ray[1][0], 2) + pow(ray[1][2], 2);

}