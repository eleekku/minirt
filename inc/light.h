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
	float	*color;
	float	*position;
}	t_light;

typedef struct s_material
{
	float	*color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
}	t_material;

#endif