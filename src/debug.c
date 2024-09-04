/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:34:34 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/03 11:35:08 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int print_matrix(float **m, int size)
{
    int i;
    int j;

    i = 0;
    printf("Matrix: \n");
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            printf("%f ", m[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return (1);
}

int print_float_array(float *a)
{   
    int i;
    
    i = 0;
    printf("Vector: [");
    while (i < 3)
    {
        printf("%f, ", a[i]);
        i++;
    }
    printf("%f]\n", a[3]);
    return (0);
}