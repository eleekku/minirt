/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:52:53 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/07 18:08:17 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/world.h"
#include "../inc/minirt.h"

static t_comp	*create_comp(t_intersection i)
{
	t_comp	*comp;

	comp = malloc(sizeof(t_comp));
	if (!comp)
		return (NULL);
	comp->point = NULL;
	comp->eyev = NULL;
	comp->normalv = NULL;
	comp->t = i.t;
	comp->object = &i.object;
	return (comp);
}

void	clean_comp(t_comp *comp)
{
	if (comp->point)
		free(comp->point);
	if (comp->eyev)
		free(comp->eyev);
	if (comp->normalv)
		free(comp->normalv);
	free(comp);
}

static t_intersections	*create_world_intersections(void)
{
	t_intersections	*world;
	
	world = malloc(sizeof(t_intersections));
	if (!world)
		return (NULL);
	world->count = 0;
	world->int_list = malloc(1000 * sizeof(t_intersection));
	if (!world->int_list)
	{
		free(world);
		return (NULL);
	}
	return (world);
}

t_intersections	*intersect_world(t_world *w, float **r)
{
	t_intersections	*w_inters;
	t_intersections	temp;
	float			**r_temp;
	int				i;
	int				j;

	i = -1;
	w_inters = create_world_intersections();
	if (!w_inters->int_list)
		return (w_inters);
	while (++i < w->number_objects)
	{
		j = -1;
		r_temp = transform_ray(r, w->objects[i].transform.m);
		temp = sphere_intersect(w->objects[i], r_temp);
		while (++j < temp.count)
		{
			w_inters->count++;
			w_inters->int_list[(i * 2) + j].object = temp.int_list[j].object;
			w_inters->int_list[(i * 2) + j].t = temp.int_list[j].t;
		}
		free(temp.int_list);
		free_matrix(r_temp);
	}
	w_inters  = sort_intersect(w_inters->count, w_inters);
	return (w_inters);	
}

t_comp	*prepare_computations(t_intersection i, float **ray)
{
	t_comp	*comp;
	float	*tmp;

	comp = create_comp(i);
	if (!comp)
		return (NULL);
	comp->point = ray_position(ray, comp->t);
	comp->eyev = negate_vector(ray[1]);
	comp->normalv = normal_at(comp->object, comp->point);
	if (!comp->point || !comp->eyev || !comp->normalv)
	{
		clean_comp(comp);
		return (NULL);
	}
	if (dot_product(comp->normalv, comp->eyev) < 0)
	{
		comp->inside = TRUE;
		tmp = comp->normalv;
		comp->normalv = negate_vector(comp->normalv);
		free(tmp);
	}
	else
		comp->inside = FALSE;
	return (comp);
}
