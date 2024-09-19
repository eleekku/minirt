/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:36:08 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/19 14:09:33 by xriera-c         ###   ########.fr       */
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
	int		n;
	int		i;
	float	*col;
	float	*result;

	i = 0;
	result = color(0, 0, 0);
	while (result && w->lights[i])
	{
		n = is_shadowed(w, comp->over_point, w->lights[i]);
		if (comp->object->material->pattern == TRUE)
			comp->object->material->color = checker_at_obj(comp);
		col = lighting(comp, w->lights[i], comp->object, n);
		if (!col)
		{
			free(result);
			return (NULL);
		}
		result = add_two_colors(result, col);
		i++;
	}
	return (result);
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

static float	*specular(float *lv, t_comp *comp, t_object *obj, t_light *l)
{
	float	*tmp;
	float	*reflectv;
	float	ref_dot_eye;
	float	factor;

	tmp = negate_vector(lv);
	if (!tmp)
		return (NULL);
	reflectv = reflect(tmp, comp->normalv);
	free(tmp);
	if (!reflectv)
		return (NULL);
	ref_dot_eye = dot_product(reflectv, comp->eyev);
	free(reflectv);
	if (ref_dot_eye < 0)
		return (color(0, 0, 0));
	else
	{
		factor = pow(ref_dot_eye, obj->material->shininess);
		tmp = multiply_color(l->color, obj->material->specular, 0);
	}
		return (multiply_color(tmp, factor, 1));
}

float	*lighting(t_comp *comp, t_light *l, t_object *obj, int shadow)
{
	float	*eff_color;
	float	*lightv;
	float	*ambient;
	float	*tmp;
	float	light_dot_normal;
	float	*diffuse;
	float	*spec;

	eff_color = hadamard(obj->material->color, l->color);
	if (!eff_color)
		return (NULL);
	tmp = tuple_subs(l->coord, comp->over_point);
	if (!tmp)
	{
		free(eff_color);
		return (NULL);
	}
	lightv = normalize(tmp, 1);
	if (!lightv)
	{
		free(eff_color);
		return (NULL);
	}
	ambient = multiply_color(eff_color, obj->material->ambient, 0);
	light_dot_normal = dot_product(lightv, comp->normalv);
	if (light_dot_normal < 0 || shadow)
	{
		diffuse = color(0, 0, 0);
		spec = color(0, 0, 0);
		free(eff_color);
	}
	else
	{
		tmp = multiply_color(eff_color, obj->material->diffuse, 1);
		diffuse = multiply_color(tmp, light_dot_normal, 1);
		spec = specular(lightv, comp, obj, l);
	}
	free(lightv);
	return (add_colors(ambient, diffuse, spec));
}
