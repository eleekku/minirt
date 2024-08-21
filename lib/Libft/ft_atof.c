/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:39:40 by esalmela          #+#    #+#             */
/*   Updated: 2024/07/19 16:45:19 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*A function to turn ascii into float. Designed to be used in miniRT.
Returns 0.0 if fails but is not fully protected. For example, accepts
asd5.34 and turns it into 5.34*/
float	ft_atof(const char *str)
{
	float	result;
	float	sign;
	int		i;
	int		count;

	result = 0.0;
	count = 0;
	i = ft_strlen(str);
	sign = 1.0;
	if (*str == '-')
		sign = -1.0;
	while (--i >= 0 && str[i] >= '0' && str[i] <= '9')
		result = result / 10.0 + (str[i] - '0');
	if (str[i] != '.' || i < 1)
		return (0.0);
	while (--i >= 0 && str[i] >= '0' && str[i] <= '9')
	{
		result = result / 10 + (str[i] - '0');
		count++;
	}
	if (count == 0)
		return (0.0);
	while (--count > 0)
		result = result * 10;
	return (result * sign);
}