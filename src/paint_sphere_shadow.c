/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_sphere_shadow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:01:28 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/04 18:28:40 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	add_ambient(mlx_image_t *img, t_parse *parse)
{
	int x;
	int y;
	int color;
	int intensity;

	intensity = scene->alightr * 255;

	x = 0;
	y = 0;
	color = colors_to_int(scene->amcolor, intensity);
	while (x < 1200)
	{
		while (y < 1200)
		{
			mlx_put_pixel(img, x, y, color);
			y++;
		}
	y = 0;
	x++;
	}
}

int	paint_sphere_shadow(mlx_image_t *img, t_sphere *sphere, t_parse *parse)
{
	//t_matrix motrix, mutrix;
	//t_sphere sphere;
	t_intersections	xs;
	float *position;
	float wall_z;
	float wall_size, half, pixel_size, canvas_pixels;
	float world_y, world_x;
	float **ray;
	int x;
	int y;
	float *normal;

	wall_z = 10;
	canvas_pixels = 1200;
	wall_size = 7;
	half = wall_size / 2;
	pixel_size = wall_size / canvas_pixels;
//	ray_origin = tuple(0.5, 0.5, -50, 1);
	/*sphere.color[0] = 0;
	ray_origin = tuple(0,0,-9000, 1);
	sphere.color[0] = 0;
	sphere.color[1] = 0;
	sphere.color[2] = 0;
	sphere.coord[0] = 0;
	sphere.coord[1] = 0;
	sphere.coord[2] = 0;
	sphere.diameter = 1;*/
	//scene->camc[3] = 1;
//	add_ambient(img, scene);
	//int spcol;
	t_object	object;
	object.s = SPHERE;
	object.coord = scene->sp[0].center;
	object.diameter = scene->sp[0].diameter;
	object.color[0] = scene->sp[0].color[0];
	object.color[1] = scene->sp[0].color[1];
	object.color[2] = scene->sp[0].color[2];
	object.transform = create_identity();
	object.normv[0] = 0;
	object.normv[1] = 0;
	object.normv[2] = 0;
	object.height = 0;
	object.material = material(scene, 0);
	float	*eyev;
	int *spcol;
	(void)img;
	t_intersection hitpoint;
//	spcol = colors_to_int(sphere->color, 266);
//	printf("hola\n");
	//motrix = create_identity();
	//motrix = create_translate(3, 4, 5);
	object.transform = create_scaling(100, 100, 100);
	//mutrix = create_translate(3, 3, 3);
	//motrix = matrix_multiply(object.transform.m, motrix.m);
	t_matrix metrix  = inverse_matrix(object.transform);
	for (y = 0; y < canvas_pixels - 1; y++)
	{
	//	if (y == 0)
	//		exit (1);
		world_y = half - pixel_size * y;
		for (x = 0; x < canvas_pixels - 1; x++)
		{
			world_x = -half + pixel_size * x;
			position = tuple(world_x, world_y, wall_z, 1);
			ray = create_ray(scene->camc, normalize(tuple_subs(position, scene->camc)));
			transform_ray(ray, metrix.m);
			xs = intersects(sphere, ray);
			hitpoint = hit(xs);
			if (hitpoint.t != -1)
			{
			//	printf("I did hit\n");
			//	(void)eyev;
			//	(void)normal;
			float	*rayposition = ray_position(ray, hitpoint.t);
			//	printf("position is %f\n", position[3]);
				normal = normal_at(&object, rayposition);
			//	printf("we have normal\n");
				eyev = negate_vector(ray[1]);
			//	printf("we have eyev\n");
				spcol = lighting(scene, position, eyev, normal);
			//	if (spcol[0] != 20 || spcol[1] != 20 || spcol[2] != 20)
			///	printf("calculated color is %d %d %d\n", spcol[0], spcol[1], spcol[2]);
			//	printf("CONGRAZ YOU CALCULATED LIGHTNIN\n");
				int color = colors_to_int(spcol, 256);
				mlx_put_pixel(img, x, y, color);
				free(eyev);
				free(normal);
				free(rayposition);
			//	printf("i printed in theory");
			}
			free(position);
			free(ray);

		}
	}
	return (1);
}
