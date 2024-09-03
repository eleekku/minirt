/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:16:14 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/29 16:42:42 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

typedef struct	s_light
{
	int		color[3];
	float	position[4];
	float	brightness;
}	t_light;

typedef struct s_material
{
	int	*color[4];
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

typedef struct s_lightdot
{
	int 	*ambient;
	int 	*diffuse;
	int		*specular;
	int		result[3];
	int		*effective_color;
    float	*lightv; 
    int		*temp;
    float	light_dot_normal;
    float	*reflectv;
    float	reflect_dot_eye;
    float	factor;
}	t_lightdot;

/*
typedef struct s_vectors
{
	float	*eyev;
	float	*normal;
}	t_vectors;

typedef struct s_lighting
{
	float	*eff_color;
	float	*lightv;
	float	*ambient;
}	t_lighting;


/*** Light ***/
t_light	*point_light(float *pos, float *intensity);
*/
#endif