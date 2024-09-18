/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:40:31 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/16 16:30:26 by xriera-c         ###   ########.fr       */
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

typedef int	t_bool;

# define ORIGIN 0
# define DIRECTION 1

typedef enum e_shape
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_shape;

typedef enum e_transformation
{
	TRANSLATION,
	SCALING,
	ROTATE,
	SHEARING
}	t_transformation;

typedef struct s_matrix
{
	int					size;
	float				**m;
	t_transformation	type;
}	t_matrix;

typedef struct s_pattern
{
	float		*colora;
	float		*colorb;
	t_matrix	*transf;
}	t_pattern;

typedef struct s_material
{
	float		*color;
	float		ambient;
	float		diffuse;
	float		specular;
	float		shininess;
	t_pattern	*patt;
	t_bool		pattern;
}	t_material;

typedef struct s_light
{
	float	*color;
	float	*coord;
}	t_light;

typedef struct s_cylindervalues
{
    float a;
    float b;
    float c;
    float disc;
    float t0;
    float t1;
    float y0;
    float y1;
}   t_cylindervalues;


typedef struct s_object
{
    t_shape s;
    float   *coord;
    float   diameter;
    float	*color;
    t_matrix	*transform;
    float   *normv;
    float   height;
    t_material  *material;
    float   cylindermin;
    float   cylindermax;
    t_bool  closed;
}   t_object;

typedef struct s_world
{
	int			number_objects;
	t_object	**objects;
	t_light		*light;
}	t_world;

typedef struct s_comp
{
	t_object	*object;
	float		t;
	float		*point;
	float		*over_point;
	float		*eyev;
	float		*normalv;
	t_bool		inside;
}	t_comp;

typedef struct s_intersection
{
	float		t;
	t_object	*object;
}	t_intersection;

typedef struct s_intersections
{
	int			count;
	t_object	**objects;
	float		*t;
}	t_intersections;

typedef struct s_camera
{
	float		hsize;
	float		vsize;
	float		field;
	float		pixel_size;
	float		half_height;
	float		half_width;
	t_matrix	*transform;
}	t_camera;

typedef struct s_parse
{
    float       alightr;
    float       *amcolor;
    float       camc[3];
    float       normv[3];
    int         fow;
    float       lcoord[3];
    int         *lcolor;
    float       lbrightness;
    int         spheres;
    int         planes;
    int         cylinders;
}   t_parse;


/*typedef struct s_scene
{
    float       alightr;
    int         amcolor[3];
    float         camc[4];
    float         normv[4];
    int         fow;
    t_light     light;
    t_material  material;
    //t_lightdot  lightdot;
   // float       lightc[4];
    //float       brightness;
    t_object    *objects;
    int         spheres;
    int         planes;
    int         cylinders;
    t_sphere    *sp;
    t_plane     *pl;
    t_cylinder  *cy;
}   t_parse;
*/

/* Parsing */
t_object  **check_file(char *file, t_parse *parse, t_bool flag);
char    **safe_split(char *string, char separator);
void    free_array(char **args);
void    exit_error(char *msg, char **args, t_parse *parse);
t_bool    validate_values(char *arg);
t_bool    fill_value(char *arg, char **coordinates, float *value);
void    free_objects(t_parse *parse);
void    malloc_objects(t_parse *parse);
t_bool    parse_sphere(char **args, int index, t_object **object);
t_bool    parse_plane(char **args, int index, t_object **object);
t_bool    parse_cylinder(char **args, int index, t_object **object);
t_bool  validate_line(char **args, t_parse *parse);
t_bool fill_rgb(float **color, char *str);
void    free_objects_exit(t_object **object, char **args, int amount, t_parse *parse);


int				colors_to_int(int *colors, int intensity);
int				*combine_colors(int *a, int *b);
int				*multiply_scale(int *color, float scale);

//t_material  material(t_parse *parse, int i);
//int    *lighting(t_parse *parse, float *point, float *eyev, float *normalv);

/*** Definitions ***/
float			*tuple(float a, float b, float c, float w);
float			*create_point(float a, float b, float c);
float			*create_vector(float a, float b, float c);
t_matrix		*create_matrix(int n);
t_matrix		*create_populated_matrix(float *a, float *b, float *c, float *d);
float			*color(float a, float b, float c);
t_material		*create_material(void);
t_object		*create_object(t_shape shape);
t_matrix		*create_identity(int n);
t_comp			*create_comp(t_intersection *i);
t_intersections	*create_intersections(void);
t_comp			*create_comp(t_intersection *i);
t_camera		*create_camera(float hsize, float vsize, float field);
t_world			*create_world(int n, t_light *light);

/*** Shapes  ***/
t_object *test_object(t_shape type);

/*** Tuple Operations ***/
int				equal_float(float a, float b);
float			*tuple_add(float *a, float *b);
float			*tuple_subs(float *a, float *b);
float			*negate_vector(float *a);
float			*tuple_add(float *a, float *b);
float			*scalar_multi_tuple(float *a, float n);
float			*scalar_div_tuple(float *a, float n);
float			magnitude(float *a);
float			*normalize(float *a, int delete);
float			dot_product(float *a, float *b);
float			*vector_cross_prod(float *a, float *b);
float			*normal_at(t_object *object, float *world_p);

/*** Matrix operations ***/
int				matrix_are_equal(t_matrix *a, t_matrix *b);
t_matrix		*matrix_multiply(t_matrix *a, t_matrix *b, int delete);
t_matrix		*submatrix(t_matrix *a, int i, int j);
t_matrix		*transpose(t_matrix *a);
float			minor(t_matrix *a, int i, int j);
float			cofactor(t_matrix *a, int i, int j);
float			determinant(t_matrix *a);
t_matrix		*inverse_matrix(t_matrix *a);
float			*four_one_multiply(t_matrix *a, float *b, int delete);

/*** Matrix transformations ***/
t_matrix		*create_translate(float a, float b, float c);
t_matrix		*create_scaling(float a, float b, float c);
t_matrix		*create_x_rotation(float a);
t_matrix		*create_y_rotation(float a);
t_matrix		*create_z_rotation(float a);
t_matrix		*create_shearing(float *p);
t_matrix		*view_transform(float *from, float *to, float *up);

/*** Rays ***/
float			**create_ray(float *origin, float *direction);
float			*ray_position(float **r, float t);
float			**transform_ray(float **ray, t_matrix *matrix);
float			**ray_for_pixel(t_camera *c, float px, float py);

/*** Spheres
t_intersections	intersects(t_sphere *sp, float **r);
t_intersection	intersection(float t, t_object object);
t_intersections	intersections(int n, t_intersection i, ...);
t_intersection	hit(t_intersections xs);
t_intersections	sphere_intersect(t_object sp, float **r);
 ***/
//int paint_sphere_shadow(mlx_image_t *img, t_sphere *sphere, t_parse *parse);
//float	        *normal_at(t_object *object, float *world_p);
float	*reflect(float *vector, float *normal);

/*** Printing ***/
//int	paint_sphere_shadow(mlx_image_t *img);
int print_matrix(float **m, int size);
int print_float_array(float *a);

/*** Matrix utils ***/

/*** Possible to remove maybe later who knows */
float	*four_one_multiply(t_matrix *a, float *b);

/*** Color ***/
float	*conv_color_for(float *a);
int	    *conv_color_back(float *a);

//t_intersections	*sort_intersect(int n, t_intersections *xs);

/*** Cleaning structs ***/
void	    clean_material(t_material *mat);
void	    clean_object(t_object *obj);
void        clean_matrix(t_matrix *matrix, int n);
void	    clean_comp(t_comp *comp);
void	    clean_intersections(t_intersections *inter);
void	    clean_light(t_light	*light);
void	    clean_ray(float **ray);
void	    clean_world(t_world	*w);
void	    clean_points(float *a, float *b, float *c, float *d);
void        clean_parse(t_parse *parse);

float	*shade_hit(t_world	*w, t_comp *comp);
float	*hadamard(float *a, float *b);
float	*multiply_color(float *a, float b);
float	*add_colors(float *a, float *b, float *c);
float	*lighting(t_comp *comp, t_world *w, t_object *object, int shadow);
t_intersections	*intersect_world(t_world *w, float **r);
t_comp			*prepare_computations(t_intersection *i, float **ray);
t_matrix	*view_transform(float *from, float *to, float *up);

//t_intersections	*intersects(t_sphere *sp, float **r);
t_intersection	*intersection(float t, t_object *object);
//t_intersections	intersections(int n, t_intersection i, ...);
t_intersection	*hit(t_intersections *xs);
t_intersections	*sphere_intersect(t_object *sp, float **r);
t_intersections	*sort_intersect(t_intersections *xs);
t_intersections	*intersect_world(t_world *w, float **r);
t_intersection	*intersection(float t, t_object *object);
t_intersection	*hit(t_intersections *xs);
t_intersections *pre_intersect(t_object *object, float **ray);
t_intersections *plane_intersect(t_object *plane, float **ray);
t_intersections *cylinder_intersect(t_object *cylinder, float **ray);
t_comp			*prepare_computations(t_intersection *i, float **ray);

/*** Color utils ***/
float			*hadamard(float *a, float *b);
float			*multiply_color(float *a, float b, int delete);
float			*add_colors(float *a, float *b, float *c);
float			*conv_color_for(float *a);
int				*conv_color_back(float *a);

/*** Color calculations ***/
float			*lighting(t_comp *comp, t_world *w, t_object *obj, int shadow);
float			*shade_hit(t_world	*w, t_comp *comp);
float			*reflect(float *vector, float *normal);
float			*color_at(t_world *w, float **ray);
int				is_shadowed(t_world *w, float *p);
int				render(t_camera *camera, t_world *world);
t_pattern		*create_pattern(float *a, float *b, t_matrix *transf);
float			*checker_at_obj(t_comp *comp);
//float			*checker_at_obj(t_pattern *patt, t_object *obj, float *wp);

/*** Cleaning structs ***/
void			clean_material(t_material *mat);
void			clean_object(t_object *obj);
void			clean_matrix(t_matrix *matrix, int n);
void			clean_comp(t_comp *comp);
void			clean_intersections(t_intersections *inter);
void			clean_light(t_light	*light);
void			clean_ray(float **ray);
void			clean_world(t_world	*w);
void			clean_points(float *a, float *b, float *c, float *d);

/*** Debugging ***/
int				print_matrix(float **m, int size);
int				print_float_array(float *a);

#endif