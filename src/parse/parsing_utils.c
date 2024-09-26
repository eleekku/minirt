#include "../../inc/minirt.h"

t_bool  check_pattern(t_object **object, int index, char **args, int n)
{
    if (args[n])
    {
        if (!ft_strncmp(args[n], "P\n", 3) || !ft_strncmp(args[n], "P", 2))
        {
            object[index]->material->pattern = TRUE;
            return (TRUE);
        }
        return (FALSE);
    }
    return (TRUE);
}

t_bool allocate_light(t_parse *parse)
{
    int i;

    i = -1;
    parse->light = malloc((parse->lightnumb + 1) * (sizeof(t_light *)));
    if (!parse->light && parse->lightnumb > 0)
        return(FALSE);
    while (++i < parse->lightnumb)
        parse->light[i] = create_light();
    parse->light[parse->lightnumb] = NULL;
    return (TRUE);
}

t_bool fill_rgb(float *color, char *str)
{
    int     i;
    char    **rgb;
    float   *value;
    int     status;

    i = -1;
    rgb = safe_split(str, ',');
    value = malloc(3 * sizeof(float));
    while (++i <= 2)
        {
            value[i] = ft_atoi(rgb[i]);
            if (!(value[i] >= 0 && value[i] <= 255))
            {
                free_array(rgb);
                free(value);
                return (FALSE);
            }
        }
    free(color);
    color = conv_color_for(value);
    free(value);
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
