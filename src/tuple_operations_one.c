/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_operations_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:22:27 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/17 14:27:15 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_tuple	tuple_add(t_tuple a, t_tuple b)
{
	t_tuple	r;

	r.x = a.x + b.x;
	r.y = a.y + b.y;
	r.z = a.z + b.z;
	r.w = a.w + b.w;
	if (r.w == 2)
		printf("Error: Adding two points. Unexpected result\n");
	return (r);
}

t_tuple	tuple_subs(t_tuple a, t_tuple b)
{
	t_tuple	r;

	r.x = a.x - b.x;
	r.y = a.y - b.y;
	r.z = a.z - b.z;
	r.w = a.w - b.w;
	if (r.w < 0)
		printf("Error: Substracting wrong parameters. Unexpected result\n");
	return (r);
}

t_tuple	negate_vector(t_tuple a)
{
	return (tuple_subs(vector(0, 0, 0), a));
}

t_tuple	scalar_multi_tuple(t_tuple a, float n)
{
	t_tuple	r;

	r.x = a.x * n;
	r.y = a.y * n;
	r.z = a.z * n;
	r.w = a.w * n;
	return (r);
}

t_tuple	scalar_div_tuple(t_tuple a, float n)
{
	t_tuple	r;

	r.x = a.x / n;
	r.y = a.y / n;
	r.z = a.z / n;
	r.w = a.w / n;
	return (r);
}
