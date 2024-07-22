/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:57:03 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/22 10:43:22 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <stdarg.h>

static t_intersections	sort_intersect(int n, t_intersections xs)
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
			if (xs.t[j] > xs.t[k])
			{
				ftmp = xs.t[j];
				ctmp = xs.object[j];
				xs.t[j] = xs.t[k];
				xs.object[j] = xs.object[k];
				xs.t[k] = ftmp;
				xs.object[k] = ctmp;
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
		xs.object[k] = tmp.object;
		xs.t[k] = tmp.t;
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
		if (xs.t[k] >= 0)
		{
			i.t = xs.t[k];
			i.object = xs.object[k];
			return (i);
		}
		k++;
	}
	i.t = -1;
	return (i);
}
