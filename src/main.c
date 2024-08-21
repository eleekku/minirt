/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:47:42 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/21 15:04:52 by xriera-c         ###   ########.fr       */
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
    //t_matrix    inv;
	//t_matrix 	m1;
    //t_matrix    scale;
    //t_matrix    rotate;
    //t_object    sphere;
	//float	*a, *b, *c, *d;

	//a = tuple(1, 0, 0, 0);
	//b = tuple(0, 1, 0, 0);
	//c = tuple(0, 0, 1, 0);
	//d = tuple(0, 0, 0, 1);
	//m1 = matrix(a, b, c, d);
	//inv = inverse_matrix(m1);

	//print_matrix(inv.m, 4);
    //t_object	sphere;
	float		*v, *n;

    //scale = create_scaling(1, 0.5, 1);
    //rotate = create_z_rotation(PI/5);
	//sphere.coord = create_point(0, 0, 0);
	//sphere.diameter = 1;
    //sphere.transform = matrix_multiply(scale.m, rotate.m);
	//n = normal_at(&sphere, create_point(0, sqrt(PI/2), -sqrt(PI/2)));
	//print_float_array(n);
    //free(n);
    v = create_vector(0, -1, 0);
    n = create_vector(sqrt(2)/2, sqrt(2)/2, 0);
    print_float_array(reflect(v, n));
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
