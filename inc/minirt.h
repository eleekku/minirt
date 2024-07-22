/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:40:31 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/22 15:43:15 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "MLX42/MLX42.h"

# define EPS 0.00001

typedef struct s_tuple {
    float   x;
    float   y;
    float   z;
    float   w;
}   t_tuple;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct	s_sphere
{
    t_tuple	center;
    float	diameter;
	t_color	color;
}	t_sphere;

typedef struct s_intersections
{
	int		count;
	char	object[100];
	float	t[100];
}	t_intersections;

typedef struct s_ray
{
    t_tuple origin;
    t_tuple direction;
}   t_ray;

typedef struct s_intersection
{
	float	t;
	char	object;
}	t_intersection;

/*** Definitions ***/
float	*point(float a, float b, float c);
float	*vector(float a, float b, float c);

/*** Operations ***/
int 	equal_float(float a, float b);
float	*tuple_add(float *a, float *b);
float	*tuple_subs(float *a, float *b);
float	*negate_vector(float *a);
float	*tuple_add(float *a, float *b);
float	*scalar_multi_tuple(float *a, float n);
float	*scalar_div_tuple(float *a, float n);
float   magnitude(float *a);
float	*normalize(float *a);
float	dot_product(float *a, float *b);
float	*vector_cross_prod(float *a, float *b);

/*** Rays ***/
float	**create_ray(float *origin, float *direction);
float	*ray_position(float **r, float t);

/*** Spheres  ***/
t_intersections	sp_cross(t_sphere sp, t_ray	r);

/*** Intersections ***/
t_intersection	intersection(float t, char object);
t_intersections	intersections(int n, t_intersection i, ...);
t_intersection	hit(t_intersections xs);

#endif