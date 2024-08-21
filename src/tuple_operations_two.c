/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:46:25 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/22 15:34:25 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	equal_float(float a, float b)
{
	if (fabs(a - b) < EPS)
		return (1);
	return (0);
}

float	magnitude(float *a)
{
	float	n;

    if (a[3] == 1)
        printf("Error: Magnitude failed. Value provided is not a vector\n.");
    n = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
    return (n);
}

float   *normalize(float *a)
{
    float	*p;
    float   mag;
	int		i;

	p = malloc(4 * sizeof(float));
	if (!p)
		return (NULL);
	i = 0;
    mag = magnitude(a);
	if (mag == 0)
	printf("mag is %f\n", mag);
	while (i < 4)
	{
		p[i] = a[i] / mag;
		i++;
	}
    return (p);
}

float   dot_product(float *a, float *b)
{
    float	p;
	int		i;

    p = 0;
	i = 0;
	while (i < 4)
	{
		p = p + (a[i] * b[i]);
		i++;
	}
    return (p);
}

float	*vector_cross_prod(float *a, float *b)
{
	float	*p;
	
    if (a[3] == 1 || b[3] == 1)
	{
        printf("Error: Cross product failed. Use vectors\n");
	}
	p = malloc(4 * sizeof(float));
	if (!p)
		return (NULL);
	p[0] = (a[1] * b[2]) - (a[2] * b[1]);
    p[1] = (a[2] * b[0]) - (a[0] * b[2]);
    p[2] = (a[0] * b[1]) - (a[1] * b[0]);
    p[3] = 0; 
	return (p);
}
