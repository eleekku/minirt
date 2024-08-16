/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:40:31 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/15 15:35:08 by xriera-c         ###   ########.fr       */
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
//# include "MLX42/MLX42.h"

# define EPS 0.00001
# define TRUE 1
# define FALSE 0

typedef int     t_bool;

<<<<<<< HEAD
typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;
=======
# define PNT 1.0
# define VTR 0.0
# define ORIGIN 0
# define DIRECTION 1
>>>>>>> master

/* typedef struct  s_sphere
{
    float   coord[3];
    float   diameter;
    int     color[3];
}   t_sphere;*/

typedef struct  s_plane
{
    float       coord[3];
    float       normv[3];
    int         color[3];
}   t_plane;

typedef struct  s_cylinder
{
    float   coord[3];
    float   normv[3];
    float   diameter;
    float   height;
    int     color[3];
}   t_cylinder;

typedef struct	s_sphere
{
    float	center[3];
    float	diameter;
	int 	color[3];
}	t_sphere;


typedef struct s_scene
{
    float       alightr;
    int         amcolor[3];
    float         camc[3];
    float         normv[3];
    int         fow;
    float       lightc[3];
    float       brightness;
    int         spheres;
    int         planes;
    int         cylinders;
    t_sphere    *sp;
    t_plane     *pl;
    t_cylinder  *cy;
}   t_scene;

<<<<<<< HEAD
/* typedef struct	s_sphere
{
    t_tuple	center;
    float	diameter;
	t_color	color;
}	t_sphere;*/
=======
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
>>>>>>> master

typedef struct s_intersections
{
	int		count;
	char	object[100];
	float	t[100];
}	t_intersections;

<<<<<<< HEAD
//typedef struct s_ray
//{
  //  t_tuple origin;
    //t_tuple direction;
//}   t_ray;

=======
>>>>>>> master
typedef struct s_intersection
{
	float	t;
	char	object;
}	t_intersection;

<<<<<<< HEAD
void        free_array(char **args);
void        exit_error(char *msg, char **args, t_scene *scene);
t_bool      validate_values(char *arg, char **args, t_scene *scene);
char        **safe_split(char *string, char separator);
float       fill_value(char *arg, char **args, char **coordinates, t_scene *scene);


/*
t_tuple point(float a, float b, float c);
t_tuple vector(float a, float b, float c);

int equal_float(float a, float b);
t_tuple tuple_add(t_tuple a, t_tuple b);
t_tuple tuple_subs(t_tuple a, t_tuple b);
t_tuple negate_vector(t_tuple a);
t_tuple scalar_multi_tuple(t_tuple a, float n);
t_tuple scalar_div_tuple(t_tuple a, float n);
float   magnitude(t_tuple a);
t_tuple normalize(t_tuple a);
float dot_product(t_tuple a, t_tuple b);
t_tuple vector_cross_prod(t_tuple a, t_tuple b);

t_ray	create_ray(t_tuple origin, t_tuple direction);
t_tuple	ray_position(t_ray r, float t);

t_intersections	sp_cross(t_sphere sp, t_ray	r);
=======
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
t_matrix	    translation(float a, float b, float c);
t_matrix	    scaling(float a, float b, float c);
t_matrix	    x_rotation(float a);
t_matrix	    y_rotation(float a);
t_matrix        z_rotation(float a);

/*** Rays ***/
float			**create_ray(float *origin, float *direction);
float			*ray_position(float **r, float t);

/*** Spheres  ***/
//t_intersections	sp_cross(t_sphere sp, float **r);
t_intersections	intersects(t_sphere sp, float **r);
>>>>>>> master

t_intersection	intersection(float t, char object);
t_intersections	intersections(int n, t_intersection i, ...);
<<<<<<< HEAD
*/
=======
t_intersection	hit(t_intersections xs);
>>>>>>> master

/*** Printing ***/
int	paint_sphere_shadow(mlx_image_t *img);


/*** Possible to remove maybe later who knows */
float	*four_one_multiply(float **a, float *b);
#endif
