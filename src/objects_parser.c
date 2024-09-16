/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:04:45 by esalmela          #+#    #+#             */
/*   Updated: 2024/09/16 16:04:46 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_bool    parse_cylinder2(char **args, t_object **object, int index)
{
        float   value;
        char    **rgb;
        int     i;
        int     temp;

        value = fill_value(args[3], args, NULL, NULL);
        if (value <= 0.0)
            free_objects_exit(NULL, "Invalid cylinder diameter value", args, NULL);
        object[index]->diameter = value;
        value = fill_value(args[4], args, NULL, NULL);
        if (value <= 0.0)
            free_objects_exit(NULL, "Invalid cylinder height value", args, NULL);
        object[index]->height = value;
        i = -1;
        if  (!validate_values(args[5]))
            return (FALSE);
        if (!fill_rgb(object[index]->material->color, args[5]))
            return (FALSE);
        return (TRUE);
}

t_bool    parse_cylinder(char **args, t_object **object, int index)
{
        char    **values;
        int     i;
        float   temp;

        object[index] = create_object(PLANE);
        object[index]->material = create_material();
        if (!validate_values(args[1]))
            return (FALSE);
        i = -1;
        values = safe_split(args[1], ',');
        while (++i <= 2)
            object[index]->coord[i] = fill_value(values[i], args, values, NULL);
        if (values[i])
            free_objects_exit(NULL, "Invalid cylinder format", values, args);
        i = -1;
        free_array(values);
        if (!validate_values(args[2]))
            return (FALSE);
        values = safe_split(args[2], ',');
        while (++i <= 2)
        {
            temp = fill_value(values[i], values, args, NULL);
            if (!(temp >= -1.0 && temp <= 1.0))
                free_objects_exit(NULL, "Invalid cylinder normal vector value", args, values);
            object[index]->normv[i] = temp;
        }
        return (parse_cylinder2(args, NULL, index));
}

t_bool    parse_plane(char **args, t_object **object, int index)
{
        char    **values;
        int     i;
        float   temp;

        object[index] = create_object(PLANE);
        object[index]->material = create_material();
        if (!validate_values(args[1]))
            return (FALSE);
        i = -1;
        values = safe_split(args[1], ',');
        while (++i <= 2)
            object[index]->coord[i] = fill_value(values[i], args, values, NULL);
        if (values[i])
            free_objects_exit(NULL, "Invalid plane format", values, args);
        free_array(values);
        i = -1;
        if (!validate_values(args[2]))
            return (FALSE);
        values = safe_split(args[2], ',');
        while (++i < 2)
        {
            temp = fill_value(values[i], values, args, NULL);
            if (!(temp >= -1.0 && temp <= 1.0))
                free_objects_exit(NULL, "Invalid plane normal vector value", args, values);
            object[index]->normv[i] = temp;
        }
        if (!validate_values(args[3]))
            return (FALSE);
        if (fill_rgb(object[i]->material->color, args[3]))
            return (FALSE);
}


t_bool    parse_sphere(char **args, int index, t_object **object)
{
        char    **values;
        int     i;
        int     temp;

        object[index] = create_object(SPHERE);
        object[index]->material = create_material();
        if (!validate_values(args[1]))
            return (FALSE);
        i = -1;
        values = safe_split(args[1], ',');
        while (++i <= 2)
            object[index]->coord[i] = fill_value(values[i], args, values, object);
        object[index]->coord[i] = 1;
        if (values[i])
            free_objects_exit(NULL, "Invalid sphere format", values, args);
        free_array(values);
        object[index]->diameter = fill_value(args[2], args, NULL, NULL);
        validate_values(args[3]);
        if (!fill_rgb(object[index]->material->color, args[3]))
            return (FALSE);
}


