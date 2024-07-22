/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:47:42 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/22 15:33:13 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <string.h>

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
    print_float_array(point(1, 2, 3));
    print_float_array(vector(1, 2, 3));
    print_float_array(tuple_add(point(1, 2, 3), vector(1, 1, 1)));
    
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
