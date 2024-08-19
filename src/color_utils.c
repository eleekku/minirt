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
/*
static float	clamp_color(float n)
{
	if (n > 255)
		return (255);
	return (n);
}

t_tuple	conv_color_for(t_tuple a)
{
	t_tuple	r;

	r.x = a.x / 256;
	r.y = a.y / 256;
	r.z = a.z / 256;
	r.w = 0;
	return (r);
}

t_tuple	conv_color_back(t_tuple a)
{
	t_tuple	r;

	r.x = clamp_color(a.x * 256);
	r.y = clamp_color(a.y * 256);
	r.z = clamp_color(a.z * 256);
	r.w = 0;
	return (r);
}*/