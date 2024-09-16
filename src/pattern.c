/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:12:35 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/16 17:17:27 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_pattern	*create_pattern(float *a, float *b, t_matrix *transf)
{
	t_pattern	*pat;

	pat = malloc(sizeof(t_pattern));
	if (!pat)
		return (NULL);
	pat->colora = a;
	pat->colorb = b;
	pat->transf = transf;
	return (pat);
}

static float	*checkers(t_pattern *pattern, float *p)
{
	if (fmod(floor(p[0]) + floor(p[1]) + floor(p[2]), 2) == 0)
		return (pattern->colora);
	return (pattern->colorb);
}

float	*checker_at_obj(t_comp *comp)
{
	float	*objp;
	float	*pattp;

	objp = four_one_multiply(comp->object->transform, comp->over_point, 0);
	if (!objp)
		return (NULL);
	pattp = four_one_multiply(comp->object->material->patt->transf, objp, 1);
	if (!pattp)
		return (NULL);
	return (checkers(comp->object->material->patt, pattp));
}