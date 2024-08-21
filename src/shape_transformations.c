/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_transformations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:52 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/20 14:33:46 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	translate_object(t_object *object, t_matrix	matrix)
{
	float	*temp;
	
	temp = object->coord;
	object->coord = four_one_multiply(matrix.m, object->coord);
	free(temp);
}

void	scale_object(t_object *object, t_matrix matrix)
{
	
}