/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:40:37 by esalmela          #+#    #+#             */
/*   Updated: 2024/09/27 15:40:39 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	free_objects_exit(t_object **object, char **args,
int amount, t_parse *p)
{
	int		i;
	char	*msg;
	char	*shape;

	msg = "In parsing object";
	if (object[amount]->s == SPHERE)
		shape = "sphere";
	else if (object[amount]->s == PLANE)
		shape = "plane";
	else if (object[amount]->s == CYLINDER)
		shape = "cylinder";
	else
		shape = "cone";
	i = -1;
	if (args)
		free_array(args);
	if (p)
		clean_parse(p);
	while (++i <= amount)
		clean_object(object[i]);
	free(object);
	ft_printf(2, "Error\n%s %s\n", msg, shape);
	exit(1);
}

void	free_array(char **args)
{
	int	i;

	i = -1;
	if (!args)
		return ;
	while (args[++i])
		free(args[i]);
	free(args);
}

void	exit_error(char *msg, char **args, t_parse *parse)
{
	if (parse)
	{
		printf("im here\n");
		clean_parse(parse);
	}
	if (args)
		free_array(args);
	ft_printf(2, "Error\n%s\n", msg);
	exit(1);
}
