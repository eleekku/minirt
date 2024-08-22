#include "../inc/minirt.h"

void    malloc_objects(t_scene *scene)
{
    if (scene->spheres > 0)
    {
    scene->sp = malloc(sizeof(t_sphere) * scene->spheres);
        if (!scene->sp)
            exit_error("malloc error", NULL, NULL);
    }
    if (scene->planes > 0)
    {
    scene->pl = malloc(sizeof(t_plane) * scene->planes);
        if (!scene->pl)
        {
            free(scene->sp);
            exit_error("malloc error", NULL, NULL);
        }
    }
    if (scene->cylinders > 0)
    {
    scene->cy = malloc(sizeof(t_cylinder) * scene->cylinders);
        if (!scene->cy)
        {
            free(scene->sp);
            free(scene->pl);
            exit_error("malloc error", NULL, NULL);
        }
    }
}

t_bool    validate_values(char *arg, char **args, t_scene *scene)
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
            exit_error("Invalid value format", args, scene);
        i++;
    }
    if (coma > 2)
        exit_error("Invalid value format", args, scene);
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

float    fill_value(char *arg, char **args, char **coordinates, t_scene *scene)
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
            if (scene)
                free_objects(scene); 
            exit_error("Invalid value format", args, NULL);
        }
    }
    if (ft_strchr(arg, '.'))
        value = ft_atof(arg);
    else
        value = ft_atoi(arg);
    return (value);
}
