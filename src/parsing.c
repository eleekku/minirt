#include "../inc/minirt.h"

void    validate_light(char **args, t_scene *scene)
{
    char    **coordinates;
    int     i;
    float   brightness;

    i = -1;
    coordinates = safe_split(args[1], ',');
    while (++i < 2)
        scene->lightc[i] = fill_value(coordinates[i], args, coordinates, NULL);
    free_array(coordinates);
    if (!ft_isdigit(args[2][0]))
        exit_error("invalid light brightness format", args, NULL);
    brightness = fill_value(args[2], args, NULL, NULL);
    if (!(brightness >= 0.0 && brightness <= 1.0))
        exit_error("Invalid light brightness value", args, NULL);
    if (args[3])
        exit_error("too many values in light", args, NULL);
    
};

void    validate_ambient(char **args, t_scene *scene)
{
        float   lightratio;
        char    **rgb;
        int     i;
        float   value;

        i = -1;
        if (!ft_isdigit(args[1][0]))
            exit_error("invalid format", args, NULL);
        lightratio = ft_atof(args[1]);
        if (lightratio < 0.0 || lightratio > 1.0)
            exit_error("invalid ambient light ratio", args, NULL);
        scene->alightr = lightratio;
        validate_values(args[2], args, NULL);
        rgb = safe_split(args[2], ',');
        while (++i <= 2)
        {
            value = ft_atoi(rgb[i]);
            if (!(value >= 0 && value <= 255))
                exit_error("invalid ambient rgb value", args, NULL);
            scene->amcolor[i] = value;
        }
        if (args[i])
            exit_error("too many values in ambien rgb", args, NULL);
        free_array(rgb);      
}

void    validate_camera(char **args, t_scene *scene)
{
        int     i;
        char    **coordinates;
        int     fow;

        i = -1;
        validate_values(args[1], args, NULL);
        coordinates = safe_split(args[1], ',');
        while (++i < 2)
            scene->camc[i] = fill_value(coordinates[i], args, coordinates, scene);
        i = -1;
        free_array(coordinates);
        validate_values(args[2], args, NULL);
        coordinates = safe_split(args[2], ',');
        while (++i < 2)
            scene->normv[i] = fill_value(coordinates[i], args, coordinates, scene);
        free_array(coordinates); 
        fow = ft_atoi(args[3]);
        if (!ft_isdigit(args[3][0]) && args[3][0] != '0')
            exit_error("invalid fow format", args, NULL);
        if (fow < 0 || fow > 180)
            exit_error("invalid fow format", args, NULL);
        scene->fow = fow;
}

t_bool  validate_line(char **args, t_scene *scene)
{
    if (!ft_strncmp(args[0], "A", ft_strlen(args[0])))
        validate_ambient(args, scene);
    else if (!ft_strncmp(args[0], "C", ft_strlen(args[0])))
        validate_camera(args, scene);
    else if (!ft_strncmp(args[0], "L", ft_strlen(args[0])))
        validate_light(args, scene);
    else if (!ft_strncmp(args[0], "sp", ft_strlen(args[0])))
        return (TRUE);
    else if (!ft_strncmp(args[0], "pl", ft_strlen(args[0])))
        return (TRUE);
    else if (!ft_strncmp(args[0], "cy", ft_strlen(args[0])))
        return (TRUE);
    else if (!ft_strncmp(args[9], "\n", (ft_strlen(args[0]))))
        return (TRUE);
    else
        return (FALSE);
    return (TRUE); 
}

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

void    malloc_objects(t_scene *scene)
{
    if (scene->spheres > 0)
    {
    scene->sp = malloc(sizeof(t_sphere) * scene->spheres);
        if (!scene->sp)
            exit;
    }
    if (scene->planes > 0)
    {
    scene->sp = malloc(sizeof(t_plane) * scene->planes);
        if (!scene->pl)
        {
            free(scene->sp);
            exit_error("malloc error", NULL, NULL);
        }
    }
    if (scene->spheres > 0)
    {
    scene->sp = malloc(sizeof(t_cylinder) * scene->planes);
        if (!scene->cy)
        {
            free(scene->sp);
            free(scene->pl);
            exit_error("malloc error", NULL, NULL);
        }
    }
}

void    parse_plane(char **args, t_scene *scene, int index)
{
        char    **values;
        int     i;
        float   temp;

        validate_values(args[1], args, scene);
        i = -1;
        values = safe_split(args[1], ',');
        while (++i < 2)
        scene->pl[index].coord[i] = fill_value(values[i], args, values, scene);
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
        

}

void    parse_sphere(char **args, t_scene *scene, int index)
{
        char    **values;
        int     i;
        int     temp;

        validate_values(args[1], args, scene);
        i = -1;
        values = safe_split(args[1], ',');
        while (++i < 2)
        scene->sp[index].center[i] = fill_value(values[i], args, values, scene);
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

void    recon_object(char **args, t_scene *scene)
{
    static int     sph;
    static int     pla;
    static int     cyl;
    
    if (!ft_strncmp(args[0], "sp", ft_strlen(args[0])))
    {
        sph++;
        parse_sphere(args, scene, sph);
    }
    if (!ft_strncmp(args[0], "pl", ft_strlen(args[0])))
    {
        pla++;
        //
    }
    if (!ft_strncmp(args[0], "sp", ft_strlen(args[0])))
    {
        cyl++;
        scene->cylinders++;
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
    else if (flag == FALSE)
    {
        read_file(fd, scene, TRUE);
        check_file(file, scene, 2);
    }
    else
        read_objects(fd, scene);


}
int main(int argc, char **argv)
{
    t_scene scene;

    scene.spheres = 0;
    scene.planes = 0;
    scene.planes = 0;

    if (argc != 2)
    {
        ft_printf(2, "Error\nPlease input one and only one file\n");
        exit (1);
    }
    check_file(argv[1], &scene, FALSE);
 
}