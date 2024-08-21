/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:18:13 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/20 14:24:59 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_matrix	create_translate(float a, float b, float c)
{
	t_matrix matrix;

	matrix.size = 4;
	matrix.m = malloc(4 * sizeof(float *));
	if (!matrix.m)
		return (matrix);
	matrix.m[0] = tuple(1, 0, 0, a);
	matrix.m[1] = tuple(0, 1, 0, b);
	matrix.m[2] = tuple(0, 0, 1, c);
	matrix.m[3] = tuple(0, 0, 0, 1);
	return (matrix);
}

t_matrix	create_scaling(float a, float b, float c)
{
	t_matrix matrix;

	matrix.size = 4;
	matrix.m = malloc(4 * sizeof(float *));
	if (!matrix.m)
		return (matrix);
	matrix.m[0] = tuple(a, 0, 0, 0);
	matrix.m[1] = tuple(0, b, 0, 0);
	matrix.m[2] = tuple(0, 0, c, 0);
	matrix.m[3] = tuple(0, 0, 0, 1);
	return (matrix);

}

t_matrix	create_x_rotation(float a)
{
	t_matrix	matrix;
	matrix.size = 4;
	matrix.m = malloc(4 * sizeof(float *));
	if (!matrix.m)
		return (matrix);
	matrix.m[0] = tuple(1, 0, 0, 0);
	matrix.m[1] = tuple(0, cos(a), -sin(a), 0);
	matrix.m[2] = tuple(0, sin(a), cos(a), 0);
	matrix.m[3] = tuple(0, 0, 0, 1);
	return (matrix);

}

t_matrix	create_y_rotation(float a)
{
	t_matrix	matrix;
	matrix.size = 4;
	matrix.m = malloc(4 * sizeof(float *));
	if (!matrix.m)
		return (matrix);
	matrix.m[0] = tuple(cos(a), 0, sin(a), 0);
	matrix.m[1] = tuple(0, 1, 0, 0);
	matrix.m[2] = tuple(-sin(a), 0, cos(a), 0);
	matrix.m[3] = tuple(0, 0, 0, 1);
	return (matrix);

}
t_matrix	create_z_rotation(float a)
{
	t_matrix	matrix;
	matrix.size = 4;
	matrix.m = malloc(4 * sizeof(float *));
	if (!matrix.m)
		return (matrix);
	matrix.m[0] = tuple(cos(a), -sin(a), 0, 0);
	matrix.m[1] = tuple(sin(a), cos(a), 0, 0);
	matrix.m[2] = tuple(0, 0, 1, 0);
	matrix.m[3] = tuple(0, 0, 0, 1);
	return (matrix);

}