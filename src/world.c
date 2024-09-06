/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:52:53 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/06 12:24:19 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/world.h"
#include "../inc/minirt.h"

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

t_intersections	*intersect_world(t_world w, float **r)
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
	while (++i < w.number_objects)
	{
		j = -1;
		r_temp = transform_ray(r, w.objects[i].transform.m);
		temp = sphere_intersect(w.objects[i], r_temp);
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

void	prepare_computations()