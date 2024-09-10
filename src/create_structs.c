/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:34:33 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/10 11:19:42 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_comp	*create_comp(t_intersection *i)
{
	t_comp	*comp;

	comp = malloc(sizeof(t_comp));
	if (!comp)
		return (NULL);
	comp->point = NULL;
	comp->eyev = NULL;
	comp->normalv = NULL;
	comp->t = i->t;
	comp->object = i->object;
	return (comp);
}

t_material	*create_material(void)
{
	t_material	*mat;

	mat = malloc(sizeof(t_material));
	if (!mat)
		return (NULL);
	mat->color = color(0, 0, 0);
	if (!mat->color)
	{
		free(mat);
		return (NULL);
	}
	mat->ambient = 0;
	mat->diffuse = 0;
	mat->specular = 0;
	mat->shininess = 0;
	return (mat);
}

t_object	*create_object(t_shape shape)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	obj->s = shape;
	obj->diameter = 1;
	obj->height = 1;
	obj->coord = create_point(0, 0, 0);
	obj->color = color(0, 0, 0);
	obj->material = create_material();
	obj->normv = create_vector(0, 0, 0);
	obj->transform = create_identity(4);
	if (!obj->coord || !obj->color || !obj->material || !obj->normv || obj->transform)
	{
		clean_object(obj);
		return (NULL);
	}
	return (obj);
}

t_world	*create_world(int n, t_light *light)
{
	t_world	*world;

	if (!light)
		return (NULL);
	world = malloc(sizeof(t_world));
	if (!world)
		return (NULL);
	world->number_objects = n;
	world->objects = malloc(n * sizeof(t_object));
	if (!world->objects)
	{
		free(world);
		return (NULL);
	}
	world->light = light;
	return (world);
}
