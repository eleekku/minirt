#include "../inc/minirt.h"

t_material  material(t_scene *scene, int i)
{
    t_material material;

    material.color[0] = &scene->sp[i].color[0];
    material.color[1] = &scene->sp[i].color[1];
    material.color[2] = &scene->sp[i].color[2];
    material.ambient = scene->alightr;
    material.diffuse = 0.9;
    material.specular = 0.9;
    material.shininess = 200.0;
    return (material);
}

void    free_lightutils(t_lightdot *light)
{
    free(light->ambient);
    free(light->diffuse);
    free(light->specular);
    free(light->effective_color);
    free(light->lightv);
    free(light->temp);
    free(light->reflectv);
}

int    *lighting(t_scene *scene, float *point, float *eyev, float *normalv)
{
    t_lightdot  lightdot;

    lightdot.effective_color = combine_colors(scene->sp[0].color, scene->light.color);
    if (!lightdot.effective_color)
        exit (1);
    lightdot.lightv = normalize(tuple_subs(scene->light.position, point));
    lightdot.ambient = multiply_scale(lightdot.effective_color, scene->material.ambient);
    lightdot.light_dot_normal = dot_product(normalv, lightdot.lightv);
    lightdot.temp = multiply_scale(lightdot.effective_color, scene->material.diffuse);
    lightdot.diffuse = multiply_scale(lightdot.temp, lightdot.light_dot_normal);
    free (lightdot.temp);
    lightdot.reflectv = reflect(negate_vector(lightdot.lightv), normalv);
    lightdot.reflect_dot_eye = dot_product(lightdot.reflectv, eyev);
    lightdot.factor = pow(lightdot.reflect_dot_eye, scene->material.shininess);
    lightdot.temp = multiply_scale(scene->light.color, scene->material.specular);
    lightdot.specular = multiply_scale(lightdot.temp, lightdot.factor);
    lightdot.result[0] = lightdot.ambient[0] + lightdot.diffuse[0] + lightdot.specular[0];
    lightdot.result[1] = lightdot.ambient[1] + lightdot.diffuse[1] + lightdot.specular[1];
    lightdot.result[2] = lightdot.ambient[2] + lightdot.diffuse[2] + lightdot.specular[2];
    free_lightutils(&lightdot);
}
