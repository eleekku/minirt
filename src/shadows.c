/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:49:14 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/12 16:05:42 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	is_shadowed_help(t_intersections *xs, float d)
{
	t_intersection	*i;

	i = hit(xs);
	if (!i)
		return (0);
	if (i->t != -1 && i->t < d)
	{
		free(i);
		return (1);
	}
	return (0);
}

int	is_shadowed(t_world *w, float *p)
{
	float			*v;
	float			*direction;
	float			**ray;
	float			distance;
	t_intersections	*xs;

	v = tuple_subs(w->light->coord, p);
	distance = magnitude(v);
	direction = normalize(v);
	ray = create_ray(p, direction);
	xs = intersect_world(w, ray);
	free(v);
	return (is_shadowed_help(xs, distance));
}