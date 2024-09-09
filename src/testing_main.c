
#include "../inc/minirt.h"
#include "../inc/world.h"
#include <stdio.h>

int	main(void)
{
	t_object	sp1, sp2;
	t_intersections	*world;
	t_intersection	i;
	t_world		*w;
	t_matrix	tmp;
	t_comp		*comp;
	float		**r, *v, *p;

	w = malloc(sizeof(t_world));
	sp1.coord = create_point(0, 0, 0);
	sp2.coord = create_point(0, 0, 0);
	sp1.material.color = color(1, 0.5, 1);
	sp1.material.shininess = 0.5;
	sp1.material.specular = 1;
	sp1.material.diffuse = 2;
	sp1.material.ambient = 0.9;
	sp1.transform = create_identity();
	tmp = inverse_matrix(sp1.transform);
	free_matrix(sp1.transform.m);
	sp1.transform = tmp;
	sp2.transform = create_scaling(0.5, 0.5, 0.5);
	tmp = inverse_matrix(sp2.transform);
	free_matrix(sp2.transform.m);
	sp2.transform = tmp;
	w->objects = malloc(sizeof(t_object) * 100);
	w->number_objects = 2;
	w->objects[0] = sp1;
	w->objects[1] = sp2;
	w->light->color = color(1, 0.9, 0.9);
	i = intersection(1, sp1);
	p = create_point(0, 0, 0);
	v = create_vector(0, 0, 1);
	r = create_ray(p, v);
	comp = prepare_computations(i, r);
	world = intersect_world(w, r);
	lighting(comp, w, w->objects[0]);
	printf("World %d %f %f %f %f", world->count, world->int_list[0].t, world->int_list[1].t, world->int_list[2].t, world->int_list[3].t);
	print_float_array(comp->point);
	print_float_array(comp->eyev);
	print_float_array(comp->normalv);
	free(sp1.coord);
	free(sp2.coord);
	free_matrix(sp1.transform.m);
	free_matrix(sp2.transform.m);
	clean_comp(comp);
	free(world->int_list);
	free(world);
	free(w->objects);
	free(p);
	free(v);
	free(r);
}
/*
int main(void)
{
	t_matrix	motrix, mutrix;

	motrix = create_translate(3, 3, 0);
	mutrix = inverse_matrix(motrix);
	free_matrix(motrix.m);
	free_matrix(mutrix.m);
}*/