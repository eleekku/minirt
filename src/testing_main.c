
#include "../inc/minirt.h"

int	main(void)
{
	t_object *object;
//	float *normal;
	t_intersections	*xs;
	float **r;

	object = test_object(PLANE);
//	free(object->transform);
//	printf("%f\n", object->transform->m[0]);
//	print_matrix(object->transform->m, 4);
//	object->transform = matrix_multiply(create_scaling(1, 0.5, 1), create_z_rotation(PI/5));
//	normal = normal_at(object, create_point(10, 0, -10));
//	printf("normal0 %f, normal1 %f normal2 %f\n", normal[0], normal[1], normal[2]);
	float *point = create_point(0, 1, 0);
	float *vector = create_vector(0, 0, 1);
	r = create_ray(point, vector);
	xs = pre_intersect(object, r);
//	xs = plane_intersect(object, r);
//	printf("%d is the count at t %f\n", xs->count, xs->int_list[0].t);
	clean_intersections(xs);
	clean_object(object);
	free(point);
	free(vector);



}