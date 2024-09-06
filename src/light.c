#include "../inc/minirt.h"

t_material  material(t_scene *scene)
{
    t_material material;

    material.ambient = scene->alightr;
    material.diffuse = 0.9;
    material.specular = 0.9;
    material.shininess = 100.0;
    return (material);
}

void    free_lightutils(t_lightdot *light)
{
//    printf("im here\n");
    free(light->ambient);
    free(light->diffuse);
    if (light->specular)
        free(light->specular);
    free(light->effective_color);
    free(light->lightv);
 //   printf("next im gonna free temp\n");
 //   if (light->temp)
 //       free(light->temp);
 //   printf("done\n");
    free(light->reflectv);
}

int *fill_color(int rgbvalue)
{
    int *result;
    result = malloc(3 * sizeof(int));
    if (!result)
    {
        printf("fatal error in fill color function\n");
        exit(1);
    }
    result[0] = rgbvalue;
    result[1] = rgbvalue;
    result[2] = rgbvalue;
    return (result);
}

int    *lighting(t_scene *scene, float *point, float *eyev, float *normalv, int i, t_bool shadow)
{
    if (!shadow)
        scene->lightdot.effective_color = combine_colors(scene->sp[i].color, scene->light.color);
    if (!shadow && !scene->lightdot.effective_color)
        exit (1);
    scene->lightdot.lightv = normalize(tuple_subs(scene->light.position, point));
    if (!shadow)
        scene->lightdot.temp = combine_colors(scene->lightdot.effective_color, scene->amcolor);
    else
        scene->lightdot.temp = combine_colors(scene->sp[i].color, scene->amcolor);
    scene->lightdot.ambient = multiply_scale(scene->lightdot.temp, scene->material.ambient);
    free(scene->lightdot.temp);
    if (shadow)
    {
        scene->lightdot.result[0] = clamp_color(scene->lightdot.ambient[0]);
        scene->lightdot.result[1] = clamp_color(scene->lightdot.ambient[1]);
        scene->lightdot.result[2] = clamp_color(scene->lightdot.ambient[2]);
        return (scene->lightdot.result);
    }
    scene->lightdot.light_dot_normal = dot_product(normalv, scene->lightdot.lightv);
    if (scene->lightdot.light_dot_normal < 0)
    {
        scene->lightdot.diffuse = fill_color(0);
        scene->lightdot.specular = fill_color(0);
    }
    else
    {
        scene->lightdot.temp = multiply_scale(scene->lightdot.effective_color, scene->material.diffuse);
        scene->lightdot.diffuse = multiply_scale(scene->lightdot.temp, scene->lightdot.light_dot_normal);
        free (scene->lightdot.temp);
        scene->lightdot.temp = NULL;
    }
    scene->lightdot.reflectv = reflect(negate_vector(scene->lightdot.lightv), normalv);
    scene->lightdot.reflect_dot_eye = dot_product(scene->lightdot.reflectv, eyev);
    if (scene->lightdot.reflect_dot_eye <= 0)
        scene->lightdot.specular = fill_color(0);
    else 
    {
        scene->lightdot.factor = pow(scene->lightdot.reflect_dot_eye, scene->material.shininess);
        scene->lightdot.temp = multiply_scale(scene->light.color, scene->material.specular);
        scene->lightdot.specular = multiply_scale(scene->lightdot.temp, scene->lightdot.factor);
        free(scene->lightdot.temp);
        scene->lightdot.temp = NULL;
    }
    scene->lightdot.result[0] = clamp_color(scene->lightdot.ambient[0] + scene->lightdot.diffuse[0] + scene->lightdot.specular[0]);
    scene->lightdot.result[1] = clamp_color(scene->lightdot.ambient[1] + scene->lightdot.diffuse[1] + scene->lightdot.specular[1]);
    scene->lightdot.result[2] = clamp_color(scene->lightdot.ambient[2] + scene->lightdot.diffuse[2] + scene->lightdot.specular[2]);
    free_lightutils(&scene->lightdot);
    return(scene->lightdot.result);
}
/*
t_light	*point_light(float *pos, float *intensity)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->position = pos;
	light->color = conv_color_for(intensity);
	return (light);
}

float	*lighting(t_material	*m, t_light *l, float *point, t_vectors v)
{
	t_lighting	lighting;
	
	lighting.eff_color = 
}
*/