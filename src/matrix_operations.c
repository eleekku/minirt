/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:14:29 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/24 10:31:54 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	matrix_are_equal(float **a, float **b)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (equal_float(a[i][j], b[i][j] == 0))
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
