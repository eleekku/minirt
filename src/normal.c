/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:14:21 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/10 11:26:53 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static float	*create_world_normal(t_matrix *m, float *object_n)
{
	t_matrix	*transposed;
	float		*result;

	transposed = transpose(m);
	result = four_one_multiply(transposed->m, object_n);
	clean_matrix(transposed, transposed->size);
	return (result);
}

static void	normal_cleaner(float *obj_p, float *p, float *obj_n, float **m)
{
	free(p);
	free(obj_p);
	free(obj_n);
	free(m);
}

float	*normal_at(t_object *object, float *world_p)
{
	float		*object_p;
	float		*object_normal;
	float		*world_normal;
	float		*p;
	t_matrix	*inverse;

	world_normal = world_p;
	inverse = inverse_matrix(object->transform);
	if (inverse->m == NULL)
		return (NULL);
	p = create_point(0, 0, 0);
	if (!p)
	{
		free(inverse->m);
		return (NULL);
	}
	object_p = four_one_multiply(inverse->m, world_p);
	object_normal = tuple_subs(object_p, p);
	world_normal = create_world_normal(inverse, object_normal);
	world_normal[3] = 0;
	normal_cleaner(object_p, p, object_normal, inverse->m);
	p = normalize(world_normal);
	free(world_normal);
	return (p);
}
