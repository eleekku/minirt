/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:03:01 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/17 15:24:00 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static float	clamp_color(float n)
{
	if (n > 255)
		return (255);
	return (n);
}

t_tuple	conv_color_for(t_tuple a)
{
	t_tuple	r;

	r.x = a.x / 256;
	r.y = a.y / 256;
	r.z = a.z / 256;
	r.w = 0;
	return (r);
}

t_tuple	conv_color_back(t_tuple a)
{
	t_tuple	r;

	r.x = clamp_color(a.x * 256);
	r.y = clamp_color(a.y * 256);
	r.z = clamp_color(a.z * 256);
	r.w = 0;
	return (r);
}