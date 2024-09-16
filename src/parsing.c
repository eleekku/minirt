#include "../inc/minirt.h"

void    validate_light(char **args, t_parse *parse)
{
    char    **coordinates;
    int     i;
    float   brightness;

    i = -1;
    coordinates = safe_split(args[1], ',');
    while (++i <= 2)
        parse->lcoord[i] = fill_value(coordinates[i], args, coordinates, NULL);
    free_array(coordinates);
    if (!ft_isdigit(args[2][0]))
        exit_error("invalid light brightness format", args);
    brightness = fill_value(args[2], args, NULL, NULL);
    if (!(brightness >= 0.0 && brightness <= 1.0))
        exit_error("Invalid light brightness value", args);
    parse->lbrightness = brightness;
    if (args[3])
    {
        if (!validate_values(args[3], args, NULL))
            return (FALSE);
        if (!fill_rgb(args[3], parse->lcolor))
            return (FALSE);
    }
    if (args[3] && args[4])
        return (FALSE);
    return (TRUE);
}

t_bool    validate_ambient(char **args, t_parse *parse)
{
        float   lightratio;

        if (!ft_isdigit(args[1][0]))
            exit_error("invalid format", args);
        lightratio = ft_atof(args[1]);
        if (lightratio < 0.0 || lightratio > 1.0 || (lightratio == 0.0 && args[1][0] != '0'))
            return (FALSE);
        parse->alightr = lightratio;
        if (!validate_values(args[2], args, NULL))
            return (FALSE);
        if (!fill_rgb(parse->amcolor, args[2]));
            return (FALSE);
        if (args[3])
            return (FALSE);
        return (TRUE);    
}

t_bool    validate_camera(char **args, t_parse *parse)
{
        int     i;
        char    **coordinates;
        int     fow;

        i = -1;
        if (!validate_values(args[1], args))
            return (FALSE);
        coordinates = safe_split(args[1], ',');
        while (++i <= 2)
            parse->camc[i] = fill_value(coordinates[i], args, coordinates, NULL);
        i = -1;
        free_array(coordinates);
        if (!validate_values(args[2], args))
            return (FALSE);
        coordinates = safe_split(args[2], ',');
        while (++i < 2)
            parse->normv[i] = fill_value(coordinates[i], args, coordinates, parse);
        free_array(coordinates); 
        fow = ft_atoi(args[3]);
        if (!ft_isdigit(args[3][0]) && args[3][0] != '0')
            exit_error("invalid fow format", args);
        if (fow < 0 || fow > 180)
            exit_error("invalid fow format", args);
        parse->fow = fow;
        return (TRUE);
}

t_bool  validate_line(char **args, t_parse *parse)
{
    if (!ft_strncmp(args[0], "A", ft_strlen(args[0])))
        validate_ambient(args, parse);
    else if (!ft_strncmp(args[0], "C", ft_strlen(args[0])))
        return (validate_camera(args, parse));
    else if (!ft_strncmp(args[0], "L", ft_strlen(args[0])))
        validate_light(args, parse);
    else if (!ft_strncmp(args[0], "sp", ft_strlen(args[0])) || 
    !ft_strncmp(args[0], "pl", ft_strlen(args[0])) ||
    !ft_strncmp(args[0], "cy", ft_strlen(args[0])) ||
    !ft_strncmp(args[0], "\n", (ft_strlen(args[0]))))
        return (TRUE);
    else
        return (FALSE);
    return (TRUE); 
}

/*
int main(int argc, char **argv)
{
    t_parse parse;

    parse.spheres = 0;
    parse.planes = 0;
    parse.planes = 0;

    if (argc != 2)
    {
        ft_printf(2, "Error\nPlease input one and only one file\n");
        exit (1);
    }
    check_file(argv[1], &parse, FALSE);
}*/