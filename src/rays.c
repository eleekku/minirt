/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:46:54 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/18 15:15:47 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	r;

	if (origin.w == 0)
	{
		printf("Error: Origin is a vector\n");
		; //Need to change
	}
	if (direction.w == 1)
	{
		printf("Error: Direction is a point\n");
		; //Need to change
	}
	r.origin = origin;
	r.direction = direction;
	return (r);
}

t_tuple	ray_position(t_ray r, float t)
{
	t_tuple	pos;

	pos.x = r.origin.x + r.direction.x * t;
	pos.y = r.origin.y + r.direction.y * t;
	pos.z = r.origin.z + r.direction.z * t;
	return (pos);
}
