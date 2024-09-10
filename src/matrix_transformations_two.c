/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transformations_two.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:21:11 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/10 11:11:07 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_matrix	*create_shearing(float *p)
{
	t_matrix	*matrix;

	matrix = create_identity(4);
	if (!matrix)
		return (NULL);
	matrix->m[0][1] = p[0];
	matrix->m[0][2] = p[1];
	matrix->m[1][0] = p[2];
	matrix->m[1][2] = p[3];
	matrix->m[2][0] = p[4];
	matrix->m[2][1] = p[5];
	return (matrix);
}
