#include "../inc/minirt.h"

void    validate_light(char **args, t_scene *scene)
{
    char    **coordinates;
    int     i;
    float   brightness;

    i = -1;
    coordinates = safe_split(args[1], ',');
    while (++i < 2)
        scene->lightc[i] = fill_value(coordinates[i], args, coordinates);
    free_array(coordinates);
    if (!ft_isdigit(args[2][0]))
        exit_error("invalid light brightness format", args);
    brightness = fill_value(args[2], args, NULL);
    if (!(brightness >= 0.0 && brightness <= 1.0))
        exit_error("Invalid light brightness value", args);
    if (args[3])
        exit_error("too many values in light", args);
    
};

void    validate_ambient(char **args, t_scene *scene)
{
        float   lightratio;
        char    **rgb;
        int     i;
        float   value;

        i = -1;
        if (!ft_isdigit(args[1][0]))
            exit_error("invalid format", args);
        lightratio = ft_atof(args[1]);
        if (lightratio < 0.0 || lightratio > 1.0)
            exit_error("invalid ambient light ratio", args);
        scene->alightr = lightratio;
        validate_values(args[2], args);
        rgb = safe_split(args[2], ',');
        while (++i <= 2)
        {
            value = ft_atoi(rgb[i]);
            if (!(value >= 0 && value <= 255))
                exit_error("invalid ambient rgb value", args);
            scene->amcolor[i] = value;
        }
        if (args[i])
            exit_error("too many values in ambien rgb", args);
        free_array(rgb);      
}

void    validate_camera(char **args, t_scene *scene)
{
        int     i;
        char    **coordinates;
        int     fow;

        i = -1;
        validate_values(args[1], args);
        coordinates = safe_split(args[1], ',');
        while (++i < 2)
            scene->camc[i] = fill_value(coordinates[i], args, coordinates);
        i = -1;
        free_array(coordinates);
        validate_values(args[2], args);
        coordinates = safe_split(args[2], ',');
        while (++i < 2)
            scene->normv[i] = fill_value(coordinates[i], args, coordinates);
        free_array(coordinates); 
        fow = ft_atoi(args[3]);
        if (!ft_isdigit(args[3][0]) && args[3][0] != '0')
            exit_error("invalid fow format", args);
        if (fow < 0 || fow > 180)
            exit_error("invalid fow format", args);
        scene->fow = fow;
}

t_bool  validate_line(char *arg, char **args, t_scene *scene)
{
    if (!ft_strncmp(arg, "A", ft_strlen(arg)))
        validate_ambient(args, scene);
    else if (!ft_strncmp(arg, "C", ft_strlen(arg)))
        validate_camera(args, scene);
    else if (!ft_strncmp(arg, "L", ft_strlen(arg)))
        validate_light(args, scene);
    else if (!ft_strncmp(arg, "sp", ft_strlen(arg)))
        return (TRUE);
    else if (!ft_strncmp(arg, "pl", ft_strlen(arg)))
        return (TRUE);
    else if (!ft_strncmp(arg, "cy", ft_strlen(arg)))
        return (TRUE);
    else if (!ft_strncmp(arg, "\n", (ft_strlen(arg))))
        return (TRUE);
    else
        return (FALSE);
    return (TRUE); 
}

void    read_file(int fd, t_scene *scene)
{
    char    *line;
    char    **args;
    int     i;

    line = get_next_line(fd);
    while (line)
    {
    args = ft_split(line, ' ');
    free(line);
    i = -1;
    while (args[++i])
        if (validate_line(args[i], args, scene) != TRUE)
            exit_error("Invalid file format", args);
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
        exit_error("File must be in format .rt", NULL);
    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit_error("Failed to open the file please check name, path and permissions", NULL);
    if (flag == FALSE)
    {
        read_file(fd, scene);
        check_file(file, scene, TRUE);
    }

}
int main(int argc, char **argv)
{
    t_scene scene;

    if (argc != 2)
    {
        ft_printf(2, "Error\nPlease input one and only one file\n");
        exit (1);
    }
    check_file(argv[1], &scene, FALSE);
 
}