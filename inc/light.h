/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:16:14 by xriera-c          #+#    #+#             */
/*   Updated: 2024/08/21 16:19:09 by xriera-c         ###   ########.fr       */
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
	float	*color[4];
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

#endif