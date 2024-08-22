#include "../inc/minirt.h"

void    parse_cylinder2(char **args, t_scene *scene, int index)
{
        float   value;
        char    **rgb;
        int     i;
        int     temp;

        value = fill_value(args[3], args, NULL, scene);
        if (value <= 0.0)
            free_objects_exit(scene, "Invalid cylinder diameter value", args, NULL);
        scene->cy[index].diameter = value;
        value = fill_value(args[4], args, NULL, scene);
        if (value <= 0.0)
            free_objects_exit(scene, "Invalid cylinder height value", args, NULL);
        scene->cy[index].height = value;
        i = -1;
        validate_values(args[5], args, scene);
        rgb = safe_split(args[5], ',');
        while (++i < 2)
        {
            temp = ft_atoi(rgb[i]);
            if (!(temp >= 0 && temp <= 255))
                exit_error("invalid plane rgb value", args, scene);
            scene->cy[index].color[i] = temp;
        }
        free_array(rgb);
}

void    parse_cylinder(char **args, t_scene *scene, int index)
{
        char    **values;
        int     i;
        float   temp;

        validate_values(args[1], args, scene);
        i = -1;
        values = safe_split(args[1], ',');
        while (++i <= 2)
            scene->cy[index].coord[i] = fill_value(values[i], args, values, scene);
        scene->cy[index].coord[i] = 1;
        if (values[i])
            free_objects_exit(scene, "Invalid cylinder format", values, args);
        i = -1;
        free_array(values);
        validate_values(args[2], args, scene);
        values = safe_split(args[2], ',');
        while (++i <= 2)
        {
            temp = fill_value(values[i], values, args, scene);
            if (!(temp >= -1.0 && temp <= 1.0))
                free_objects_exit(scene, "Invalid cylinder normal vector value", args, values);
            scene->pl[index].normv[i] = temp;
        }
        scene->pl[index].normv[i] = 0;
        parse_cylinder2(args, scene, index);
}

static void    parse_planergb(char **args, t_scene *scene, int index)
{
        char    **rgb;
        int     i;
        int     temp;

        i = -1;
        validate_values(args[3], args, scene);
        rgb = safe_split(args[3], ',');
        while (++i < 2)
        {
            temp = ft_atoi(rgb[i]);
            if (!(temp >= 0 && temp <= 255))
                exit_error("invalid plane rgb value", args, scene);
            scene->pl[index].color[i] = temp;
        }
        free_array(rgb);
}

void    parse_plane(char **args, t_scene *scene, int index)
{
        char    **values;
        int     i;
        float   temp;

        validate_values(args[1], args, scene);
        i = -1;
        values = safe_split(args[1], ',');
        while (++i <= 2)
            scene->pl[index].coord[i] = fill_value(values[i], args, values, scene);
        scene->pl[index].coord[i] = 1;
        if (values[i])
            free_objects_exit(scene, "Invalid plane format", values, args);
        free_array(values);
        i = -1;
        validate_values(args[2], args, scene);
        values = safe_split(args[2], ',');
        while (++i < 2)
        {
            temp = fill_value(values[i], values, args, scene);
            if (!(temp >= -1.0 && temp <= 1.0))
                free_objects_exit(scene, "Invalid plane normal vector value", args, values);
            scene->pl[index].normv[i] = temp;
        }
        scene->pl[index].normv[i] = 0;
        parse_planergb(args, scene, index); 
}

void    parse_sphere(char **args, t_scene *scene, int index)
{
        char    **values;
        int     i;
        int     temp;

        validate_values(args[1], args, scene);
        i = -1;
        values = safe_split(args[1], ',');
        while (++i <= 2)
            scene->sp[index].center[i] = fill_value(values[i], args, values, scene);
        scene->sp[index].center[i] = 1;
        if (values[i])
            free_objects_exit(scene, "Invalid sphere format", values, args);
        free_array(values);
        scene->sp[index].diameter = fill_value(args[2], args, NULL, scene);
        validate_values(args[3], args, scene);
        values = safe_split(args[3], ',');
        i = -1;
        while (++i <= 2)
        {
            temp = ft_atoi(values[i]);
            if (!(temp >= 0 && temp <= 255))
                free_objects_exit(scene, "Invalid rgb value on sphere", args, values);
            scene->sp[index].color[i] = temp;
        }
        free_array(values);
}


