
#include "../inc/minirt.h"

/*int	main(int argc, char **argv)
{
	t_parse		*parse;
	t_object	**objects;

	parse = malloc(sizeof(t_parse));
	parse->amcolor = create_point(0, 0, 0);
	parse->total = 0;
	parse->lightnumb = 0;
	
	//parse->lcolor = (int*)create_point(0, 0, 0);
	if (argc != 2)
    {
        ft_printf(2, "Error\nPlease input one and only one file\n");
        exit (1);
    }
	objects = check_file(argv[1], parse, FALSE);
	printf("ambient color is %f\n", parse->amcolor[0]);
	printf("object color is %f\n", objects[0]->material->color[1]);
	int i = -1;
	while (++i < parse->total)
	clean_object(objects[i]);
	clean_parse(parse);
	free(objects);
}*/

t_matrix *create_transform(t_matrix *transform, t_object *o)
{
	t_matrix	*temp;
	t_matrix    *scale;
	t_matrix	*x;
	t_matrix	*y;
	float	theta_x;
	float	theta_y;

	temp = create_translate(o->coord[0], o->coord[1], o->coord[2]);
	if (o->s == SPHERE)
		scale = create_scaling(o->diameter / 2, o->diameter / 2, o->diameter / 2);
	else if (o->s == CYLINDER)
		scale = create_scaling(o->diameter / 2, o->height, o->diameter / 2);
	else
		scale = create_identity(4);
	if (o->s != SPHERE)
	{
	theta_x = atan2(o->normv[2], o->normv[0]);
	theta_y = acos(o->normv[1]);
	x = create_x_rotation(theta_x);
	y = create_y_rotation(theta_y);
	}
	else
	{
		x = create_identity(4);
		y = create_identity(4);
	}
	temp = matrix_multiply(temp, x, 1);
	temp = matrix_multiply(temp, y, 1);
	transform = matrix_multiply(temp, scale, 1);
	transform = inverse_matrix(transform);
	return (transform);
}

float *compute_up(float *dir)
{
	/*If camd is not aligned too closely with (0, 1, 0), we use (0, 1, 0)
    Otherwise, we use (1, 0, 0) as the reference to avoid collinearity*/
	float *temp_up;
	float *right;
	float *cameradir;
	float *up;

	cameradir = create_vector(dir[0], dir[1], dir[2]);
	if (fabs(dir[1]) < 0.9)
		temp_up = create_vector(0, 1, 0);
    else
		temp_up = create_vector(1, 0, 0);
	right = vector_cross_prod(cameradir, temp_up);
	right = normalize(right, 1);
	up = vector_cross_prod(right, cameradir);
	free(temp_up);
	free(right);
	free(cameradir);
	return (up);
}



int	main(int argc, char **argv)
{
	t_light		*light;
	t_world		*world;
	t_camera	*camera;
	t_light	**lights;
	t_matrix	*tmp;
	float		*cameraup;

	t_parse		*parse;
	t_object	**object;
	int			i;

	parse = malloc(sizeof(t_parse));
	parse->amcolor = create_point(0, 0, 0);
	if (argc != 2)
    {
        ft_printf(2, "Error\nPlease input one and only one file\n");
        exit (1);
    }
	i = -1;
	object = check_file(argv[1], parse, FALSE);
	while (++i < parse->total)
	{
		object[i]->transform = create_transform(object[i]->transform, object[i]);
	//	print_matrix(object[i]->transform->m, 4);
	}
	

<<<<<<< HEAD
//	printf("camdir is %f %f %f\n", parse->normv[0], parse->normv[1], parse->normv[2]);
	light = parse->light[0];
//	light->coord = create_point(parse->light[0]->coord[0], parse->light[0]->coord[1], parse->light[0]->coord[2]);
//	light->color = color(1, 1, 1);

	world = create_world(parse->total, light);
	world->objects = object;
	i = -1;
//	while (++i < total)
//		printf("obj colors are %f, %f, %f\n", world->objects[i]->material->color[0], world->objects[i]->material->color[1], world->objects[i]->material->color[2]);
	camera = create_camera(1500, 1000, parse->fow * 0.01745329);
=======
	left_wall = create_object(PLANE);
	clean_matrix(left_wall->transform, 4);
	left_wall->transform = matrix_multiply(matrix_multiply(matrix_multiply(create_translate(0, 0, 5), create_y_rotation(PI/4), 1), create_x_rotation(PI/2), 1), create_scaling(10, 0.01, 10), 1);
	left_wall->transform = inverse_matrix(left_wall->transform);
	free(left_wall->material->color);
	left_wall->material->color = color(1, 0.9, 0.9);
	left_wall->material->specular = 0;
	left_wall->material->pattern = TRUE;
	tmp = create_scaling(0.1, 0.1, 0.1);
	left_wall->material->patt = create_pattern(color(0, 0, 0), color(1, 1, 1), inverse_matrix(tmp));
	clean_matrix(tmp, 4);

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

	lights = malloc(sizeof(t_light) * 10);
	light = malloc(sizeof(t_light));
	light->coord = create_point(-10, 10, -10);
	light->color = color(1, 1, 1);
	lights[0] = light;
	lights[1] = NULL;

	world = create_world(7, lights);
	world->objects[0] = floor;
	world->objects[1] = cylinder;
	world->objects[2] = right_wall;
	world->objects[3] = left_wall;
	world->objects[4] = middle;
	world->objects[5] = right;
	world->objects[6] = left;
	camera = create_camera(1500, 1000, PI/3);
>>>>>>> master
	clean_matrix(camera->transform, 4);
	cameraup = compute_up(parse->normv);
	tmp = view_transform(create_point(parse->camc[0], parse->camc[1], parse->camc[2]), create_point(parse->normv[0], parse->normv[1], parse->normv[2]), cameraup);
	camera->transform = inverse_matrix(tmp);
	clean_matrix(tmp, 4);
	render(camera, world);
}
