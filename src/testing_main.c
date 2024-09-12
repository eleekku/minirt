
#include "../inc/minirt.h"

int	main(void)
{
	t_object *object;
	float *normal;
	t_intersections	*xs;
	float **r;

	object = test_object(CYLINDER);
//	free(object->transform);
//	printf("%f\n", object->transform->m[0]);
//	print_matrix(object->transform->m, 4);
//	object->transform = matrix_multiply(create_scaling(1, 0.5, 1), create_z_rotation(PI/5));
//	normal = normal_at(object, create_point(-1, 1, 0));
//	printf("normal0 %f %f %f\n", normal[0], normal[1], normal[2]);
//	object->cylindermin = 1;
//	object->cylindermin = 2;
	object->closed = TRUE;
	float *point = create_point(0, 1.5, -2);
	float *vector = create_vector(0, 0, 1);
	vector = normalize(vector);
//	printf("normallised vector: %f %f %f\n", vector[0], vector[1], vector[2]);
	r = create_ray(point, vector);
	xs = pre_intersect(object, r);
//	xs = cylinder_intersect(object, r);
	printf("%d is the count at t %f and %f\n", xs->count, xs->int_list[0].t, xs->int_list[1].t);
//	clean_intersections(xs);
//	clean_object(object);
//	free(point);
//	free(vector);*/

}