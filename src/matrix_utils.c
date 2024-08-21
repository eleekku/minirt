/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:17:23 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/21 12:39:51 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void    clear_matrix(t_matrix *matrix, int i)
{
    int j;

    j = 0;
    while (j < i)
    {
        free(matrix->m[j]);
        j++;
    }
    free(matrix->m);
    matrix->m = NULL;
}

t_matrix    create_identity(void)
{
    t_matrix    matrix;
    int         i;
    int         j;

    matrix.size = 4;
    matrix.m = malloc(4 * sizeof(float *));
    if (!matrix.m)
        return (matrix);
    matrix.m[0] = tuple(1, 0, 0, 0);
    matrix.m[1] = tuple(0, 1, 0, 0);
    matrix.m[2] = tuple(0, 0, 1, 0);
    matrix.m[3] = tuple(0, 0, 0, 1);
    i = -1;
    while (++i < 4)
    {
        if (matrix.m[i] = NULL)
        {
            clear_matrix(&matrix, i);
            break ;
        }
    }
    return (matrix);
}