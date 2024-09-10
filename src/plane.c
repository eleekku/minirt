#include "../inc/minirt.h"

t_object *test_object(t_shape type)
{
    t_object    *object;

    object = malloc(sizeof(t_object));
    if (!object)
        return (NULL);
    object->s = type;
    object->coord = create_point(0, 0, 0);
    object->transform = create_identity(4);
    object->material = create_material();
    object->material->diffuse = 0.9;
    object->material->specular = 0.9;
    object->material->shininess = 200.0;
    free(object->material->color);
    object->material->color = color(0, 0, 200); 
}


t_intersections plane_intersect(t_object *plane, float **ray)
{

}




