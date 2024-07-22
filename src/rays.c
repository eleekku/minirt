/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:46:54 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/22 15:36:12 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	**create_ray(float *origin, float *direction)
{
	float	**p;

	p = malloc(2 * 4 * sizeof(float));
	if (!p)
		return (NULL);
	if (origin[3] == 0)
	{
		printf("Error: Origin is a vector\n");
		; //Need to change
	}
	if (direction[3] == 1)
	{
		printf("Error: Direction is a point\n");
		; //Need to change
	}
	p[0] = origin;
	p[1] = direction;
	return (p);
}
float	*ray_position(float **r, float t)
{
	float	*p;
	int		i;

	p = malloc(4 * sizeof(float));
	if (!p)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		p[i] = r[0][i] + r[1][i] * t;
		i++;
	}
	return (p);
}
