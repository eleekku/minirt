/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:47:42 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/12 16:35:33 by xriera-c         ###   ########.fr       */
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
    //float   **r;
    //t_intersections xs;
    //t_intersection  i1;
    //t_intersection  i2, i3;
    //t_sphere    sp;
    //float   a[] = {0,0,5,PNT};
    //float   b[] = {0,0,1,0};
    //float   c[] = {0,0,0,1};

    //r = create_ray(a, b);
    //sp.center = c;
    //sp.diameter = 1;

    //xs = intersects(sp, r);
    //printf("Ray-Sphere intersection\nNumber of intersections: %d\nIntersection distance: [%f] [%f]\n", xs.count, xs.t[0], xs.t[1]);
    //i1 = intersection(-1,'s');
    //i2 = intersection(-3,'s');
    //i3 = intersection(-2, 's');
    //xs = intersections(3, i2, i1, i3);
    //printf("Ray-Sphere intersection\nNumber of intersections: %d\nIntersection distance: [%f] [%f]\n", xs.count, xs.t[0], xs.t[1]);
    //i1 = hit(xs);
    //printf("%f\n", i1.t);
    float a[] = {8,-5,9,2};
    float b[] = {7,5,6,1};
    float c[] = {-6,0,9,6};
    float d[] = {-3,0,-9,-4};
    //float ab[] = {-2,1,2,3};
    //float bb[] = {3, 2, 1, -1};
    //float cb[] = {4,3,6,5};
    //float db[] = {1,2,7,8};
    //float ac[] = {1,0,0,0};
    //float bc[] = {0,1,0,0};
    //float cc[] = {0,0,1,0};
    //float dc[] = {0,0,0,1};
    t_matrix  m1;
    t_matrix    m2;
    //t_matrix    m3;
	//float	**m2;
	//float	**m3;
    //float   **m4;
    //float   **m5;

    m1 = matrix(4, a, b, c, d);
    print_matrix(m1.m, 4);
    m2 = inverse_matrix(m1);
	print_matrix(m2.m, 4);
    print_matrix(transpose(m1).m, 4);
    //print_float_array(tuple(1, 2, 3, 1));
    //print_float_array(tuple(1, 2, 3, 0));
    //print_float_array(tuple_add(tuple(1, 2, 3, 1), tuple(1, 1, 1, 0)));
    //print_float_array(normalize(tuple(4,0,0,0)));
    //printf("%f\n", dot_product(tuple(1,2,3,0), tuple(2,3,4,0)));
    //print_float_array(vector_cross_prod(tuple(1,2,3,0), tuple(2,3,4,0)));
    //print_matrix(matrix_multiply(matrix(a, b, c, d), matrix(ab,bb,cb,db)));
    
	/*mlx_t* mlx = mlx_init(1080, 1080, "MLX42", true);
    
    if (!mlx) exit(1);

    // Create a 250x250 image.
    mlx_image_t* img = mlx_new_image(mlx, 250, 250);

    // Set the channels of each pixel in our image to the maximum byte value of 255. 
    memset(img->pixels, 180, img->width * img->height * sizeof(int));

    // Draw the image at coordinate (0, 0).
    mlx_image_to_window(mlx, img, 0, 0);

    // Run the main loop and terminate on quit.  
    mlx_loop(mlx);
    mlx_terminate(mlx);
*/
    
    return (0);
}
