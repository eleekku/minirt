/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:05:34 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/12 09:52:24 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void	*clean_vectors(float *a, float *b, float *c, float *d)
{
	if (a)
		free(a);
	if (b)
		free(b);
	if (c)
		free(c);
	if (d)
		free(d);
	return (NULL);
}
/*
static void	initialize_vectors(float *a, float *b, float *c, float *d)
{
	a = NULL;
	b = NULL;
	c = NULL;
	d = NULL;
}
*/
static t_matrix	*orient(float *left, float *true_up, float *forw, float *from)
{
	t_matrix	*m;
	t_matrix	*result;
	t_matrix	*t;
	float		*neg_for;

	neg_for = negate_vector(forw);
	free(forw);
	if (!neg_for)
		return (NULL);
	m = create_populated_matrix(left, true_up, neg_for, create_point(0, 0, 0));
	if (!m)
		return (NULL);
	t = create_translate(-from[0], -from[1], -from[2]);
	if (!t)
	{
		clean_matrix(m, 4);
		return (NULL);
	}
	result = matrix_multiply(m, t);
	clean_matrix(m, 4);
	clean_matrix(t, 4);
	return (result);
}

t_matrix	*view_transform(float *from, float *to, float *up)
{
	float	*forward;
	float	*norm;
	float	*left;
	float	*true_up;
	float	*upn;

	forward = NULL;
	norm = NULL;
	left = NULL;
	true_up = NULL;
	//initialize_vectors(forward, norm, left, true_up);
	forward = tuple_subs(to, from);
	if (!forward)
		return (NULL);
	norm = normalize(forward);
	if (!norm)
		return (clean_vectors(forward, norm, left, true_up));
	upn = normalize(up);
	if (!upn)
		return (clean_vectors(forward, norm, left, true_up));
	left = vector_cross_prod(norm, upn);
	if (!left)
		return (clean_vectors(forward, norm, left, true_up));
	true_up = vector_cross_prod(left, norm);
	if (!true_up)
		return (clean_vectors(forward, norm, left, true_up));
	free(upn);
	free(forward);
	return (orient(left, true_up, norm, from));
}
