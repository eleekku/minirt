/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:14:21 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/20 15:40:03 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	*normal_at(t_object *object, float *world_p)
{
	float	*object_p;
	//float	*object_normal;
	float	*world_normal;
	t_matrix	inverse;
	
	world_normal = world_p;
	inverse = inverse_matrix(object->transform);
	object_p = four_one_multiply(inverse.m, world_p);
	//object_normal = tuple_subs(object_p, create_point(0, 0, 0));
	//world_normal = four_one_multiply(transpose(inverse).m, object_normal);
	world_normal[4] = 0;
	return (normalize(world_normal));
}