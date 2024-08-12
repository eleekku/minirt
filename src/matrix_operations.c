/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:14:29 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/12 16:37:01 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	matrix_are_equal(t_matrix a, t_matrix b)
{
	int	i;
	int	j;

	if (a.size != b.size)
		return (0);
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			if (equal_float(a.m[i][j], b.m[i][j] == 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

float	**matrix_multiply(float **a, float **b)
{
	float	**matrix;
	int		i;
	int		j;
	int		k;

	k = 1;
	if (sizeof(b) > sizeof(float) * 4)
		k = 4;
	matrix = malloc(4 * sizeof(float *));
	if (!matrix)
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		matrix[i] = tuple(0,0,0,0);
		if (matrix[i] == NULL)
			return (NULL);
		j = -1;
		while (++j < 4)
			matrix[i][j] = (a[i][0] * b[0][j]) + (a[i][1] * b[1][j]) 
				+ (a[i][2] * b[2][j]) + (a[i][3] * b[3][j]);
	}
	return (matrix);
}

t_matrix	transpose(t_matrix a)
{
	t_matrix	trans;
	int			i;
	int			j;

	trans.size = a.size;
	trans.m = malloc(a.size * sizeof(float *));
	if (!trans.m)
		return (trans);
	initialize_matrix(trans);
	i = -1;
	while (++i < a.size)
	{
		j = -1;
		while (++j < a.size)
			trans.m[i][j] = a.m[j][i];
	}
	return (trans);
}

float	cofactor(t_matrix a, int i, int j)
{
	int		k;
	float	min;

	min = minor(a, i, j);
	k = i + j;
	if (k % 2 == 0)
		return (min);
	else
		return (-min);
}