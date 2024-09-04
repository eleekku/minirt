/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:07:16 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/04 11:38:10 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	determinant(t_matrix a)
{
	float	d;
	int		i;

	if (a.size == 2)
		d = (a.m[0][0] * a.m[1][1]) - (a.m[0][1] * a.m[1][0]);
	else
	{
		i = -1;
		d = 0;
		while (++i < a.size)
			d += (a.m[0][i] * cofactor(a, 0, i));
	}
	return (d);
}

static	float	*copy_row(float *row, int i)
{
	float	*new_row;
	int		k;

	new_row = tuple(0, 0, 0, 0);
	if (!new_row)
		return (NULL);
	k = -1;
	while (++k < i)
		new_row[k] = row[k];
	while (++k < 4)
		new_row[k - 1] = row[k];
	return (new_row);
}

t_matrix	submatrix(t_matrix a, int i, int j)
{
	t_matrix	subm;
	float		**matrix;
	int			k;

	subm.size = a.size - 1;
	matrix = malloc(a.size * sizeof(float *));
	if (!matrix)
		return (subm);
	k = -1;
	while (++k < i)
		matrix[k] = copy_row(a.m[k], j);
	while (++k < a.size)
		matrix[k - 1] = copy_row(a.m[k], j);
	matrix[a.size - 1] = NULL;
	subm.m = matrix;
	return (subm);
}

float	minor(t_matrix a, int i, int j)
{
	t_matrix	matrix;
	float		det;

	matrix = submatrix(a, i, j);
	det = determinant(matrix);
	free_matrix(matrix.m);
	return (det);
}

t_matrix	inverse_matrix(t_matrix a)
{
	t_matrix	inv;
	int			i;
	int			j;
	float		c;

	inv.m = NULL;
	if (determinant(a) == 0)
		return (inv);
	inv.m = malloc(4 * sizeof(float *));
	if (!inv.m)
		return (inv);
	inv.size = 4;
	initialize_matrix(inv);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			c = cofactor(a, i, j);
			inv.m[j][i] = c / determinant(a);
		}
	}
	return (inv);
}
