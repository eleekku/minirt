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
	float wall_z;
	float wall_size, half, pixel_size, canvas_pixels;
	float world_y, world_x;
	float **ray;
	int x;
	int y;

	wall_z = 10;
	canvas_pixels = 2000;
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
	add_ambient(img, scene);
	int spcol;

	spcol = colors_to_int(sphere->color, 266);
	
	for (y = 0; y < canvas_pixels - 1; y++)
	{
		world_y = half - pixel_size * y;
		for (x = 0; x < canvas_pixels - 1; x++)
		{
			world_x = -half + pixel_size * x;
			position = tuple(world_x, world_y, wall_z, 1);
			ray = create_ray(scene->camc, normalize(tuple_subs(position, scene->camc)));
			xs = intersects(sphere, ray);
			if (hit(xs).t != -1)
			{
				mlx_put_pixel(img, x, y, spcol);
			}
		}
	}
	return (1);
}
