/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:14:21 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/10 13:34:49 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	*normal_at(t_object *object, float *world_p)
{
	float		*object_p;
	float		*object_normal;
	float		*world_normal;
	t_matrix	*transposed;
	t_matrix	*inverse;

	inverse = inverse_matrix(object->transform);
	if (!inverse)
		return (NULL);
	object_p = four_one_multiply(inverse, world_p);
	object_normal = create_vector(object_p[0], object_p[1], object_p[2]);
	transposed = transpose(inverse);
	world_normal = four_one_multiply(transposed, object_normal);
	world_normal[3] = 0;
	clean_matrix(transposed, transposed->size);
	clean_matrix(inverse, inverse->size);
	free(object_p);
	object_p = normalize(world_normal);
	free(world_normal);
	free(object_normal);
	return (object_p);
}
