/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:20:16 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/22 13:03:34 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	*point(float a, float b, float c)
{
	float	*p;

	p = malloc(4 * sizeof(float));
	if (!p)
		return (NULL);
	p[0] = a;
	p[1] = b;
	p[2] = c;
	p[3] = 1;
	return (p);
}

float	*vector(float a, float b, float c)
{
	float	*p;

	p = malloc(4 * sizeof(float));
	p[0] = a;
	p[1] = b;
	p[2] = c;
	p[3] = 0;
	return (p);
}
