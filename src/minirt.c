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

int	main(int argc, char **argv)
{
    t_scene scene;
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
    
    scene.spheres = 0;
    scene.planes = 0;
    scene.cylinders = 0;

    if (argc != 2)
    {
        ft_printf(2, "Error\nPlease input one and only one file\n");
        exit (1);
    }
    check_file(argv[1], &scene, FALSE);
    //scene.material = material(&scene, 0);
    //scene.light.color[0] = 201;
    //scene.light.color[1] = 201;
    //scene.light.color[2] = 201;

    /*
    float a[] = {8,-5,9,2};
    float b[] = {7,5,6,1};
    float c[] = {-6,0,9,6};
  //  float d[] = {-3,0,-9,-4};
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

 //   m1 = matrix(4, a, b, c, d);
  //  print_matrix(m1.m, 4);
 //   m2 = inverse_matrix(m1);
//	print_matrix(m2.m, 4);
 //   print_matrix(transpose(m1).m, 4);
    //print_float_array(tuple(1, 2, 3, 1));
    //print_float_array(tuple(1, 2, 3, 0));
    //print_float_array(tuple_add(tuple(1, 2, 3, 1), tuple(1, 1, 1, 0)));
    //print_float_array(normalize(tuple(4,0,0,0)));
    //printf("%f\n", dot_product(tuple(1,2,3,0), tuple(2,3,4,0)));
    //print_float_array(vector_cross_prod(tuple(1,2,3,0), tuple(2,3,4,0)));
    //print_matrix(matrix_multiply(matrix(a, b, c, d), matrix(ab,bb,cb,db)));
*/    

	mlx_t* mlx = mlx_init(1080, 1080, "MLX42", true);
    
    if (!mlx) exit(1);

    // Create a 250x250 image.
    mlx_image_t* img = mlx_new_image(mlx, 1200, 1200);

    // Set the channels of each pixel in our image to the maximum byte value of 255. 
    memset(img->pixels, 150, img->width * img->height * sizeof(int));

    // Draw the image at coordinate (0, 0).
    mlx_image_to_window(mlx, img, 0, 0);
    paint_sphere_shadow(img, &scene.sp[0], &scene);

    // Run the main loop and terminate on quit.  
    mlx_loop(mlx);
    mlx_terminate(mlx);

    return (0);
}