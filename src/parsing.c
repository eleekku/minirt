#include "../inc/minirt.h"

void    validate_ambient(char **args, t_scene *scene)
{
        float   lightratio;
        int     rgb;
        int     i;

        i = 2;
        if (ft_strncmp(args[0], "A", ft_strlen(args[0]) != 0))
            exit;
        if (!ft_isdigit(args[1][0]))
            exit;
        lightratio = ft_atof(args[1]);
        if (lightratio < 0.0 || lightratio > 1.0)
            ft_printf(2, "invalid ambient light ratio\n");
        scene->alightr = ft_atof(args[1]);
        while (i < 5)
        {
            if (!ft_isdigit(args[i][0]))
                ft_printf(2, "invalid ambient rgb value");
            
            rgb = ft_atoi(args[i])
            if (rgb == 0 && args[i][0] != )
        }

        
        
}
t_bool  validate_line(char *arg, char **args, t_scene *scene)
{
    if (ft_strncmp(arg, "A", 1) == 0)
        validate_ambient(args, scene);    
    if else (ft_strncmp(arg, "C", 1) == 0)

    if else ft_strncmp(arg, "L", 1) == 0)

    if else (ft_strncmp(arg, "sp", 2) == 0)

    if else (ft_strncmp(arg, "pl", 2) == 0)
    
    if else (ft_strncmp(arg, "cy", 2) == 0)
    return (TRUE);
    else
    return (FALSE);
}

void    read_file(int fd, t_scene *scene)
{
    char    *line;
    char    **args;

    line = get_next_line(fd);
    args = ft_split(line, ' ');
    free(line);
    if (validate_line(args[1]) != TRUE);


}

void  check_file(char file, t_scene *scene)
{
    int len;
    int fd;

    len = ft_strlen(file);
    if (ft_strncmp(file + (len - 3), ".rt", 3) != 0)
    {
        ft_printf(2, "Error\nFile must be in format .rt\n");
        exit(1);
    }
    fd = OPEN(file, O_RDONLY);
    if (fd == -1)
    {
        ft_printf(2, "Error\nFailed to open the file please check name, path and permissions\n");
        exit(1);
    }
    read_file(fd, scene);
}
int main(int argc, char **argv)
{
    t_scene *scene;

    if (argc != 2)
    {
        fr_printf(2, "Error\nPlease input one and only one file\n");
        exit (1);
    }
    check_file(argv[1], &scene);
 
}