#include "../inc/minirt.h"

t_bool  validate_line(char *arg)
{
    if (ft_strncmp(arg, "A", 1) == 0 ||
    ft_strncmp(arg, "C", 1) == 0 ||
    ft_strncmp(arg, "L", 1) == 0 ||
    ft_strncmp(arg, "sp", 2) == 0 ||
    ft_strncmp(arg, "pl", 2) == 0 ||
    ft_strncmp(arg, "cy", 2) == 0)
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