/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:20:16 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/17 13:29:57 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_tuple	point(float a, float b, float c)
{
	t_tuple	p;

	p.x = a;
	p.y = b;
	p.z = c;
	p.w = 1;
	return (p);
}

t_tuple	vector(float a, float b, float c)
{
	t_tuple	v;

	v.x = a;
	v.y = b;
	v.z = c;
	v.w = 0;
	return (v);
}
