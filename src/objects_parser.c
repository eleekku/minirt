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

t_bool    parse_cylinder2(char **args, t_object **object, int index, char **values)
{
        int i;

        i = -1;
        while (++i <= 2)
        {
            if (!fill_value(values[i], values, &object[index]->normv[i]))
                return (FALSE);
            if (!(object[index]->normv[i] >= -1.0 && object[index]->normv[i] <= 1.0))
                return (FALSE);
        }
        free_array(values);
        if (!fill_value(args[3], NULL, &object[index]->diameter))
            return (FALSE);
        if (object[index]->diameter <= 0.0)
            return (FALSE);
        if (!fill_value(args[4], NULL, &object[index]->height))
            return (FALSE);
        if (object[index]->height <= 0.0)
            return (FALSE);
        if  (!validate_values(args[5]))
            return (FALSE);
        if (!fill_rgb(&object[index]->material->color, args[5]))
            return (FALSE);
        return (TRUE);
}

t_bool    parse_cylinder(char **args, int index, t_object **object)
{
        char    **values;
        int     i;

        object[index] = create_object(CYLINDER);
        if (!validate_values(args[1]))
            return (FALSE);
        i = -1;
        values = safe_split(args[1], ',');
        while (++i <= 2)
            if(!fill_value(values[i], values, &object[index]->coord[i]))
                return (FALSE);
        if (values[i])
            return (FALSE);
        i = -1;
        free_array(values);
        if (!validate_values(args[2]))
            return (FALSE);
        values = safe_split(args[2], ',');
        return (parse_cylinder2(args, object, index, values));
}

t_bool  parse_plane2(char **args, t_object **object, int index, char **values)
{
        int i;

        i = -1;
        while (++i < 2)
        {
            if(!fill_value(values[i], values, &object[index]->normv[i]))
                return (FALSE);
            if (!(object[index]->normv[i] >= -1.0 && object[index]->normv[i] <= 1.0))
                return (FALSE);
        }
        free_array(values);
        if (!validate_values(args[3]))
            return (FALSE);
        if (!fill_rgb(&object[index]->material->color, args[3]))
            return (FALSE);
        return (TRUE);
}

t_bool    parse_plane(char **args, int index, t_object **object)
{
        char    **values;
        int     i;

        object[index] = create_object(PLANE);
        if (!validate_values(args[1]))
            return (FALSE);
        i = -1;
        values = safe_split(args[1], ',');
        while (++i <= 2)
            if (!fill_value(values[i], values, &object[index]->coord[i]))
                return (FALSE);
        if (values[i])
            return (FALSE);
        free_array(values);
        i = -1;
        if (!validate_values(args[2]))
            return (FALSE);
        values = safe_split(args[2], ',');
        return (parse_plane2(args, object, index, values)); 
}


t_bool    parse_sphere(char **args, int index, t_object **object)
{
        char    **values;
        int     i;

        object[index] = create_object(SPHERE);
        if (!validate_values(args[1]))
            return (FALSE);
        i = -1;
        values = safe_split(args[1], ',');
        while (++i <= 2)
            if (!fill_value(values[i], values, &object[index]->coord[i]))
                return (FALSE);
        object[index]->coord[i] = 1;
        if (values[i])
        {
            free_array(values);
            return (FALSE);
        }
        free_array(values);
        if (!fill_value(args[2], NULL, &object[index]->diameter))
            return (FALSE);
        if (!validate_values(args[3]))
            return(FALSE);
        if (!fill_rgb(&object[index]->material->color, args[3]))
            return (FALSE);
        return (TRUE);
}


