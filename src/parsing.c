#include "../inc/minirt.h"


void  check_format(char file)
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
}
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fr_printf(2, "Error\nPlease input one and only one file\n");
        exit (1);
    }
 
}