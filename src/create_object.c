/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:14:13 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/13 12:35:14 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_object	*create_sphere(float *coord, float scale, float *color)
{
	t_object	*sp;
	t_matrix	*tmp;
	t_matrix	*tmp2;

	sp = malloc(sizeof(t_object));
	if (!sp)
		return (NULL);
	sp->s = SPHERE;
	sp->coord = coord;
	sp->diameter = scale;
	sp->material = create_material(color);
	tmp = create_translate(coord[0], coord[1], coord[2]);
	tmp2 = create_scaling(scale, scale, scale);
	if (tmp && tmp2)
		sp->transform = matrix_multiply(tmp, tmp2);
	clean_matrix(tmp, 4);
	clean_matrix(tmp2, 4);
	if (sp->material && sp->transform)
		return (sp);
	clean_matrix(sp->transform, 4);
	clean_material(sp->material);
	free(coord);
	free(sp);
	return (NULL);
}
