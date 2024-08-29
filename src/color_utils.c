/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:03:01 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/29 15:16:59 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static float	clamp_color(float n)
{
	if (n > 255)
		return (255);
	return (n);
}

float	*conv_color_for(float *a)
{
	float	*r;

	r = create_vector(0, 0, 0);
	if (!r)
		return (NULL);
	r[0] = a[0] / 256;
	r[1] = a[1] / 256;
	r[2] = a[2] / 256;
	r[3] = 0;
	return (r);
}

float	*conv_color_back(float *a)
{
	float	*r;

	r = create_vector(0, 0, 0);
	if (!r)
		return (NULL);
	r[0] = clamp_color(a[0] * 256);
	r[1] = clamp_color(a[1] * 256);
	r[2] = clamp_color(a[2] * 256);
	r[3] = 0;
	return (r);
}