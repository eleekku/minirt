
#include "../inc/minirt.h"
#include "../inc/world.h"
#include <stdio.h>

int	main(void)
{
	float	*t1, *t2, *t3, *t4;

	t1 = create_point(3, -2, 5);
	t2 = create_vector(-2, 3, 1);
	t3 = tuple_add(t1, t2);
}
