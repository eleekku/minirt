/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:40:31 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/12 16:29:15 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include "../lib/Libft/libft.h"
# include "MLX42/MLX42.h"

# define EPS 0.00001
# define TRUE 1
# define FALSE 0

typedef int     t_bool;

# define PNT 1.0
# define VTR 0.0
# define ORIGIN 0
# define DIRECTION 1

typedef struct  s_sphere
{
    float   coord[3];
    float   diameter;
    int     color[3];
}   t_sphere;

typedef struct  s_plane
{
    float   coord[3];
    float   normv[3];
    int     color[3];
}   t_plane;

typedef struct  s_cylinder
{
    float   coord[3];
    float   normv[3];
    float   diameter;
    float   height;
    int     color[3];
}   t_cylinder;

typedef struct s_scene
{
    float       ambient[4];
    int         camc[3];
    int         normv[3];
    int         fow;
    float       light[3];
    float       brightness;
    t_sphere    *sp;
    t_plane     *pl;
    t_cylinder  *cy;
}   t_scene;

//typedef struct s_color
typedef struct s_matrix
{
	int		size;
	float	**m;
}	t_matrix;

//typedef struct s_sphere
//{
//	float	*center;
//	float	diameter;
//	int		*color;
//}	t_sphere;

typedef struct s_intersections
{
	int		count;
	char	object[100];
	float	t[100];
}	t_intersections;

typedef struct s_intersection
{
	float	t;
	char	object;
}	t_intersection;

/*** Definitions ***/
float			*tuple(float a, float b, float c, float w);
t_matrix		matrix(int size, float *a, ...);
t_matrix		initialize_matrix(t_matrix matrix);
//float	**matrix(float *a, float *b, float *c, float *d);

/*** Tuple Operations ***/
int				equal_float(float a, float b);
float			*tuple_add(float *a, float *b);
float			*tuple_subs(float *a, float *b);
float			*negate_vector(float *a);
float			*tuple_add(float *a, float *b);
float			*scalar_multi_tuple(float *a, float n);
float			*scalar_div_tuple(float *a, float n);
float			magnitude(float *a);
float			*normalize(float *a);
float			dot_product(float *a, float *b);
float			*vector_cross_prod(float *a, float *b);

/*** Matrix operations ***/
int				matrix_are_equal(t_matrix a, t_matrix b);
float			**matrix_multiply(float **a, float **b);
t_matrix		submatrix(t_matrix a, int i, int j);
t_matrix		transpose(t_matrix a);
float			minor(t_matrix a, int i, int j);
float			cofactor(t_matrix a, int i, int j);
float			determinant(t_matrix a);
t_matrix		inverse_matrix(t_matrix a);

/*** Rays ***/
float			**create_ray(float *origin, float *direction);
float			*ray_position(float **r, float t);

/*** Spheres  ***/
//t_intersections	sp_cross(t_sphere sp, float **r);
t_intersections	intersects(t_sphere sp, float **r);

/*** Intersections ***/
t_intersection	intersection(float t, char object);
t_intersections	intersections(int n, t_intersection i, ...);
t_intersection	hit(t_intersections xs);

#endif
