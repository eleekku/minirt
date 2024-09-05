/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:50:17 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/20 13:53:15 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_intersections	intersects(t_sphere *sp, float **r)
{
	t_intersections	cross;
	float			*sp_to_ray;
	float			*values;
	float			discriminant;

	cross.count = 0;
	sp_to_ray = tuple_subs(r[ORIGIN], sp->center);
	values = tuple(1,1,1,1);
	if (!values)
		return (cross);
	values[0] = dot_product(r[DIRECTION], r[DIRECTION]);
	values[1] = 2 * dot_product(r[DIRECTION], sp_to_ray);
	values[2] = dot_product(sp_to_ray, sp_to_ray) - 1;
	discriminant = values[1] * values[1] - (4 * values[0] * values[2]);
	if (discriminant >= 0)
	{
		cross.t[0] = (-values[1] - sqrt(discriminant)) / (2 * values[0]);
		cross.t[1] = (-values[1] + sqrt(discriminant)) / (2 * values[0]);
		cross.object[0] = 's';
		cross.object[1] = 's';
		cross.count = cross.count + 2;
	}
	free(sp_to_ray);
	free(values);
	return (cross);
}
