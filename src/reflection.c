/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:49:26 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/21 14:57:08 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	*reflect(float *vector, float *normal)
{
	float	r;

	r = 2 * dot_product(vector, normal);
	return (tuple_subs(vector, scalar_multi_tuple(normal, r)));
}