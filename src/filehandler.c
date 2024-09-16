/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filehandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esalmela <esalmela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:04:31 by esalmela          #+#    #+#             */
/*   Updated: 2024/09/16 16:04:32 by esalmela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void    recon_object(char **args, t_parse *parse, t_object **object)
{
    static int i;

    if (!ft_strncmp(args[0], "sp", ft_strlen(args[0])))
    {
        if (!parse_sphere(args, i, object)
            exit(1);
        i++
    }
    else if (!ft_strncmp(args[0], "pl", ft_strlen(args[0])))
    {
        parse_plane(args, parse, pla);
        i++;
    }
    else if (!ft_strncmp(args[0], "cy", ft_strlen(args[0])))
    {
        parse_cylinder(args, parse, cyl);
        i++;
    }
}

t_object    **read_objects(int fd, t_parse *parse)
{
    char        *line;
    char        **args;
    t_object    **object;
    int         total;

    line = get_next_line(fd);
    malloc_objects(parse);
    total = parse->spheres + parse->planes + parse->cylinders;
    object = malloc(total * sizeof(t_object *));
    if (!object)
        exit_error("fatal", NULL, NULL);
    while (line)
    {
        args = safe_split(line, ' ');
        free (line);
        recon_object(args, parse, object);
        free_array(args);
        line = get_next_line(fd);
    }
}

void    count_objects(char **args, t_parse *parse)
{
    if (!ft_strncmp(args[0], "sp", ft_strlen(args[0])))
        parse->spheres++;
    if (!ft_strncmp(args[0], "pl", ft_strlen(args[0])))
        parse->planes++;
    if (!ft_strncmp(args[0], "cy", ft_strlen(args[0])))
        parse->cylinders++; 
}

void    read_file(int fd, t_parse *parse, t_bool flag)
{
    char    *line;
    char    **args;

    line = get_next_line(fd);
    while (flag == FALSE && line)
    {
        args = ft_split(line, ' ');
        free(line);
            if (validate_line(args, parse) != TRUE)
                exit_error("Parsing", args, NULL);
        free_array(args);
        line = get_next_line(fd);
    }
    while (flag == TRUE && line)
    {
        args = ft_split(line, ' ');
        free(line);
        count_objects(args, parse);
        free_array(args);
        line = get_next_line(fd);
    }
    close (fd);
}

t_object **check_file(char *file, t_parse *parse, t_bool flag)
{
    int         len;
    int         fd;
    t_object    **object;

    len = ft_strlen(file);
    if (ft_strncmp(file + (len - 3), ".rt", 3) != 0)
        exit_error("File must be in format .rt", NULL, NULL);
    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit_error("Failed to open the file please check name, path and permissions", NULL, NULL);
    if (flag == FALSE)
    {
        read_file(fd, parse, FALSE);
        check_file(file, parse, TRUE);
    }
    else if (flag == TRUE)
    {
        read_file(fd, parse, TRUE);
        check_file(file, parse, 2);
    }
    else
    {
        object = read_objects(fd, parse);
        return (object);
    }
}
