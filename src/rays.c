/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:46:54 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/05 14:02:47 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	**transform_ray(float **ray, float **matrix)
{
	float	**trans;
	float	*p;
	float	*v;
	
	p = four_one_multiply(matrix, ray[0]);
	if (!p)
		return (NULL);
	v = four_one_multiply(matrix, ray[1]);
	if (!v)
	{
		free(p);
		return (NULL);
	}
	trans = create_ray(p, v);
	if (!trans)
	{
		free(v);
		free(p);
		return (NULL);
	}
	return (trans);
}

float	**create_ray(float *origin, float *direction)
{
	float	**r;

	r = malloc(3 * sizeof(float *));
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
	r[2] = NULL;
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
