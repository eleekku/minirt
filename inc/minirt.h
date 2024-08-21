/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:40:31 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/21 12:40:41 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/Libft/libft.h"
# include "MLX42/MLX42.h"

# define PI 3.14159265358979323846
# define EPS 0.00001
# define TRUE 1
# define FALSE 0

typedef int     t_bool;

# define ORIGIN 0
# define DIRECTION 1

typedef enum    e_shape
{
    SPHERE,
    PLANE,
    CYLINDER
}   t_shape;

typedef enum    e_transformation
{
    TRANSLATION,
    SCALING,
    ROTATE,
	SHEARING
}   t_transformation;

typedef struct s_matrix
{
	int		            size;
	float	            **m;
    t_transformation    type;
}	t_matrix;

typedef struct s_object
{
    t_shape s;
    float   *coord;
    float   diameter;
    int     color[3];
    t_matrix	transform;
    float   normv[3];
    float   height;
}   t_object;

/*typedef struct  s_sphere
{
    float   coord[3];
    float   diameter;
    int     color[3];
    float   **transform;
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
*/
typedef struct s_scene
{
    float       ambient[4];
    int         camc[3];
    int         normv[3];
    int         fow;
    float       light[3];
    float       brightness;
    t_object    *objects;
}   t_scene;

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
float	        *tuple(float a, float b, float c, float w);
float           *create_point(float a, float b, float c);
float           *create_vector(float a, float b, float c);
t_matrix	    matrix(float *a, float *b, float *c, float *d);
t_matrix		initialize_matrix(t_matrix matrix);

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
t_matrix		matrix_multiply(float **a, float **b);
t_matrix		submatrix(t_matrix a, int i, int j);
t_matrix		transpose(t_matrix a);
float			minor(t_matrix a, int i, int j);
float			cofactor(t_matrix a, int i, int j);
float			determinant(t_matrix a);
t_matrix		inverse_matrix(t_matrix a);

/*** Matrix transformations ***/
t_matrix	    create_translate(float a, float b, float c);
t_matrix	    create_scaling(float a, float b, float c);
t_matrix		create_x_rotation(float a);
t_matrix		create_y_rotation(float a);
t_matrix		create_z_rotation(float a);
t_matrix		create_shearing(float *p);

/*** Rays ***/
float			**create_ray(float *origin, float *direction);
float			*ray_position(float **r, float t);

/*** Spheres  ***/
t_intersections	intersects(t_object *sp, float **r);

/*** Intersections ***/
t_intersection	intersection(float t, char object);
t_intersections	intersections(int n, t_intersection i, ...);
t_intersection	hit(t_intersections xs);
float	        *normal_at(t_object *object, float *world_p);

/*** Printing ***/
int	paint_sphere_shadow(mlx_image_t *img);
int print_matrix(float **m, int size);

/*** Matrix utils ***/
t_matrix    create_identity(void);
void        clear_matrix(t_matrix *matrix, int i);

/*** Possible to remove maybe later who knows */
float	*four_one_multiply(float **a, float *b);
#endif
