
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

t_matrix *create_axis_rotation(float *axis, float angle)
{
    t_matrix *rotation = create_identity(4);  // Start with identity matrix
    float x = axis[0], y = axis[1], z = axis[2];
    float cos_theta = cos(angle);
    float sin_theta = sin(angle);
    float one_minus_cos = 1.0f - cos_theta;

    // Normalize the axis vector
    float magnitude = sqrt(x*x + y*y + z*z);
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;

    // Rodrigues' rotation formula
    rotation->m[0][0] = cos_theta + one_minus_cos * x * x;
    rotation->m[0][1] = one_minus_cos * x * y - z * sin_theta;
    rotation->m[0][2] = one_minus_cos * x * z + y * sin_theta;
    rotation->m[0][3] = 0.0f;

    rotation->m[1][0] = one_minus_cos * y * x + z * sin_theta;
    rotation->m[1][1] = cos_theta + one_minus_cos * y * y;
    rotation->m[1][2] = one_minus_cos * y * z - x * sin_theta;
    rotation->m[1][3] = 0.0f;

    rotation->m[2][0] = one_minus_cos * z * x - y * sin_theta;
    rotation->m[2][1] = one_minus_cos * z * y + x * sin_theta;
    rotation->m[2][2] = cos_theta + one_minus_cos * z * z;
    rotation->m[2][3] = 0.0f;

    rotation->m[3][0] = 0.0f;
    rotation->m[3][1] = 0.0f;
    rotation->m[3][2] = 0.0f;
    rotation->m[3][3] = 1.0f;

    return rotation;
}

t_matrix *create_transform(t_matrix *transform, t_object *o)
{
    t_matrix    *temp;
    t_matrix    *scale;
    t_matrix    *rotation;
    float       *up = create_vector(0, 1, 0);  // Up vector
    float       *rotation_axis;
    float       angle;
    float       dot;
	float	theta_x;
	float	theta_y;
	t_matrix *x, *y;



    // Create translation matrix
    temp = create_translate(o->coord[0], o->coord[1], o->coord[2]);

    // Handle scaling based on object type
    if (o->s == SPHERE)
        scale = create_scaling(o->diameter / 2, o->diameter / 2, o->diameter / 2);
    else if (o->s == CYLINDER)
        scale = create_scaling(o->diameter / 2, o->height, o->diameter / 2);
    else
        scale = create_identity(4);

    // Handle rotation for non-spherical objects
    if (o->s == PLANE)// || o->s == CYLINDER)
    {
        // Calculate the angle between the object's normal vector and the up vector
        dot = dot_product(o->normv, up);  // Dot product
        angle = acos(dot);  // Angle between normal and up vector

        // Compute the rotation axis (cross product of normal and up vector)
        rotation_axis = vector_cross_prod(o->normv, up);

        // If the normal vector is already aligned with the up vector, no rotation is needed
        if (magnitude(rotation_axis) > 1e-6)  // Check if rotation is needed
            rotation = create_axis_rotation(rotation_axis, angle);  // Rotate around the axis by the calculated angle
        else
            rotation = create_identity(4);  // No rotation needed if the vectors are already aligned
    }
	else if (o->s == CYLINDER)
	{
		theta_x = atan2(o->normv[2], o->normv[0]);
		theta_y = acos(o->normv[1]);
		x = create_x_rotation(theta_x);
		y = create_y_rotation(theta_y);
		rotation = matrix_multiply(x, y, 1);
	}
    else
    {
        // Spheres don't need any rotation
        rotation = create_identity(4);
    }

    // Apply the transformations: Translation * Rotation * Scaling
    temp = matrix_multiply(temp, rotation, 1);
    transform = matrix_multiply(temp, scale, 1);

    // Inverse the final transform matrix
    transform = inverse_matrix(transform);

    // Free temporary vectors
    free(up);

    return (transform);
}
/*
	t_matrix	*temp;
	t_matrix    *scale;
	t_matrix	*x;
	t_matrix	*y;
	t_matrix *rotation;
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
		
		if (o->s == PLANE)
		{
			float angle;
            float *def;
			def = create_vector(0, 1, 0);
            angle = acos(dot_product(o->normv, def));

            float *rotation_axis = vector_cross_prod(o->normv, def);

            if (magnitude(rotation_axis) > 1e-6)
                rotation = create_axis_rotation(rotation_axis, angle);
            else
                rotation = create_identity(4); // No rotation needed if aligned
    	}
		else
	//	{
		theta_x = atan2(o->normv[2], o->normv[0]);
		theta_y = acos(o->normv[1]);
		x = create_x_rotation(theta_x);
		y = create_y_rotation(theta_y);
		rotation = matrix_multiply(x, y, 1);
	//	}
	}
	else
	rotation = create_identity(4);

	temp = matrix_multiply(temp, rotation, 1);
	transform = matrix_multiply(temp, scale, 1);
	transform = inverse_matrix(transform);
	return (transform);
}*/

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
//	t_light		*light;
	t_world		*world;
	t_camera	*camera;
	t_light	**lights;
//	float		**ray;
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
	printf("parsing done\n");
//	object[0]->material->pattern = TRUE;
	while (++i < parse->total)
		object[i]->transform = create_transform(object[i]->transform, object[i]);
	object[0]->material->pattern = TRUE;
	object[0]->material->patt = create_pattern(color(0, 0, 0), color(1, 1, 1), object[0]->transform);
	object[0]->material->shininess = 30;
	object[0]->material->specular = 0.1;
	object[1]->material->shininess = 90;
	object[1]->material->specular = 0.3;
	object[2]->material->shininess = 90;
	object[2]->material->specular = 0.3;
	

//	printf("camdir is %f %f %f\n", parse->normv[0], parse->normv[1], parse->normv[2]);
	lights = parse->light;
//	light->coord = create_point(parse->light[0]->coord[0], parse->light[0]->coord[1], parse->light[0]->coord[2]);
//	light->color = color(1, 1, 1);

	world = create_world(parse->total, lights);
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
