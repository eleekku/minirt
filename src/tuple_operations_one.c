/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:22:27 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/24 10:35:10 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	*tuple_add(float *a, float *b)
{
	float	*p;
	int		i;

	p = malloc(4 * sizeof(float));
	if (!p)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		p[i] = a[i] + b[i];
		i++;
	}
	if (p[3] == 2)
		printf("Error: Adding two points. Unexpected result\n");
	return (p);
}

float	*tuple_subs(float *a, float *b)
{
	float	*p;
	int		i;

	p = malloc(4 * sizeof(float));
	if (!p)
		return (NULL);
	i = 0;
//	printf("float a is %f, %f, %f, %f\n", a[0], a[1], a[2], a[3]);
	while (i < 4)
	{
		p[i] = a[i] - b[i];
		i++;
	}
	if (p[3] < 0)
	{
		printf("Error: Substracting wrong parameters. Unexpected result\n");
		exit(1);
	}
	return (p);
}

float	*negate_vector(float *a)
{
//	printf("this is what u passed %f\n", a[3]);
	return (tuple_subs(tuple(0, 0, 0, 0), a));
}

float	*scalar_multi_tuple(float *a, float n)
{
	float	*p;
	int		i;

	p = malloc(4 * sizeof(float));
	if (!p)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		p[i] = a[i] * n;
		i++;
	}
	return (p);
}

float	*scalar_div_tuple(float *a, float n)
{
	float	*p;
	int		i;

	p = malloc(4 * sizeof(float));
	if (!p)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		p[i] = a[i] / n;
		i++;
	}
	return (p);
}
