/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:57:03 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/05 15:34:02 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_intersections	sort_intersect(int n, t_intersections xs)
{
	float	ftmp;
	char	ctmp;
	int		k;
	int		j;

	k = 0;
	while (k < n)
	{
		j = 0;
		while (j < n)
		{
			if (xs.int_list[j].t > xs.int_list[k].t)
			{
				ftmp = xs.int_list[j].t;
				ctmp = xs.int_list[j].object;
				xs.int_list[j].t = xs.int_list[k].t;
				xs.int_list[j].object = xs.int_list[k].object;
				xs.int_list[k].t = ftmp;
				xs.int_list[k].object = ctmp;
			}
			j++;
		}
		k++;
	}
	return (xs);
}

t_intersection	intersection(float t, char object)
{
	t_intersection	i;

	i.t = t;
	i.object = object;
	return (i);
}

t_intersections	intersections(int n, t_intersection i, ...)
{
	va_list			ap;
	t_intersection	tmp;
	t_intersections	xs;
	int				k;

	k = 0;
	xs.count = n;
	va_start(ap, i);
	while (k < n)
	{
		tmp = i;
		if (k > 0)
			tmp = va_arg(ap, t_intersection);
		xs.int_list[k].object = tmp.object;
		xs.int_list[k].t = tmp.t;
		k++;
	}
	va_end(ap);
	xs = sort_intersect(n, xs);
	return (xs);
}

t_intersection	hit(t_intersections xs)
{
	t_intersection	i;
	int				k;

	k = 0;
	while (k < xs.count)
	{
		if (xs.int_list[k].t >= 0)
		{
			i.t = xs.int_list[k].t;
			i.object = xs.int_list[k].object;
			return (i);
		}
		k++;
	}
	i.t = -1;
	return (i);
}
