/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 17:47:42 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/18 16:06:13 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


#include <stdlib.h>
#include <string.h>

int	main(void)
{
    t_sphere		sp;
    t_ray           r;
    t_intersections	cross;

    sp.center = point(0, 0, 0);
    sp.diameter = 1;

    r.origin = point(0, 0, -5);
    r.direction = vector(0, 0, 1);

    cross = sp_cross(sp, r);
	printf("%f %f %d\n", cross.t[0], cross.t[1], cross.count);

	cross = intersections(4, intersection(2, 's'), intersection(-4, 's'), intersection(5, 's'), intersection(0, 's'));	
	printf("%f %f %f %f %d\n", cross.t[0], cross.t[1], cross.t[2], cross.t[3], cross.count);
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
