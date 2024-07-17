/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:46:25 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/17 14:06:09 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	equal_float(float a, float b)
{
	if (fabs(a - b) < EPS)
		return (1);
	return (0);
}

float	magnitude(t_tuple a)
{
	float	n;

    if (a.w == 1)
        printf("Error: Magnitude failed. Value provided is not a vector\n.");
    n = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
    return (n);
}

t_tuple	normalize(t_tuple a)
{
    t_tuple	r;
    float	mag;

    mag = magnitude(a);
    r.x = a.x / mag;
    r.y = a.y / mag;
    r.z = a.z / mag;
    r.w = a.w / mag;
    return (r);
}

float	dot_product(t_tuple a, t_tuple b)
{
    float	r;
    
    r = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    return (r);
}

t_tuple	vector_cross_prod(t_tuple a, t_tuple b)
{
    t_tuple	r;

    if (a.w == 1 || b.w == 1)
        printf("Error: Cross product failed. Use vectors\n");
    r.x = a.y * b.z - a.z * b.y;
    r.y = a.z * b.x - a.x * b.z;
    r.z = a.x * b.y - a.y * b.x;
    r.w = 0;
    return (r);
}