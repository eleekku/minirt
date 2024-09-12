
#include "../inc/minirt.h"

int	main(void)
{
	t_object	*floor, *left_wall, *right_wall, *middle, *right, *left;
	t_light		*light;
	t_world		*world;
	t_camera	*camera;
	t_matrix	*tmp;

	floor = create_object(SPHERE);
	clean_matrix(floor->transform, 4);
	floor->transform = create_scaling(10, 0.01, 10);
	floor->transform = inverse_matrix(floor->transform);
	free(floor->material->color);
	floor->material->color = color(1, 0.9, 0.9);
	floor->material->specular = 0;

	left_wall = create_object(SPHERE);
	clean_matrix(left_wall->transform, 4);
	left_wall->transform = matrix_multiply(matrix_multiply(matrix_multiply(create_translate(0, 0, 5), create_y_rotation(PI/4)), create_x_rotation(PI/2)), create_scaling(10, 0.01, 10));
	left_wall->transform = inverse_matrix(left_wall->transform);
	clean_material(left_wall->material);
	left_wall->material = floor->material;

	right_wall = create_object(SPHERE);
	clean_matrix(right_wall->transform, 4);
	right_wall->transform = matrix_multiply(matrix_multiply(matrix_multiply(create_translate(0, 0, 5), create_y_rotation(-PI/4)), create_x_rotation(PI/2)), create_scaling(10, 0.01, 10));
	right_wall->transform = inverse_matrix(right_wall->transform);
	clean_material(right_wall->material);
	right_wall->material = floor->material;

	middle = create_object(SPHERE);
	clean_matrix(middle->transform, 4);
	tmp = create_translate(-0.5, 1, 0.5);
	middle->transform = inverse_matrix(tmp);
	clean_matrix(tmp, 4);
	middle->material->color = color(0.1, 1, 0.5);
	middle->material->diffuse = 0.7;
	middle->material->specular = 0.3;

	right = create_object(SPHERE);
	clean_matrix(right->transform, 4);
	tmp = matrix_multiply(create_translate(1.5, 0.5, -0.5), create_scaling(0.5, 0.5, 0.5));
	right->transform = inverse_matrix(tmp);
	clean_matrix(tmp, 4);
	right->material->color = color(0.5, 1, 0.1);
	right->material->diffuse = 0.7;
	right->material->specular = 0.3;

	left = create_object(SPHERE);
	clean_matrix(left->transform, 4);
	tmp = matrix_multiply(create_translate(-1.5, 0.33, -0.75), create_scaling(0.33, 0.33, 0.33));
	left->transform = inverse_matrix(tmp);
	clean_matrix(tmp, 4);
	left->material->color = color(1, 0.8, 0.1);
	left->material->diffuse = 0.7;
	left->material->specular = 0.3;
	
	light = malloc(sizeof(t_light));
	light->coord = create_point(-10, 10, -10);
	light->color = color(1, 1, 1);

	world = create_world(6, light);
	world->objects[0] = floor;
	world->objects[1] = left_wall;
	world->objects[2] = right_wall;
	world->objects[3] = middle;
	world->objects[4] = right;
	world->objects[5] = left;
	camera = create_camera(1000, 1000, PI/3);
	clean_matrix(camera->transform, 4);
	//camera->transform = create_translate(1, 2, 1);
	camera->transform = view_transform(create_point(0, 1.5, -5), create_point(0, 1, 0), create_vector(0, 1, 0));
	camera->transform = inverse_matrix(camera->transform);
	render(camera, world);
}
