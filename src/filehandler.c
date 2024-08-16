#include "../inc/minirt.h"

void    recon_object(char **args, t_scene *scene)
{
    static int     sph;
    static int     pla;
    static int     cyl;
    
    if (!ft_strncmp(args[0], "sp", ft_strlen(args[0])))
    {
        parse_sphere(args, scene, sph);
        sph++;
    }
    else if (!ft_strncmp(args[0], "pl", ft_strlen(args[0])))
    {
        parse_plane(args, scene, pla);
        pla++;
    }
    else if (!ft_strncmp(args[0], "cy", ft_strlen(args[0])))
    {

        parse_cylinder(args, scene, cyl);
        cyl++;
    }
}

void    read_objects(int fd, t_scene *scene)
{
    char    *line;
    char    **args;

    line = get_next_line(fd);
    malloc_objects(scene);
    while (line)
    {
        args = safe_split(line, ' ');
        free (line);
        recon_object(args, scene);
        free_array(args);
        line = get_next_line(fd);
    }
}

void    count_objects(char **args, t_scene *scene)
{
    if (!ft_strncmp(args[0], "sp", ft_strlen(args[0])))
        scene->spheres++;
    if (!ft_strncmp(args[0], "pl", ft_strlen(args[0])))
        scene->planes++;
    if (!ft_strncmp(args[0], "sp", ft_strlen(args[0])))
        scene->cylinders++; 
}

void    read_file(int fd, t_scene *scene, t_bool flag)
{
    char    *line;
    char    **args;

    line = get_next_line(fd);
    while (flag == FALSE && line)
    {
        args = ft_split(line, ' ');
        free(line);
            if (validate_line(args, scene) != TRUE)
                exit_error("Invalid file format", args, NULL);
        free_array(args);
        line = get_next_line(fd);
    }
    while (flag == TRUE && line)
    {
        args = ft_split(line, ' ');
        free(line);
        count_objects(args, scene);
        free_array(args);
        line = get_next_line(fd);
    }
    close (fd);
}

void  check_file(char *file, t_scene *scene, t_bool flag)
{
    int len;
    int fd;

    len = ft_strlen(file);
    if (ft_strncmp(file + (len - 3), ".rt", 3) != 0)
        exit_error("File must be in format .rt", NULL, NULL);
    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit_error("Failed to open the file please check name, path and permissions", NULL, NULL);
    if (flag == FALSE)
    {
        read_file(fd, scene, FALSE);
        check_file(file, scene, TRUE);
    }
    else if (flag == TRUE)
    {
        read_file(fd, scene, TRUE);
        check_file(file, scene, 2);
    }
    else
        read_objects(fd, scene);
}