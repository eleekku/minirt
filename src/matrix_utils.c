/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:17:23 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/09 12:00:59 by xriera-c         ###   ########.fr       */
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
    free(matrix);
    matrix = NULL;
}

t_matrix    *create_identity(void)
{
    t_matrix    *matrix;
    int         i;

    matrix = malloc(sizeof(t_matrix));
    if (!matrix)
        return (NULL);
    matrix->size = 4;
    matrix->m = malloc(4 * sizeof(float *));
    if (!matrix->m)
    {
        free(matrix);
        return (NULL);
    }
    i = -1;
    while (++i < 4)
    {
        matrix->m[i] = tuple(0, 0, 0, 0);
        matrix->m[i][i] = 1;
        if (matrix->m[i] == NULL)
        {
            clear_matrix(matrix, i);
            return (NULL);
        }
    }
    return (matrix);
}
