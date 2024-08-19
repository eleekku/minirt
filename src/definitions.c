/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:20:16 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/19 16:08:26 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static float	*tuple(float a, float b, float c, float w)
{
	float	*p;

	p = malloc(4 * sizeof(float));
	if (!p)
		return (NULL);
	p[0] = a;
	p[1] = b;
	p[2] = c;
	p[3] = w;
	return (p);
}

float	*create_point(float a, float b, float c)
{
	return (tuple(a, b, c, 1));
}

float	*create_vector(float a, float b, float c)
{
	return (tuple(a, b, c, 0));
}

//Could it be simplified to a 4x4 matrix?
t_matrix	matrix(int size, float *a, ...)
{
	va_list		ap;
	t_matrix	matrix;
	float		**m;
	int			j;

	m = malloc(size * sizeof(float *));
	if (!m)
	{
		matrix.size = 0;
		return (matrix);
	}
	matrix.size = size;
	va_start(ap,a);
	j = -1;
	while (++j < size)
	{
		m[j] = a;
		a = va_arg(ap, float *);
	}
	matrix.m = m;
	return (matrix);
}

t_matrix	initialize_matrix(t_matrix matrix)
{
	int	i;

	i = 0;
	while (i < matrix.size)
	{
		matrix.m[i] = tuple(0,0,0,0);
		if (matrix.m[i] == NULL)
			return matrix;
		i++;
	}
	return (matrix);
}

/*
float	**matrix(float *a, float *b, float *c, float *d)
{
	float	**matrix;
	
	matrix = malloc(4 * sizeof(float *));
	if (!matrix)
		return (NULL);
	matrix[0] = a;
	matrix[1] = b;
	matrix[2] = c;
	matrix[3] = d;
	return (matrix);
}
*/