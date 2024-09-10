
#include "../inc/minirt.h"

int	main(void)
{
	t_matrix	*transform;
	t_matrix	*inv;
	float		*p, *r;

	transform = create_translate(5, -3, 2);
	inv = inverse_matrix(transform);
	p = create_point(-3, 4, 5);
	r = four_one_multiply(inv->m, p);
	print_float_array(r);
	return (0);
}
