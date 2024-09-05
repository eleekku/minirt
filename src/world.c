/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:52:53 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/05 15:49:02 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/world.h"
#include "../inc/minirt.h"

t_intersections	intersect_world(t_world w, float **r)
{
	t_intersections	w_inters;
	t_intersections	temp;
	float			**r_temp;
	int				i;
	int				j;

	i = -1;
	w_inters.count = 0;
	w_inters.int_list = malloc(500 * sizeof(t_intersection));
	if (!w_inters.int_list)
		return (w_inters);
	while (++i < w.number_objects)
	{
		j = -1;
		r_temp = transform_ray(r, w.objects[i].transform.m);
		temp = sphere_intersect(w.objects[i], r_temp);
		while (++j < temp.count)
		{
			w_inters.count++;
			w_inters.int_list[(i * 2) + j].object = temp.int_list[j].object;
			w_inters.int_list[(i * 2) + j].t = temp.int_list[j].t;
		}
		free_matrix(r_temp);
	}
	w_inters= sort_intersect(w_inters.count, w_inters);
	return (w_inters);	
}

//void	prepare_computations()