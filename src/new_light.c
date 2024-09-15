/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:36:08 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/15 23:31:23 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_light	*point_light(float *p, float *c)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->coord = p;
	light->color = c;
	return (light);
}

float	*shade_hit(t_world	*w, t_comp *comp)
{
	int	n;

	n = is_shadowed(w, comp->over_point);
	return (lighting(comp, w, comp->object, n));
}

float	*color_at(t_world *w, float **ray)
{
	t_intersections	*xs;
	t_intersection	*i;
	t_comp			*comp;
	float			*result;

	xs = intersect_world(w, ray);
	if (!xs)
		return (NULL);
	i = hit(xs);
	clean_intersections(xs);
	if (!i)
		return (NULL);
	if (i->t == -1)
	{
		free(i);
		return (color(0, 0, 0));
	}
	comp = prepare_computations(i, ray);
	result = shade_hit(w, comp);
	free(i);
	clean_comp(comp);
	return (result);
}

float	*lighting(t_comp *comp, t_world *w, t_object *object, int shadow)
{
	float	*eff_color;
	float	*lightv;
	float	*ambient;
	float	*tmp;
	float	light_dot_normal;
	float	*reflectv;
	float	reflect_dot_eye;
	float	*diffuse;
	float	*specular;
	float	factor;

	eff_color = hadamard(object->material->color, w->light->color);
	if (!eff_color)
		return (NULL);
	tmp = tuple_subs(w->light->coord, comp->over_point);
	if (!tmp)
	{
		free(eff_color);
		return (NULL);
	}
	lightv = normalize(tmp);
	free(tmp);
	if (!lightv)
	{
		free(eff_color);
		return (NULL);
	}
	ambient = multiply_color(eff_color, object->material->ambient);
	light_dot_normal = dot_product(lightv, comp->normalv);
	if (light_dot_normal < 0 || shadow)
	{
		diffuse = color(0, 0, 0);
		specular = color(0, 0, 0);
	}
	else
	{
		tmp = multiply_color(eff_color, object->material->diffuse);
		diffuse = multiply_color(tmp, light_dot_normal);
		free(tmp);
		tmp = negate_vector(lightv);
		reflectv = reflect(tmp, comp->normalv);
		free(tmp);
		reflect_dot_eye = dot_product(reflectv, comp->eyev);
		free(reflectv);
		if (reflect_dot_eye < 0)
			specular = color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, object->material->shininess);
			tmp = multiply_color(w->light->color, object->material->specular);
			specular = multiply_color(tmp, factor);
			free(tmp);
		}
	}
	free(eff_color);
	free(lightv);
	return (add_colors(ambient, diffuse, specular));
}
