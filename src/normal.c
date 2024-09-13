/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:14:21 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/12 14:29:45 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static float	*local_normal_at(t_shape shape, float *object_p, t_object *object)
{
	float dist;

	if (shape == PLANE)
		return (create_vector(0, 1, 0));
	if (shape == SPHERE)
		return (create_vector(object_p[0], object_p[1], object_p[2]));
	if (shape == CYLINDER)
	{
		dist = object_p[0] * object_p[0] + object_p[2] * object_p[2];
		if (dist < 1 && object_p[1] >= object->cylindermax - 1e-6)
			return(create_vector(0, 1, 0));
		else if (dist < 1 && object_p[1] <= object->cylindermin + 1e-6)
			return(create_vector(0, -1, 0));
		else
		return (create_vector(object_p[0], 0, object_p[2]));
	}
	else
		return (NULL);
}

float	*normal_at(t_object *object, float *world_p)
{
	float		*object_p;
	float		*object_normal;
	float		*world_normal;
	t_matrix	*transposed;
	//t_matrix	*inverse;

	//inverse = inverse_matrix(object->transform);
	//if (!inverse)
	//	return (NULL);
	object_p = four_one_multiply(object->transform, world_p);
	object_normal = local_normal_at(object->s, object_p, object);
	transposed = transpose(object->transform);
	world_normal = four_one_multiply(transposed, object_normal);
	world_normal[3] = 0;
	clean_matrix(transposed, transposed->size);
	//clean_matrix(inverse, inverse->size);
	free(object_p);
	object_p = normalize(world_normal);
	free(world_normal);
	free(object_normal);
	return (object_p);
}
