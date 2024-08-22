#include "../inc/minirt.h"

void    validate_light(char **args, t_scene *scene)
{
    char    **coordinates;
    int     i;
    float   brightness;

    i = -1;
    coordinates = safe_split(args[1], ',');
    while (++i <= 2)
        scene->light.position[i] = fill_value(coordinates[i], args, coordinates, NULL);
    scene->light.position[i] = 0;
    free_array(coordinates);
    if (!ft_isdigit(args[2][0]))
        exit_error("invalid light brightness format", args, NULL);
    brightness = fill_value(args[2], args, NULL, NULL);
    if (!(brightness >= 0.0 && brightness <= 1.0))
        exit_error("Invalid light brightness value", args, NULL);
    scene->light.brightness = brightness;
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
        if (lightratio < 0.0 || lightratio > 1.0 || (lightratio == 0.0 && args[1][0] != '0'))
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
        while (++i <= 2)
            scene->camc[i] = fill_value(coordinates[i], args, coordinates, NULL);
        scene->camc[i] = 1;
        i = -1;
        free_array(coordinates);
        validate_values(args[2], args, NULL);
        coordinates = safe_split(args[2], ',');
        while (++i < 2)
            scene->normv[i] = fill_value(coordinates[i], args, coordinates, scene);
        scene->normv[i] = 0;
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
    else if (!ft_strncmp(args[0], "\n", (ft_strlen(args[0]))))
        return (TRUE);
    else
        return (FALSE);
    return (TRUE); 
}

/*
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
}*/