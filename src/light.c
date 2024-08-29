/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:18:16 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/29 16:42:54 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_light	*point_light(float *pos, float *intensity)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->position = pos;
	light->color = conv_color_for(intensity);
	return (light);
}

float	*lighting(t_material	*m, t_light *l, float *point, t_vectors v)
{
	t_lighting	lighting;
	
	lighting.eff_color = 
}