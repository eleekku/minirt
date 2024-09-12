/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:06:26 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/12 13:52:25 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	clean_light(t_light	*light)
{
	if (light)
	{
		if (light->coord)
			free(light->coord);
		if (light->color)
			free(light->color);
		free(light);
	}
	light = NULL;
}

void	clean_intersections(t_intersections *inter)
{
	if (inter)
	{
		//if (inter->objects)
		//	free(inter->objects);
		//if (inter->t)
			//free(inter->t);
		free(inter);
	}
	inter = NULL;
}

void	clean_comp(t_comp *comp)
{
	if (comp)
	{
		if (comp->point)
			free(comp->point);
		if (comp->eyev)
			free(comp->eyev);
		if (comp->normalv)
			free(comp->normalv);
		//if (comp->object)
		//	free(comp->object);
		free(comp);
	}
	comp = NULL;
}

void	clean_material(t_material *mat)
{
	if (mat)
	{
		if (mat->color)
			free(mat->color);
		free(mat);
	}
	mat = NULL;
}

void	clean_object(t_object *obj)
{
	if (obj)
	{
		if (obj->coord)
			free(obj->coord);
		if (obj->color)
			free(obj->color);
		if (obj->normv)
			free(obj->normv);
		if (obj->material)
			clean_material(obj->material);
		if (obj->transform)
			clean_matrix(obj->transform, 4);
		free(obj);
	}
	obj = NULL;
}
