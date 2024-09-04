/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:46:54 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/04 13:06:33 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	transform_ray(float **ray, float **matrix)
{
	//float	*tmp;
	
	//tmp = ray[0];
	ray[0] = four_one_multiply(matrix, ray[0]);
	//tmp = ray[1];
	ray[1] = four_one_multiply(matrix, ray[1]);
}

float	**create_ray(float *origin, float *direction)
{
	float	**r;

	r = malloc(2 * sizeof(float *));
	if (!r)
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
	r[0] = origin;
	r[1] = direction;
	return (r);
}
float	*ray_position(float **r, float t)
{
	float	*p;
	int		i;

	p = malloc(4 * sizeof(float));
	if (!p)
		return (NULL);
	i = 0;
//	printf("float t is %f\n", t);
	while (i < 3)
	{	
//		printf("r[0][i] = %f and r[1][i] = %f\n", r[0][i], r[1][i]);
		p[i] = r[0][i] + r[1][i] * t;
//		printf("p[i] is %f\n", p[i]);
		i++;
	}
	p[i] = 1;
	return (p);
}
