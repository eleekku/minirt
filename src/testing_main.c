
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
	clean_matrix(camera->transform, 4);
	cameraup = compute_up(parse->normv);
	tmp = view_transform(create_point(parse->camc[0], parse->camc[1], parse->camc[2]), create_point(parse->normv[0], parse->normv[1], parse->normv[2]), cameraup);
	camera->transform = inverse_matrix(tmp);
	clean_matrix(tmp, 4);
	render(camera, world);
}
