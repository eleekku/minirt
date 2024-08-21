#include "../inc/minirt.h"

void    free_objects_exit(t_scene *scene, char *message, char **array, char **args)
{
    free(scene->sp);
    free(scene->pl);
    free(scene->cy);
    if (args)
        free_array(args);
    if (message)
        exit_error(message, array, NULL);
    
}

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

void    free_objects(t_scene *scene)
{
    if (scene->sp)
        free(scene->sp);
    if (scene->pl)
        free(scene->pl);
    if (scene->cy)
        free(scene->cy);
}

void    exit_error(char *msg, char **args, t_scene *scene)
{
    if (args)
        free_array(args);
    if (scene)
        free_objects(scene);
    ft_printf(2, "Error\n%s\n", msg);
    exit(1);
}