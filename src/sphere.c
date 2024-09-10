/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:50:17 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/10 15:37:57 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static float	*get_values(t_object *sp, float **r)
{
	float	*vals;
	float	*sp_to_ray;

	sp_to_ray = tuple_subs(r[ORIGIN], sp->coord);
	if (!sp_to_ray)
		return (NULL);
	vals = tuple(1, 1, 1, 1);
	if (!vals)
	{
		//free(sp_to_ray);
		return (NULL);
	}
	vals[0] = dot_product(r[DIRECTION], r[DIRECTION]);
	vals[1] = 2 * dot_product(r[DIRECTION], sp_to_ray);
	vals[2] = dot_product(sp_to_ray, sp_to_ray) - 1;
	free(sp_to_ray);
	return (vals);
}

t_intersections	*sphere_intersect(t_object *sp, float **r)
{
	t_intersections	*cross;
	float			*vals;
	float			discrim;

	cross = create_intersections();
	if (!cross)
		return (NULL);
	vals = get_values(sp, r);
	if (!vals)
		return (cross);
	discrim = vals[1] * vals[1] - (4 * vals[0] * vals[2]);
	if (discrim < 0)
	{
		free(vals);
		return (cross);
	}
	cross->int_list[0].t = (-vals[1] - sqrt(discrim)) / (2 * vals[0]);
	cross->int_list[1].t = (-vals[1] + sqrt(discrim)) / (2 * vals[0]);
	cross->int_list[0].object = sp;
	cross->int_list[1].object = sp;
	cross->count = 2;
	free(vals);
	return (cross);
}
