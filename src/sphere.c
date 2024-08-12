/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:50:17 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/22 15:29:30 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
/*
t_intersections	sp_cross(t_sphere sp, t_ray	r)
{
	t_intersections	cross;
	t_tuple			sp_to_ray;
	t_tuple			values;
	float			discriminant;

	cross.count = 0;
	sp_to_ray = tuple_subs(r.origin, sp.center);
	values.x = dot_product(r.direction, r.direction);
	values.y = 2 * dot_product(r.direction, sp_to_ray);
	values.z = dot_product(sp_to_ray, sp_to_ray) - 1;
	discriminant = values.y * values.y - (4 * values.x * values.z);
	if (discriminant >= 0)
	{
		cross.t[0] = (-values.y - sqrt(discriminant)) / (2 * values.x);
		cross.t[1] = (-values.y + sqrt(discriminant)) / (2 * values.x);
		cross.object[0] = 's';
		cross.object[1] = 's';
		cross.count = cross.count + 2;
	}
	return (cross);
}*/
