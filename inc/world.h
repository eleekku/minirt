/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:57:02 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/06 12:16:42 by xriera-c         ###   ########.fr       */
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

t_intersections	*intersect_world(t_world w, float **r);

#endif