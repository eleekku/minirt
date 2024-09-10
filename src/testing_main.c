
#include "../inc/minirt.h"

int	main(void)
{
	t_world	*world;
	t_light	*light;
	t_object	*sphere, *sp2;
	t_intersections	*xs;
	float	**ray;

	light = malloc(sizeof(t_light));
	light->coord = create_point(-10, 10, -10);
	light->color = color(1, 1, 1);
	sphere = create_object(SPHERE);
	sphere->material->color = color(0.8, 1.0, 0.6);
	sphere->material->diffuse = 0.7;
	sphere->material->specular = 0.2;
	sp2 = create_object(SPHERE);
	sp2->transform = create_scaling(0.5, 0.5, 0.5);
	world = malloc(sizeof(t_world));
	ray = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	world->light = light;
	world->number_objects = 2;
	world->objects = malloc(2 * sizeof(t_object *));
	world->objects[0] = sphere;
	world->objects[1] = sp2;
	xs = intersect_world(world, ray);
	printf("%d %f %f %f %f\n", xs->count, xs->int_list[0].t, xs->int_list[1].t, xs->int_list[2].t, xs->int_list[3].t);
}
