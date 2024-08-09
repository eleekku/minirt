#include "../inc/minirt.h"

void    free_array(char **args)
{
    int i;

    i = -1;
    if (!args)
        return;
    while(args[++i])
        free(args[i]);
    free(args);
}

void    exit_error(char *msg, char **args)
{
    if (args)
        free_array(args);
    ft_printf(2, "Error\n%s\n", msg);
    exit(1);
}

t_bool    validate_values(char *arg, char **args)
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
            exit_error("Invalid value format", args);
        i++;
    }
    if (coma > 2)
        exit_error("Invalid egb format", args);
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

float    fill_value(char *arg, char **args, char **coordinates)
{
    float   value;
    int     i;

    i = -1;

    while(arg[++i])
        if (arg[i] != '.' || (arg[i] != '-' && !(arg[i] >= '1' && arg[i] <= '9')))
        {   
            if (coordinates)
                free_array(coordinates);
            exit_error("Invalid value format", args);
        } 
    if (ft_strchr(arg, '.'))
        value = ft_atof(arg);
    else
        value = ft_atoi(arg);
    return (value);
}