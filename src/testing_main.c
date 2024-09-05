
#include "../inc/minirt.h"
#include "../inc/world.h"
#include <stdio.h>

int	main(void)
{
	t_object	sp1, sp2;
	t_intersections	world;
	t_world		w;
	t_matrix	tmp;
	float		**r, *v, *p;

	sp1.coord = create_point(0, 0, 0);
	sp2.coord = create_point(0, 0, 0);
	sp1.transform = create_identity();
	tmp = inverse_matrix(sp1.transform);
	free_matrix(sp1.transform.m);
	sp1.transform = tmp;
	sp2.transform = create_scaling(0.5, 0.5, 0.5);
	tmp = inverse_matrix(sp2.transform);
	free_matrix(sp2.transform.m);
	sp2.transform = tmp;
	w.objects = malloc(sizeof(t_object) * 100);
	w.number_objects = 2;
	w.objects[0] = sp1;
	w.objects[1] = sp2;
	p = create_point(0, 0, -5);
	v = create_vector(0, 0, 1);
	r = create_ray(p, v);
	world = intersect_world(w, r);
	printf("World %d %f %f %f %f", world.count, world.int_list[0].t, world.int_list[1].t, world.int_list[2].t, world.int_list[3].t);
	free(sp1.coord);
	free(sp2.coord);
	free_matrix(sp1.transform.m);
	free_matrix(sp2.transform.m);
	free(w.objects);
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