#include "../inc/minirt.h"

t_bool  validate_light2(char **args, t_parse *parse, int index, t_light *light)
{
    if (args[3])
    {
        if (!validate_values(args[3]))
            return (FALSE);
        if (!fill_rgb(&light->color, args[3]))
            return (FALSE);
    }
    light->color = multiply_color(light->color, parse->lbrightness, 1);
    if (args[3] && args[4])
        return (FALSE);
    parse->light[index] = light;
    return (TRUE);
}

t_bool    validate_light(char **args, t_parse *parse, int index)
{
    char    **coordinates;
    int     i;
    t_light *light;

    light = create_light();
    if (!light)
        return (FALSE);
    i = -1;
    coordinates = safe_split(args[1], ',');
    while (++i <= 2)
        if (!fill_value(coordinates[i], coordinates, &light->coord[i]))
            return (FALSE);
    free_array(coordinates);
    if (!ft_isdigit(args[2][0]))
        exit_error("invalid light brightness format", args, parse);
    if (!fill_value(args[2], NULL, &parse->lbrightness))
        return (FALSE);
    if (!(parse->lbrightness >= 0.0 && parse->lbrightness <= 1.0))
        exit_error("Invalid light brightness value", args, parse);
    return (validate_light2(args, parse, index, light));
}

t_bool    validate_ambient(char **args, t_parse *parse)
{
        float   lightratio;

        if (!args[1])
        return (FALSE);
        if (!ft_isdigit(args[1][0]))
            exit_error("invalid format", args, parse);
        lightratio = ft_atof(args[1]);
        if (lightratio < 0.0 || lightratio > 1.0 || (lightratio == 0.0 && args[1][0] != '0'))
            return (FALSE);
        parse->alightr = lightratio;
        if (!validate_values(args[2]))
            return (FALSE);
        if (!fill_rgb(&parse->amcolor, args[2]))
            return (FALSE);
        parse->amcolor = multiply_color(parse->amcolor, parse->alightr, 1);
        if (args[3])
            return (FALSE);
        return (TRUE);    
}

t_bool    validate_camera(char **args, t_parse *parse)
{
        int     i;
        char    **coordinates;

        i = -1;
        if (!validate_values(args[1]))
            return (FALSE);
        coordinates = safe_split(args[1], ',');
        while (++i <= 2)
            if (!fill_value(coordinates[i], coordinates, &parse->camc[i]))
                return (FALSE);
        i = -1;
        free_array(coordinates);
        if (!validate_values(args[2]))
            return (FALSE);
        coordinates = safe_split(args[2], ',');
        while (++i <= 2)
            if (!fill_value(coordinates[i], coordinates, &parse->normv[i]))
                return (FALSE);
        free_array(coordinates); 
        parse->fow = ft_atoi(args[3]);
        if (!ft_isdigit(args[3][0]) && args[3][0] != '0')
            exit_error("invalid fow format", args, parse);
        if (parse->fow < 0 || parse->fow > 180)
            exit_error("invalid fow format", args, parse);
        return (TRUE);
}

t_bool  validate_line(char **args, t_parse *parse)
{
    static int  index;

    if (!ft_strncmp(args[0], "A", 2))
        return (validate_ambient(args, parse));
    else if (!ft_strncmp(args[0], "C", 2))
        return (validate_camera(args, parse));
    else if (!ft_strncmp(args[0], "L", 2))
    {
        index++;
        return (validate_light(args, parse, index - 1));
    }
    else if (!ft_strncmp(args[0], "sp", 3) || 
    !ft_strncmp(args[0], "pl", 3) ||
    !ft_strncmp(args[0], "cy", 3) ||
    !ft_strncmp(args[0], "\n", 2))
        return (TRUE);
    else
        return (FALSE);
    return (TRUE); 
}