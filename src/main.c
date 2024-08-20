/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:47:42 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/20 16:04:27 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <string.h>

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

int	main(void)
{
    t_matrix    inv;
	t_matrix 	m1;
	float	*a, *b, *c, *d;

	a = tuple(-5, 2, 6, -8);
	b = tuple(1, -5, 1, 8);
	c = tuple(7, 7, -6, -7);
	d = tuple(1, -3, 7, 4);
	m1 = matrix(a, b, c, d);
	inv = inverse_matrix(m1);

	print_matrix(inv.m, 4);
    /*t_object	sphere;
	float		*n;

	sphere.coord = create_point(0, 0, 0);
	sphere.diameter = 1;
	n = normal_at(&sphere, create_point(0, 1, 0));
    */
	//print_float_array(n);
	//mlx_t* mlx = mlx_init(1080, 1080, "MLX42", true);
    
  //  if (!mlx) exit(1);

    // Create a 100x100 image.
//    mlx_image_t* img = mlx_new_image(mlx, 1000, 1000);

    // Set the channels of each pixel in our image to the maximum byte value of 255. 
//    memset(img->pixels, 255, img->width * img->height * sizeof(int));

    // Draw the image at coordinate (0, 0).
//    mlx_image_to_window(mlx, img, 0, 0);
 //   paint_sphere_shadow(img);
    // Run the main loop and terminate on quit.  
    //mlx_loop(mlx);
    //mlx_terminate(mlx);
    return (0);
}
