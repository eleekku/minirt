/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:57:03 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/09 14:37:09 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../inc/world.h"

t_intersections	*sort_intersect(int n, t_intersections *xs)
{
	float		ftmp;
	t_object	*ctmp;
	int			k;
	int			j;

	k = 0;
	while (k < n)
	{
		j = 0;
		while (j < n)
		{
			if (xs->int_list[j].t > xs->int_list[k].t)
			{
				ftmp = xs->int_list[j].t;
				ctmp = xs->int_list[j].object;
				xs->int_list[j].t = xs->int_list[k].t;
				xs->int_list[j].object = xs->int_list[k].object;
				xs->int_list[k].t = ftmp;
				xs->int_list[k].object = ctmp;
			}
			j++;
		}
		k++;
	}
	return (xs);
}

t_intersection	*intersection(float t, t_object *object)
{
	t_intersection	*i;

	i = malloc(sizeof(t_intersection));
	if (!i)
		return (NULL);
	i->t = t;
	i->object = object;
	return (i);
}

t_intersection	*hit(t_intersections *xs)
{
	t_intersection	*i;
	int				k;

	k = 0;
	i = malloc(sizeof(t_intersection));
	if (!i)
		return (NULL);
	while (k < xs->count)
	{
		if (xs->int_list[k].t >= 0)
		{
			i->t = xs->int_list[k].t;
			i->object = xs->int_list[k].object;
			return (i);
		}
		k++;
	}
	i->t = -1;
	return (i);
}
