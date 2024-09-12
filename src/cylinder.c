/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:12:25 by esalmela          #+#    #+#             */
/*   Updated: 2024/09/12 17:12:28 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static t_bool check_cap(float **ray, float t)
{
    float x;
    float z;

    x = ray[0][0] + t * ray[1][0];
    z = ray[0][2] + t * ray[1][2];

    if (x * x + z * z <= 1)
        return (TRUE);
    else
        return (FALSE);
}

static void intersect_caps(t_object *cylinder, float **ray, t_intersections *cross)
{
    float t;

    if (cylinder->closed == FALSE || fabs(ray[1][1]) < 1e-6)
        return;
    t = (cylinder->cylindermin - ray[0][1]) / ray[1][1];
    if (check_cap(ray, t))
    {
        cross->count++;
        cross->int_list[cross->count - 1].t = t;
    }
    t = (cylinder->cylindermax - ray[0][1]) / ray[1][1];
    if (check_cap(ray, t))
    {
        cross->count++;
        cross->int_list[cross->count - 1].t = t;
    }    
}

static void check_height(t_object *cylinder, t_cylindervalues *v, float **ray, t_intersections *cross)
{
    v->y0 = ray[0][1] + v->t0 * ray[1][1];
    if (cylinder->cylindermin < v->y0 && v->y0 < cylinder->cylindermax)
    {
        cross->count++;
        cross->int_list[cross->count - 1].t = v->t0;
    }
    v->y1 = ray[0][1] + v->t1 * ray[1][1];
    if (cylinder->cylindermin - 0.00001 < v->y1 && v->y1 <= cylinder->cylindermax + 0.00001)
    {
        cross->count++;
        cross->int_list[cross->count - 1].t = v->t1;
    }
}

static void ft_swap(float *a, float *b)
{
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

t_intersections *cylinder_intersect(t_object *cylinder, float **ray)
{
    t_intersections	*cross;
    t_cylindervalues v;

    cross = create_intersections();
    v.a = pow(ray[1][0], 2) + pow(ray[1][2], 2);
    if (!(fabs(v.a) < 1e-6))
    {
        v.b = (2 * ray[0][0] * ray[1][0]) + (2 * ray[0][2] * ray[1][2]);
        v.c = pow(ray[0][0], 2) + pow(ray[0][2], 2) - 1;
        v.disc = pow(v.b, 2) - (4 * v.a * v.c);
        if (v.disc < 0)
            return (cross);
        v.t0 = ((-v.b) - sqrt(v.disc)) / (2 * v.a);
        v.t1 = ((-v.b) + sqrt(v.disc)) / (2 * v.a);
        if (v.t0 > v.t1)
            ft_swap(&v.t0, &v.t1);
        check_height(cylinder, &v, ray, cross);
    }
    intersect_caps(cylinder, ray, cross);
    return (cross);
}