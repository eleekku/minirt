/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_structs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:06:26 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/09 14:15:19 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/world.h"

void	clean_comp(t_comp *comp)
{
	if (comp->point)
		free(comp->point);
	if (comp->eyev)
		free(comp->eyev);
	if (comp->normalv)
		free(comp->normalv);
	if (comp->object)
		free(comp->object);
	free(comp);
}

void	clean_material(t_material *mat)
{
	if (mat->color)
		free(mat->color);
	if (mat)
		free(mat);
}

void	clean_object(t_object *obj)
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
	if (obj)
		free(obj);
}
