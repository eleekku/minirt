/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:57:03 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/12 16:06:14 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_intersections	*sort_intersect(t_intersections *xs)
{
	float		ftmp;
	t_object	*ctmp;
	int			k;
	int			j;

	k = 0;
	while (xs->objects[k])
	{
		j = 0;
		while (xs->objects[j])
		{
			if (xs->t[j] > xs->t[k])
			{
				ftmp = xs->t[j];
				ctmp = xs->objects[j];
				xs->t[j] = xs->t[k];
				xs->objects[j] = xs->objects[k];
				xs->t[k] = ftmp;
				xs->objects[k] = ctmp;
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
	while (xs->objects[k])
	{
		if (xs->t[k] >= 0)
		{
			i->t = xs->t[k];
			i->object = xs->objects[k];
			return (i);
		}
		k++;
	}
	i->t = -1;
	return (i);
}
