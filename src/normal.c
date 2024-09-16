/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:14:21 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/16 10:52:57 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	*normal_at(t_object *object, float *world_p)
{
	float		*object_p;
	float		*object_normal;
	float		*world_normal;
	t_matrix	*transposed;
	
	object_p = four_one_multiply(object->transform, world_p, 0);
	object_normal = create_vector(object_p[0], object_p[1], object_p[2]);
	transposed = transpose(object->transform);
	world_normal = four_one_multiply(transposed, object_normal, 1);
	world_normal[3] = 0;
	clean_matrix(transposed, transposed->size);
	free(object_p);
	object_p = normalize(world_normal, 1);
	return (object_p);
}
