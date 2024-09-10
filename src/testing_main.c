
#include "../inc/minirt.h"

int	main(void)
{
	float	**r;
	t_object	*sphere;
	t_intersections	*inter;

	sphere = create_object(SPHERE);
	if (!sphere)
	{
		printf("BYEEE");
		return (0);
	}
	r = create_ray(create_point(0, 0, -5), create_vector(0, 0, 1));
	inter = sphere_intersect(sphere, r);
	printf("Count: %d -----  %f %f", inter->count, inter->int_list[0].t, inter->int_list[1].t);
	//printf("Count: %d", inter->count);
	return (0);
}
