/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations_two.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:21:11 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/21 11:59:45 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_matrix	create_shearing(float *p)
{
	t_matrix	matrix;

	matrix.m = malloc(4 * sizeof(float *));
	if (!matrix.m)
		return (matrix);
	matrix.m[0] = tuple(1, p[0], p[1], 0);
	matrix.m[1] = tuple(p[2], 1, p[3], 0);
	matrix.m[2] = tuple(p[4], p[5], 1, 0);
	matrix.m[3] = tuple(0, 0, 0, 1);
	return (matrix);
}

void	set_transform(t_object	*object, t_matrix matrix)
{
	object->transform = matrix;
	//if (matrix.type == TRANSLATION)
	//if (matrix.type == ROTATE)
	//if (matrix.type == SCALING)
	//if (matrix.type == SHEARING)
}