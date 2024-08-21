/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_sphere_shadow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:01:28 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/15 14:04:02 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	paint_sphere_shadow(mlx_image_t *img, t_sphere *sphere, t_scene *scene)
{
	//t_sphere sphere;
	t_intersections	xs;
	float *position, *ray_origin;
	float	y, x, wall_z;
	float wall_size, half, pixel_size, canvas_pixels;
	float world_y, world_x;
	float **ray;

	wall_z = 10;
	canvas_pixels = 2000;
	wall_size = 7;
	half = wall_size / 2;
	pixel_size = wall_size / canvas_pixels;
	ray_origin = tuple(0.5, 0.5, -50, 1);
	/*sphere.color[0] = 0;
	sphere.color[1] = 0;
	sphere.color[2] = 0;
	sphere.coord[0] = 0;
	sphere.coord[1] = 0;
	sphere.coord[2] = 0;
	sphere.diameter = 1;*/
	//scene->camc[3] = 1;
	
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
				mlx_put_pixel(img, x, y, colors_to_int(sphere->color));
			}
		}
	}
	return (1);
}