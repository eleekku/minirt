/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_light.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:32:58 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/07 17:56:34 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_LIGHT_H
# define NEW_LIGHT_H
# include "world.h"

typedef struct s_light
{
	float	*color;
	float	*coord;
}	t_light;

typedef struct s_material
{
	float	*color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

float	*hadamard(float *a, float *b);
float	*multiply_color(float *a, float b);
float	*add_colors(float *a, float *b, float *c);
float	*lighting(t_comp *comp, t_world *w, t_object *object);
#endif