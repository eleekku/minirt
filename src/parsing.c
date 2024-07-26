#include "../inc/minirt.h"

void    free_array(char **args)
{
    int i;

    i = -1;
    while(args[++i])
        free(args[i]);
    free(args);
}

void    exit_error(char *msg)
{
    ft_printf(2, "Error\n%s\n", msg);
    exit(1);
}

t_bool    validate_values(char *arg)
{
    char    **rgb;
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
            exit_error("Invalid value format");
        i++;
    }
    if (coma > 2)
        exit_error("Invalid egb format");
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

void    validate_ambient(char **args, t_scene *scene)
{
        float   lightratio;
        char    **rgb;
        int     i;
        float   value;

        i = -1;
        if (!ft_isdigit(args[1][0]))
            exit_error("invalid format");
        lightratio = ft_atof(args[1]);
        if (lightratio < 0.0 || lightratio > 1.0)
            exit_error("invalid ambient light ratio");
        scene->alightr = lightratio;
        validate_values(args[2]);
        rgb = safe_split(args[2], ',');
        while (++i <= 2)
        {
            value = ft_atoi(rgb[i]);
            if (!(value >= 0 && value <= 255))
                exit_error("invalid ambient rgb value");
            scene->amcolor[i] = value;
        }
        if (args[i])
            exit_error("too many values in ambien rgb");
        free_array(rgb);      
}

float    fill_value(char *arg)
{
    float   value;

    if (ft_strchr(arg, '.'))
        value = ft_atof(arg);
    else
        value = ft_atoi(arg);
    return (value);
}

void    validate_camera(char **args, t_scene *scene)
{
        int     i;
        char    **coordinates;
        float   value;
        int     fow;

        i = -1;
        validate_values(args[1]);
        coordinates = safe_split(args[1], ',');
        while (++i < 2)
            scene->camc[i] = fill_value(coordinates[i]);
        i = -1;
        free_array(coordinates);
        validate_values(args[2]);
        coordinates = safe_split(args[2], ',');
        while (++i < 2)
            scene->normv[i] = fill_value(coordinates[i]);
        free_array(coordinates); 
        fow = ft_atoi(args[3]);
        if (!ft_isdigit(args[3][0]) && args[3][0] != '0')
            exit_error("invalid fow format");
        if (fow < 0 || fow > 180)
            exit_error("invalid fow format");
        scene->fow = fow;
}

t_bool  validate_line(char *arg, char **args, t_scene *scene)
{
    if (ft_strncmp(arg, "A", ft_strlen(arg)) == 0)
        validate_ambient(args, scene);
    else if (ft_strncmp(arg, "C", ft_strlen(arg)) == 0)
        validate_camera(args, scene);

//    if else ft_strncmp(arg, "L", 1) == 0)

//    if else (ft_strncmp(arg, "sp", 2) == 0)

//    if else (ft_strncmp(arg, "pl", 2) == 0)
    
  //  if else (ft_strncmp(arg, "cy", 2) == 0)
  //  return (TRUE);
//    }
    return (TRUE);
}

void    read_file(int fd, t_scene *scene)
{
    char    *line;
    char    **args;
    int     i;

    line = get_next_line(fd);
    args = ft_split(line, ' ');
    free(line);
    i = -1;
    while (args[++i])
        if (validate_line(args[i], args, scene) != TRUE)
            printf("not validated\n");
    printf("%f", scene->camc[0]);
}

void  check_file(char *file, t_scene *scene)
{
    int len;
    int fd;

    len = ft_strlen(file);
    if (ft_strncmp(file + (len - 3), ".rt", 3) != 0)
    {
        ft_printf(2, "Error\nFile must be in format .rt\n");
        exit(1);
    }
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        ft_printf(2, "Error\nFailed to open the file please check name, path and permissions\n");
        exit(1);
    }
    read_file(fd, scene);
}
int main(int argc, char **argv)
{
    t_scene scene;

    if (argc != 2)
    {
        ft_printf(2, "Error\nPlease input one and only one file\n");
        exit (1);
    }
    check_file(argv[1], &scene);
 
}