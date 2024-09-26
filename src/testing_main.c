/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:53:18 by esalmela          #+#    #+#             */
/*   Updated: 2024/09/25 10:53:22 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/minirt.h"

/*int	main(int argc, char **argv)
{
	t_parse		*parse;
	t_object	**objects;

	parse = malloc(sizeof(t_parse));
	parse->amcolor = create_point(0, 0, 0);
	parse->total = 0;
	parse->lightnumb = 0;
	//parse->lcolor = (int*)create_point(0, 0, 0); if (argc != 2) { ft_printf(2, "Error\nPlease input one and only one file\n"); exit (1); }
	objects = check_file(argv[1], parse, FALSE);
	printf("ambient color is %f\n", parse->amcolor[0]);
	printf("object color is %f\n", objects[0]->material->color[1]);
	int i = -1;
	while (++i < parse->total)
	clean_object(objects[i]);
	clean_parse(parse);
	free(objects);
}*/

/*If camd is not aligned too closely with (0, 1, 0), we use (0, 1, 0)
Otherwise, we use (1, 0, 0) as the reference to avoid collinearity*/

float *compute_up(float *dir)
{
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

t_parse *init_parse(void)
{
	t_parse		*parse;

	parse = malloc(sizeof(t_parse));
	parse->lightnumb = 0;
	parse->total = 0;
	parse->amcolor = create_point(0, 0, 0);
	parse->amnum = 0;
	parse->cnum = 0;
	return (parse);
}

t_camera	*transform_n_pattern(t_object **o, t_parse *parse, t_world **world)
{
	t_camera	*camera;
	float		*cameraup;
	t_matrix	*tmp;
	int	i;
	
	i = -1;
	while(++i < parse->total)
	{
		o[i]->transform = create_transform(o[i]->transform, o[i]);
		if (o[i]->material->pattern == TRUE)
			o[i]->material->patt = create_pattern(color(0, 0, 0), 
				color(1, 1, 1), o[i]->transform);
	}
	*world = create_world(parse->total, parse->light);
	world[0]->objects = o;
	camera = create_camera(1500, 1000, parse->fow * 0.01745329);
	clean_matrix(camera->transform, 4);
	cameraup = compute_up(parse->normv);
	tmp = view_transform(create_point(parse->camc[0], parse->camc[1], parse->camc[2]),
		create_point(parse->normv[0], parse->normv[1], parse->normv[2]), cameraup);
	camera->transform = inverse_matrix(tmp);
	clean_matrix(tmp, 4);
	return (camera);
}

int	main(int argc, char **argv)
{
//	t_light		*light;
	t_world		*world;
	t_camera	*camera;
//	float		**ray;

	t_parse		*parse;
	t_object	**objects;
	int			i;

	parse = init_parse();	
	if (argc != 2)
    {
        ft_printf(2, "Error\nPlease input one and only one file\n");
        exit (1);
    }
	i = -1;
	objects = check_file(argv[1], parse, FALSE);
	printf("parsing done\n");
	camera = transform_n_pattern(objects, parse, &world);
	printf("render gonna start\n");

	i = -1;
//	while (++i < total)
//		printf("obj colors are %f, %f, %f\n", world->objects[i]->material->color[0], world->objects[i]->material->color[1], world->objects[i]->material->color[2]);
//	camera = create_camera(1500, 1000, parse->fow * 0.01745329);
//	clean_matrix(camera->transform, 4);
//	cameraup = compute_up(parse->normv);
//	tmp = view_transform(create_point(parse->camc[0], parse->camc[1], parse->camc[2]), create_point(parse->normv[0], parse->normv[1], parse->normv[2]), cameraup);
//	camera->transform = inverse_matrix(tmp);
//	clean_matrix(tmp, 4);
	render(camera, world);
}
