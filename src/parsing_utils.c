#include "../inc/minirt.h"

t_bool fill_rgb(int *color, int str)
{
    int     i;
    char    **rgb;
    int     value;
    int     status;

    rgb = safe_split(str, ',');
    while (++i <= 2)
        {
            value = ft_atoi(rgb[i]);
            if (!(value >= 0 && value <= 255))
            {
                free_array(rgb);
                return (FALSE);
            }
            color[i] = value;
        }
    status = TRUE;
    if (rgb[i])
        status = FALSE;
    free_array(rgb);
    return (status);
}

t_bool    validate_values(char *arg)
{
    int     i;
    int     coma;

    i = 0;
    coma = 0;
    while (arg[i])
    {
        if (arg[i] == ',')
            {
                coma++;
                i++; 
            }
        if (arg[i] && ((arg[i] != '.' && arg[i] != '-') && (arg[i] < '0' || arg[i] > '9')) &&
        arg[i] != '\n')
            return (FALSE);
        i++;
    }
    if (coma > 2)
        return (FALSE);
    return (TRUE);
}

char    **safe_split(char *string, char separator)
{
    char **arr;

    arr = ft_split(string,  separator);
    if (!arr)
    {
        exit(1);
    }
    return (arr);
}

float    fill_value(char *arg, char **args, char **coordinates, t_object **object)
{
    float   value;
    int     i;

    i = -1;
    while(arg[++i] && arg[i] != '\n')
    {
        if (arg[i] && arg[i] != '.' && arg[i] != '-' && !(arg[i] >= '0' && arg[i] <= '9'))
        {  
            if (coordinates)
                free_array(coordinates);
            exit_error("Invalid value format", args);
        }
    }
    if (ft_strchr(arg, '.'))
        value = ft_atof(arg);
    else
        value = ft_atoi(arg);
    return (value);
}
