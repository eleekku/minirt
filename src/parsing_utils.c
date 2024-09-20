#include "../inc/minirt.h"

t_bool fill_rgb(float **color, char *str)
{
    int     i;
    char    **rgb;
    int     value[3];
    int     status;

    i = -1;
    rgb = safe_split(str, ',');
    while (++i <= 2)
        {
            value[i] = ft_atoi(rgb[i]);
            if (!(value[i] >= 0 && value[i] <= 255))
            {
                free_array(rgb);
                return (FALSE);
            }
        }
    free(*color);
    *color = create_point(value[0], value[1], value[2]);
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

t_bool    fill_value(char *arg, char **coordinates, float *value)
{
    int     i;

    i = -1;
    while(arg[++i] && arg[i] != '\n')
    {
        if (arg[i] && arg[i] != '.' && arg[i] != '-' && !(arg[i] >= '0' && arg[i] <= '9'))
        {  
            if (coordinates)
                free_array(coordinates);
            return (FALSE);
        }
    }
    if (ft_strchr(arg, '.'))
        *value = ft_atof(arg);
    else
        *value = (float)ft_atoi(arg);
    return (TRUE);
}
