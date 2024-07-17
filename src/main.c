/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:47:42 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/17 14:30:40 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


#include <stdlib.h>
#include <string.h>

int	main(void)
{
	mlx_t* mlx = mlx_init(1080, 1080, "MLX42", true);
    
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

    return (0);
}
