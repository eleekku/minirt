
#include "../inc/minirt.h"

int	main(void)
{
	t_object	*floor, *left_wall, *right_wall, *middle, *right, *left, *cylinder, *plane;
	t_light		*light;
	t_world		*world;
	t_camera	*camera;
	t_matrix	*tmp;

	(void)plane;

	floor = create_object(PLANE);
	clean_matrix(floor->transform, 4);
	tmp = create_scaling(10, 0.01, 10);
	floor->transform = inverse_matrix(tmp);
	clean_matrix(tmp, 4);
	free(floor->material->color);
	floor->material->color = color(1, 0.9, 0.9);
	floor->material->specular = 0;

	left_wall = create_object(PLANE);
	clean_matrix(left_wall->transform, 4);
	left_wall->transform = matrix_multiply(matrix_multiply(matrix_multiply(create_translate(0, 0, 5), create_y_rotation(PI/4), 1), create_x_rotation(PI/2), 1), create_scaling(10, 0.01, 10), 1);
	left_wall->transform = inverse_matrix(left_wall->transform);
	free(left_wall->material->color);
	left_wall->material->color = color(1, 0.9, 0.9);
	left_wall->material->specular = 0;

	right_wall = create_object(PLANE);
	clean_matrix(right_wall->transform, 4);
	right_wall->transform = matrix_multiply(matrix_multiply(matrix_multiply(create_translate(0, 0, 5), create_y_rotation(-PI/4), 1), create_x_rotation(PI/2), 1), create_scaling(10, 0.01, 10), 1);
	right_wall->transform = inverse_matrix(right_wall->transform);
	free(right_wall->material->color);
	right_wall->material->color = color(1, 0.9, 0.9);
	right_wall->material->specular = 0;

	middle = create_object(SPHERE);
	clean_matrix(middle->transform, 4);
	tmp = create_translate(-0.5, 1, 0.5);
	middle->transform = inverse_matrix(tmp);
	clean_matrix(tmp, 4);
	middle->material->color = color(0.1, 1, 0.5);
	middle->material->diffuse = 0.7;
	middle->material->specular = 0.3;
	middle->material->pattern = TRUE;
	tmp = create_scaling(0.1, 0.1, 0.1);
	middle->material->patt = create_pattern(color(0, 0, 0), color(1, 1, 1), inverse_matrix(tmp));
	clean_matrix(tmp, 4);

	right = create_object(SPHERE);
	clean_matrix(right->transform, 4);
	tmp = matrix_multiply(create_translate(1.5, 0.5, -0.5), create_scaling(0.5, 0.5, 0.5), 1);
	right->transform = inverse_matrix(tmp);
	clean_matrix(tmp, 4);
	right->material->color = color(0.5, 1, 0.1);
	right->material->diffuse = 0.7;
	right->material->specular = 0.3;

	left = create_object(SPHERE);
	clean_matrix(left->transform, 4);
	tmp = matrix_multiply(create_translate(-1.5, 0.33, -0.75), create_scaling(0.33, 0.33, 0.33), 1);
	left->transform = inverse_matrix(tmp);
	clean_matrix(tmp, 4);
	left->material->color = color(1, 0.8, 0.1);
	left->material->diffuse = 0.7;
	left->material->specular = 0.3;

//	cylinder = test_object(CYLINDER);
//	cylinder->cylindermax = 3;
//	cylinder->cylindermin = -1;
//	cylinder->closed = TRUE;
//	clean_matrix(cylinder->transform, 4);
//	tmp = matrix_multiply(create_translate(-1, 0.33, 0), create_scaling(0.5, 0.5, 0.5));
//	tmp = create_identity(4);
//	cylinder->transform = inverse_matrix(tmp);
//	clean_matrix(tmp, 4);
//	cylinder->transform = inverse_matrix(cylinder->transform);
//	cylinder->material->color = color(0, 0, 1);
//	cylinder->material->diffuse = 0.9;
//	cylinder->material->specular = 0.9;
//	cylinder->material->shininess = 100;

	cylinder = create_object(CYLINDER);
	cylinder->cylindermax = 2;
	cylinder->cylindermin = 1;
	cylinder->closed = TRUE;
	//tmp = create_translate(-0.5, 0, 0.5);
	//cylinder->transform = inverse_matrix(tmp);
	cylinder->material->color = color(0, 0, 1);
	cylinder->material->diffuse = 0.9;
	cylinder->material->specular = 0.9;
	cylinder->material->shininess = 100;
	cylinder->material->pattern = TRUE;
	tmp = create_scaling(0.1, 0.1, 0.1);
	cylinder->material->patt = create_pattern(color(0, 0, 0), color(1, 1, 1), inverse_matrix(tmp));
	clean_matrix(tmp, 4);

	light = malloc(sizeof(t_light));
	light->coord = create_point(-10, 10, -10);
	light->color = color(1, 1, 1);

	world = create_world(7, light);
	world->objects[0] = floor;
	world->objects[1] = cylinder;
	world->objects[2] = right_wall;
	world->objects[3] = left_wall;
	world->objects[4] = middle;
	world->objects[5] = right;
	world->objects[6] = left;
	camera = create_camera(1500, 1000, PI/3);
	clean_matrix(camera->transform, 4);
	tmp = view_transform(create_point(0, 1.5, -5), create_point(0, 1, 0), create_vector(0, 1, 0));
	camera->transform = inverse_matrix(tmp);
	clean_matrix(tmp, 4);
	render(camera, world);
}
