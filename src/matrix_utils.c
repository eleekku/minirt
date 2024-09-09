/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:17:23 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/09 15:04:31 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_matrix	*create_matrix(int n)
{
	t_matrix    *matrix;
    int         i;

    matrix = malloc(sizeof(t_matrix));
    if (!matrix)
        return (NULL);
    matrix->size = n;
    matrix->m = malloc(n * sizeof(float *));
    if (!matrix->m)
    {
        free(matrix);
        return (NULL);
    }
    i = -1;
    while (++i < 4)
	{
        matrix->m[i] = tuple(0, 0, 0, 0);
        if (matrix->m[i] == NULL)
        {
            clean_matrix(matrix, i);
            return (NULL);
        }
    }
    return (matrix);
}

void    clean_matrix(t_matrix *matrix, int n)
{
    int j;

    j = 0;
    while (j < n)
    {
        free(matrix->m[j]);
        j++;
    }
    free(matrix->m);
    free(matrix);
    matrix = NULL;
}

t_matrix    *create_identity(int n)
{
    t_matrix    *matrix;
    int         i;

    matrix = create_matrix(n);
    if (!matrix)
        return (NULL);
    i = -1;
    while (++i < 4)
        matrix->m[i][i] = 1;
    return (matrix);
}
