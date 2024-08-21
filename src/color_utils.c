/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xriera-c <xriera-c@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:03:01 by xriera-c          #+#    #+#             */
/*   Updated: 2024/07/17 15:24:00 by xriera-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}

int	get_digit(char c, int digits_in_base)
{
	int	max_digit;

	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	else
		max_digit = digits_in_base - 10 + 'a';
	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}

unsigned int	ft_atoi_base(const char *str, int str_base)
{
	unsigned int	result;
	int				digit;

	result = 0;
	digit = get_digit(to_lower(*str), str_base);
	while (digit >= 0)
	{
		result = result * str_base;
		result = result + digit;
		++str;
		digit = get_digit(to_lower(*str), str_base);
	}
	result = result * str_base;
	result = result + 15;
	result = result * str_base;
	result = result + 15;
	return (result);
}

char *strjoin_colors(char *s1, char *s2, char *s3)
{
	char *temp;
	char *result;

	temp = ft_strjoin(s1, s2);
	if (!temp)
		exit(1);
	result = ft_strjoin(temp, s3);
	if (!result)
		exit(1);
	free (temp);
	return (result);

}
char	*int_to_hex(int num)
{
    char* hexStr;
    char *hexChars;

	hexStr = malloc(3 * sizeof(char));	
	hexChars = "0123456789ABCDEF";
    hexStr[0] = hexChars[(num >> 4) & 0xF];
    hexStr[1] = hexChars[num & 0xF];
    hexStr[2] = '\0';

    return hexStr;
}

int	colors_to_int(int *colors)
{
	char 	*c1;
	char 	*c2;
	char 	*c3;
	char 	*string;
	int		result;

	c1 = int_to_hex(colors[0]);
	c2 = int_to_hex(colors[1]);
	c3 = int_to_hex(colors[2]);
	string = strjoin_colors(c1, c2, c3);
	result = ft_atoi_base(string, 16);
	return (result);
}

static float	clamp_color(float n)
{
	if (n > 255)
		return (255);
	return (n);
}

void	conv_color_for(int *color)
{
	color[0] = color[0] / 256;
	color[1] = color[1] / 256;
	color[2] = color[2] / 256;
}

void	conv_color_back(int *color)
{
	color[0] = clamp_color(color[0] * 256);
	color[1] = clamp_color(color[1] * 256);
	color[2] = clamp_color(color[2] * 256);
}