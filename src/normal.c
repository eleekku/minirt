/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:14:21 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/02 15:27:40 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	*normal_at(t_object *object, float *world_p)
{
	float	*object_p;
	float	*object_normal;
	float	*world_normal;
	float	*p;
	t_matrix	inverse;
	
	world_normal = world_p;
	inverse = inverse_matrix(object->transform);
	if (inverse.m == NULL)
		return (NULL);
	p = create_point(0, 0, 0);
	if (!p)
	{
		free(inverse.m);
		return (NULL);
	}
	object_p = four_one_multiply(inverse.m, world_p);
	object_normal = tuple_subs(object_p, p);
	world_normal = four_one_multiply(transpose(inverse).m, object_normal);
	world_normal[3] = 0;
	free(p);
	return (normalize(world_normal));
}