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
	return (result);
}

unsigned int	ft_atoi_baseintense(const char *str, int str_base)
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
	free(temp);
	free(s1);
	free(s2);
	free(s3);
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

int	colors_to_int(int *colors, int intensity)
{
	char 	*string;
	int		result;
	char	*temp;
	char	*intens;

	string = strjoin_colors(int_to_hex(colors[0]), int_to_hex(colors[1]), int_to_hex(colors[2]));
	if (intensity == 266)
		result = ft_atoi_baseintense(string, 16);
	else
	{
		intens = int_to_hex(intensity);
		temp = ft_strjoin(string, intens);
		free(intens);
		result = ft_atoi_base(temp, 16);
		free(temp);
	}
	free(string);
	return (result);
}

int	*combine_colors(int *a, int *b)
{
	int *result;

	result = malloc(3 * sizeof(int));
	if (!result)
		return (NULL);
	result[0] = ((a[0] * b[0]) / 255);
	result[1] = ((a[1] * b[1]) / 255);
	result[2] = ((a[2] * b[2]) / 255);
	return (result);
}

int	*multiply_scale(int *color, float scale)
{
	int *result;

	result = malloc(3 * sizeof(int));
	if (!result)
		return (NULL);
	result[0] = color[0] * scale;
	result[1] = color[1] * scale;
	result[2] = color[2] * scale;
	return (result);

}
/*
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
}*/