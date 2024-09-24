/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:34:33 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/19 12:25:06 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_light	*create_light(void)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->coord = create_point(0, 0, 0);
	light->color = color(1, 1, 1);
	light->brightness = 0.5;
	return (light);
}

t_intersections	*create_intersections(void)
{
	t_intersections	*inter;

	inter = malloc(sizeof(t_intersections));
	if (!inter)
		return (NULL);
	inter->count = 0;
	inter->objects = malloc(16 * sizeof(t_object *));
	if (!inter->objects)
	{
		free(inter);
		return (NULL);
	}
	inter->t = malloc(16 * sizeof(float));
	if (!inter->t)
	{
		free(inter->objects);
		free(inter);
		return (NULL);
	}
	inter->objects[0] = NULL;
	return (inter);
}

t_comp	*create_comp(t_intersection *i)
{
	t_comp	*comp;

	comp = malloc(sizeof(t_comp));
	if (!comp)
		return (NULL);
	comp->point = NULL;
	comp->over_point = NULL;
	comp->eyev = NULL;
	comp->normalv = NULL;
	comp->t = i->t;
	comp->object = i->object;
	return (comp);
}

t_material	*create_material(t_parse *parse)
{
	t_material	*mat;

	mat = malloc(sizeof(t_material));
	if (!mat)
		return (NULL);
	mat->color = color(parse->amcolor[0], parse->amcolor[1], parse->amcolor[2]);
	if (!mat->color)
	{
		free(mat);
		return (NULL);
	}
	mat->ambient = 0.1;
	mat->diffuse = 0.9;
	mat->specular = 0.9;
	mat->shininess = 200;
	mat->pattern = FALSE;
	return (mat);
}

t_object	*create_object(t_shape shape, t_parse *parse)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	obj->s = shape;
	obj->diameter = 2;
	obj->height = 1;
	obj->coord = create_point(0, 0, 0);
	obj->color = color(0, 0, 0);
	obj->material = create_material(parse);
	obj->normv = create_vector(0, 0, 0);
	obj->transform = create_identity(4);
	obj->cylindermin = 0;
	obj->cylindermax = 1;
	if (!obj->coord || !obj->color || !obj->material ||
		!obj->normv || !obj->transform)
	{
		clean_object(obj);
		return (NULL);
	}
	return (obj);
}

t_world	*create_world(int n, t_light **lights)
{
	t_world	*world;

	if (!lights)
		return (NULL);
	world = malloc(sizeof(t_world));
	if (!world)
		return (NULL);
	world->number_objects = n;
	world->objects = malloc(n * sizeof(t_object *));
	if (!world->objects)
	{
		free(world);
		return (NULL);
	}
	world->lights = lights;
	return (world);
}
