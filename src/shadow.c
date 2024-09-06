#include "../inc/minirt.h"

t_bool  is_shadowed(t_scene *scene, float *point)
{
    float *distance;
    float *direction;
    float **ray;


    distance = tuple_subs(scene->light.position, point);
    direction = normalize(distance);
    ray = create_ray(point, direction);
    
}