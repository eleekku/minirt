/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:50:36 by esalmela          #+#    #+#             */
/*   Updated: 2024/09/12 16:50:39 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	object->cylindermin = 1.0;
	object->cylindermax = 2.0;
    free(object->material->color);
    object->material->color = color(0, 0, 200);
    return (object);
}


t_intersections *plane_intersect(t_object *plane, float **ray)
{
    t_intersections	*cross;
    float           t;

    cross = create_intersections();
    if (!cross)
        return (NULL);
    if (fabs(ray[1][1]) < EPS)
        return (cross);
    t = (ray[0][1] * -1 / ray[1][1]);
    cross->count++;
    cross->int_list[0].t = t;
    return (cross);    
}




