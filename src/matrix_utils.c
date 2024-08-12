/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:24:51 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/12 15:27:44 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

float	cofactor(t_matrix a, int i, int j)
{
	int		k;
	float	min;

	min = minor(a, i, j);
	k = i + j;
	if (k % 2 == 0)
		return (min);
	else
		return (-min);
}
