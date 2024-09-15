/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:52:53 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/15 15:00:10 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static t_intersections *combine_xs(t_intersections *a, t_intersections *b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (a->objects[i])
		i++;
	while (b->objects[j])
	{
		a->t[i] = b->t[j];
		a->objects[i] = b->objects[j];
		a->count++;
		i++;
		j++;
	}
	a->objects[i] = NULL;
	free(b->objects);
	free(b);
	return (a);
}

t_intersections	*intersect_world(t_world *w, float **r)
{
	t_intersections	*w_inters;
	t_intersections	*temp;
	float			**r_temp;
	int				i;

	i = -1;
	w_inters = create_intersections();
	if (!w_inters)
		return (NULL);
	while (++i < w->number_objects)
	{
		r_temp = transform_ray(r, w->objects[i]->transform);
		temp = sphere_intersect(w->objects[i], r_temp);
		if (temp)
		{
			combine_xs(w_inters, temp);
			clean_ray(r_temp);
		}
	}
	sort_intersect(w_inters);
	return (w_inters);	
}

t_comp	*prepare_computations(t_intersection *i, float **ray)
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
	tmp = scalar_multi_tuple(comp->normalv, 0.01);
	comp->over_point = tuple_add(comp->point, tmp);
	free(tmp);
	return (comp);
}
