/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:46:54 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/10 13:20:04 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	**transform_ray(float **ray, t_matrix *matrix)
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

	if (origin[3] == 0 || direction[3] == 1)
	{
		printf("Error: Wrong ray input\n");
		return (NULL);
	}
	r = malloc(2 * sizeof(float *));
	if (!r)
		return (NULL);
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
	while (i < 3)
	{	
		p[i] = r[0][i] + r[1][i] * t;
		i++;
	}
	p[i] = 1;
	return (p);
}
