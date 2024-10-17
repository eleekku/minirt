/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:47:33 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/27 16:37:32 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt_bonus.h"

static t_camera	*compute_pixel_size(t_camera *camera)
{
	float	half_view;
	float	aspect;

	half_view = tan(camera->field / 2);
	aspect = camera->hsize / camera->vsize;
	if (aspect >= 1)
	{
		camera->half_width = half_view;
		camera->half_height = half_view / aspect;
	}
	else
	{
		camera->half_width = half_view * aspect;
		camera->half_height = half_view;
	}
	camera->pixel_size = (camera->half_width * 2) / camera->hsize;
	return (camera);
}

t_camera	*create_camera(float hsize, float vsize, float field)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->transform = create_identity(4);
	if (!camera->transform)
	{
		free(camera);
		return (NULL);
	}
	camera->hsize = hsize;
	camera->vsize = vsize;
	camera->field = field;
	return (compute_pixel_size(camera));
}

void render_row(t_camera *camera, t_world *world, mlx_image_t *img, int y, pthread_mutex_t *pixel_mutex)
{
	int x = 0;
	float **ray;
	float *col;
	int *color_back;

	while (x < camera->hsize)
	{
		ray = ray_for_pixel(camera, x, y);
		col = color_at(world, ray);
		color_back = conv_color_back(col);
		pthread_mutex_lock(pixel_mutex);
		mlx_put_pixel(img, x, y, colors_to_int(color_back, 256));
		pthread_mutex_unlock(pixel_mutex);
		free(color_back);
		clean_ray(ray);
		free(col);
		x++;
	}
}

void *render_section(void *args)
{
	t_thread_args *thread_args = (t_thread_args *)args;
	t_camera *camera = thread_args->camera;
	t_world *world = thread_args->world;
	mlx_image_t *img = thread_args->img;
	pthread_mutex_t *pixel_mutex = thread_args->pixel_mutex;
	int y = thread_args->start_y;

	while (y < thread_args->end_y)
	{
		render_row(camera, world, img, y, pixel_mutex);
		y++;
	}
	return NULL;
}

int render(t_camera *camera, t_world *world, mlx_image_t *img)
{
	int num_threads = 2; // Adjust the number of threads as needed
	pthread_t threads[num_threads];
	t_thread_args thread_args[num_threads];
	int section_height;
	int i;
	pthread_mutex_t pixel_mutex;

	if (pthread_mutex_init(&pixel_mutex, NULL) != 0)
	{
		fprintf(stderr, "Failed to initialize mutex\n");
		return 1;
	}
	section_height = camera->vsize / num_threads;
	i = -1;
	while (++i < num_threads)
	{
		thread_args[i].camera = camera;
		thread_args[i].world = world;
		thread_args[i].img = img;
		thread_args[i].start_y = i * section_height;
		thread_args[i].pixel_mutex = &pixel_mutex;
		thread_args[i].end_y = (i == num_threads - 1) ? camera->vsize : (i + 1) * section_height;
		pthread_create(&threads[i], NULL, render_section, &thread_args[i]);
	}
	i = -1;
	while (++i < num_threads)
		pthread_join(threads[i], NULL);
	pthread_mutex_destroy(&pixel_mutex);
	return (1);
}
