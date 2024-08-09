/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:40:31 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/18 15:21:00 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "../lib/Libft/libft.h"
//# include "MLX42/MLX42.h"

# define EPS 0.00001
# define TRUE 1
# define FALSE 0

typedef int     t_bool;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

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
	int 	color;
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
    t_sphere    *sp;
    t_plane     *pl;
    t_cylinder  *cy;
}   t_scene;

/* typedef struct	s_sphere
{
    t_tuple	center;
    float	diameter;
	t_color	color;
}	t_sphere;*/

typedef struct s_intersections
{
	int		count;
	char	object[100];
	float	t[100];
}	t_intersections;

//typedef struct s_ray
//{
  //  t_tuple origin;
    //t_tuple direction;
//}   t_ray;

typedef struct s_intersection
{
	float	t;
	char	object;
}	t_intersection;

void        free_array(char **args);
void        exit_error(char *msg, char **args);
t_bool      validate_values(char *arg, char **args);
char        **safe_split(char *string, char separator);
float       fill_value(char *arg, char **args, char **coordinates);


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

t_intersection	intersection(float t, char object);
t_intersections	intersections(int n, t_intersection i, ...);
*/

#endif
