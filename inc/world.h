/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:57:02 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/06 16:41:32 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	WORLD_H
# define	WORLD_H

# include "minirt.h"

typedef struct s_world
{
	int			number_objects;
	t_object	*objects;
	float		**light;
}	t_world;

typedef struct s_comp
{
	t_object	object;
	float		t;
	float		*point;
	float		*eyev;
	float		*normalv;
	t_bool		inside;
}	t_comp;

t_intersections	*intersect_world(t_world w, float **r);
t_comp			*prepare_computations(t_intersection i, float **ray);
void	clean_comp(t_comp *comp);

#endif