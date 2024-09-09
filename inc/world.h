/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:57:02 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/08 16:09:09 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	WORLD_H
# define	WORLD_H
# include "minirt.h"

typedef struct s_material
{
	float	*color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

typedef struct s_light
{
	float	*color;
	float	*coord;
}	t_light;

typedef struct s_object
{
    t_shape s;
    float   *coord;
    float   diameter;
    int     color[3];
    t_matrix	transform;
    float   normv[3];
    float   height;
    t_material  material;
}   t_object;

typedef struct s_world
{
	int			number_objects;
	t_object	*objects;
	t_light		*light;
}	t_world;

typedef struct s_comp
{
	t_object	*object;
	float		t;
	float		*point;
	float		*eyev;
	float		*normalv;
	t_bool		inside;
}	t_comp;

typedef struct s_intersection
{
	float	    t;
	t_object	object;
}	t_intersection;

typedef struct  s_intersections
{
    int count;
    t_intersection *int_list;
}   t_intersections;

float	*hadamard(float *a, float *b);
float	*multiply_color(float *a, float b);
float	*add_colors(float *a, float *b, float *c);
float	*lighting(t_comp *comp, t_world *w, t_object object);
t_intersections	*intersect_world(t_world *w, float **r);
t_comp			*prepare_computations(t_intersection i, float **ray);
void	clean_comp(t_comp *comp);

t_intersections	intersects(t_sphere *sp, float **r);
t_intersection	intersection(float t, t_object object);
t_intersections	intersections(int n, t_intersection i, ...);
t_intersection	hit(t_intersections xs);
t_intersections	sphere_intersect(t_object sp, float **r);
t_intersections	*sort_intersect(int n, t_intersections *xs);


float	        *normal_at(t_object *object, float *world_p);

#endif