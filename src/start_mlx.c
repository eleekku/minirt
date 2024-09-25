/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:48:15 by xriera-c          #+#    #+#             */
/*   Updated: 2024/09/25 12:11:58 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	start_display(t_camera *c, t_world *w)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(c->hsize, c->vsize, "miniRT", true);
	if (!mlx)
		return (NULL);
	img = mlx_new_image(mlx, c->hsize, c->vsize);
	if (!img)
	{
		mlx_terminate(mlx);
		return (NULL);
	}
	mlx_image_to_window(mlx, img, 0, 0);
	render(c, w, img);
	mlx_loop(mlx);
	//ADD ESC KEY TERMINATE
	mlx_terminate(mlx);
	return (mlx);
}
