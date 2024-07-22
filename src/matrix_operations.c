/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:14:29 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/22 11:32:50 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	**matrix_multiply(float **a, float **b)
{
	float	matrix[4][4];
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix[i][j] = (a[i][0] * b[0][j]) + (a[i][1] * b[1][j]) +
				(a[i][2] * b[2][j]) + (a[i][3] * b[3][j]);
			j++;
		}
		i++;
	}
	return (matrix);
}