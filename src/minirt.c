#include "../inc/minirt.h"
#include <string.h>

/*int	paint_sphere_shadow(mlx_image_t *img, t_sphere *sphere)
{
//	t_sphere sphere;
	t_intersections	xs;
	float *position, *ray_origin;
	float	y, x, wall_z;
	float wall_size, half, pixel_size, canvas_pixels;
	float world_y, world_x;
	float **ray;

	wall_z = 10;
	canvas_pixels = 1000;
	wall_size = 7;
	half = wall_size / 2;
	pixel_size = wall_size / canvas_pixels;
	ray_origin = tuple(-5,0,1, 1);
    printf("sphere: %f %f %f\n%f\n%d %d %d\n", sphere->center[0], sphere->center[1], sphere->center[2], sphere->diameter, sphere->color[0], sphere->color[1], sphere->color[2]);
//	sphere->color[0] = 0;
//	sphere.color[1] = 0;
//	sphere.color[2] = 0;
//	sphere.center[0] = 0;
//	sphere.center[1] = 0;
//	sphere.center[2] = 0;
//	sphere.diameter = 1;
	
	for (y = 0; y < canvas_pixels - 1; y++)
	{
		world_y = half - pixel_size * y;
		for (x = 0; x < canvas_pixels - 1; x++)
		{
			world_x = -half + pixel_size * x;
			position = tuple(world_x, world_y, wall_z, 1);
			ray = create_ray(ray_origin, normalize(tuple_subs(position, ray_origin)));
			xs = intersects(sphere, ray);
			if (hit(xs).t != -1)
			{
				mlx_put_pixel(img, x, y, 0xFF0000FF);
			}
		}
	}
	return (1);
}*/
void	movement(t_scene *scene, int direction)
{
	scene->key = 1;
	ft_memset(scene->img->pixels, 150, 1200 * 1200 * sizeof(int32_t));
	if (direction == 1)
	{
		scene->movement.y += -1;
	}
	if (direction == 2)
	{
        scene->movement.y += +1;
	}
	if (direction == 3)
	{
        scene->movement.x += -1;
	}
	if (direction == 4)
	{
        scene->movement.x += +1;
	}
	print_object(scene, scene->img);
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_scene	*scene;

	scene = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(scene->mlx);
	if (keydata.key == MLX_KEY_DOWN && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		movement(scene, 1);
	if (keydata.key == MLX_KEY_UP && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		movement(scene, 2);
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		movement(scene, 3);
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		movement(scene, 4);
/*
	if (keydata.key == MLX_KEY_1 && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		modify_altitude(map, 1);
	if (keydata.key == MLX_KEY_2 && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT))
		modify_altitude(map, -1);
*/
}

int	main(int argc, char **argv)
{
    t_scene scene;

    scene.spheres = 0;
    scene.planes = 0;
    scene.cylinders = 0;
    scene.movement.x = 0;
    scene.movement.y = 0;
    scene.movement.z = 0;

    if (argc != 2)
    {
        ft_printf(2, "Error\nPlease input one and only one file\n");
        exit (1);
    }
    check_file(argv[1], &scene, FALSE);
    scene.material = material(&scene);
    scene.light.color[0] = 201;
    scene.light.color[1] = 201;
    scene.light.color[2] = 201;

	scene.mlx = mlx_init(1080, 1080, "MLX42", true);
    
        if (!scene.mlx) exit(1);

    // Create a 250x250 image.
    scene.img = mlx_new_image(scene.mlx, 1200, 1200);

    // Set the channels of each pixel in our image to the maximum byte value of 255. 
    memset(scene.img->pixels, 150, scene.img->width * scene.img->height * sizeof(int));
    // Draw the image at coordinate (0, 0).
    mlx_image_to_window(scene.mlx, scene.img, 0, 0);
    print_object(&scene, scene.img);
//   paint_sphere_shadow(scene.img, &scene.sp[0], &scene, 0);
    mlx_key_hook(scene.mlx, &ft_hook, &scene);
    // Run the main loop and terminate on quit.  
    mlx_loop(scene.mlx);
    mlx_terminate(scene.mlx); 
    free(scene.sp);
    free(scene.cy);
    free(scene.pl);
    
    return (0);
}