/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_sphere_shadow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:01:28 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/20 13:53:30 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	add_ambient(mlx_image_t *img, t_scene *scene)
{
	int x;
	int y;
	int color;
	int intensity;

	intensity = scene->alightr * 255;

	x = 0;
	y = 0;
	printf("colors are: %d, %d, %d and intensity: %f", scene->amcolor[0], scene->amcolor[1], scene->amcolor[2], scene->alightr);
	color = colors_to_int(scene->amcolor, intensity);
	while (x < 2000)
	{
		while (y < 2000)
		{
			mlx_put_pixel(img, x, y, color);
			y++;
		}
	y = 0;
	x++;
	}
}

int	paint_sphere_shadow(mlx_image_t *img, t_sphere *sphere, t_scene *scene)
{
	//t_sphere sphere;
	t_intersections	xs;
	float *position;
	float	y, x, wall_z;
	float wall_size, half, pixel_size, canvas_pixels;
	float world_y, world_x;
	float **ray;

	wall_z = 10;
	canvas_pixels = 2000;
	wall_size = 7;
	half = wall_size / 2;
	pixel_size = wall_size / canvas_pixels;
<<<<<<< HEAD
//	ray_origin = tuple(0.5, 0.5, -50, 1);
=======
<<<<<<< HEAD
	ray_origin = tuple(0,0,-5, 1);
>>>>>>> master
	/*sphere.color[0] = 0;
=======
	ray_origin = tuple(0,0,-9000, 1);
	sphere.color[0] = 0;
>>>>>>> 4466b38041281945d6a14f2d6ad303fea6e08d7b
	sphere.color[1] = 0;
	sphere.color[2] = 0;
	sphere.coord[0] = 0;
	sphere.coord[1] = 0;
	sphere.coord[2] = 0;
	sphere.diameter = 1;*/
	//scene->camc[3] = 1;
	add_ambient(img, scene);
	
	for (y = 0; y < canvas_pixels - 1; y++)
	{
		world_y = half - pixel_size * y;
		for (x = 0; x < canvas_pixels - 1; x++)
		{
			world_x = -half + pixel_size * x;
			position = tuple(world_x, world_y, wall_z, 1);
<<<<<<< HEAD
			ray = create_ray(scene->camc, normalize(tuple_subs(position, scene->camc)));
			xs = intersects(sphere, ray);
=======
			ray = create_ray(ray_origin, normalize(tuple_subs(position, ray_origin)));
			xs = intersects(&sphere, ray);
>>>>>>> master
			if (hit(xs).t != -1)
			{
				mlx_put_pixel(img, x, y, colors_to_int(sphere->color, 266));
			}
		}
	}
	return (1);
}
