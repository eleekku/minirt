#include "../inc/minirt.h"

t_material  material(t_scene *scene, int i)
{
    t_material material;

    material.color[0] = scene->sp[i].color[0];
    material.color[1] = scene->sp[i].color[1];
    material.color[2] = scene->sp[i].color[2];
    material.ambient = scene->alightr;
    material.diffuse = 0.9;
    material.specular = 0.9;
    material.shininess = 200.0;
    return (material);
}

float   pow(float base, float exponent)
{
    return exp(exponent * log(base));
}

void    lighting(t_scene *scene, float *point, float *eyev, float *normalv)
{
    int     *effective_color;
    float   *lightv;
    int     *ambient;
    float   *diffuse;
    float   *temp;
    float   light_dot_normal;
    float   *reflectv;
    float   reflect_dot_eye;
    float   factor;
    float   *specular;
    float   *result[3];

    effective_color = combine_colors(scene->sp[0].color, scene->light.color);
    if (!effective_color)
        exit (1);
    lightv = normalize(tuple_subs(scene->light.position, point));
    ambient = multiply_scale(effective_color, scene->material.ambient);
    light_dot_normal = dot_product(normalv, lightv);
    temp = multiply_scale(effective_color, scene->material.diffuse);
    diffuse = multiply_scale(temp, light_dot_normal);
    free (temp);
    reflectv = reflect(negate_vector(lightv), normalv);
    reflect_dot_eye = dot_product(reflectv, eyev);
    factor = pow(reflect_dot_eye, scene->material.shininess);
    temp = multiply_scale(scene->light.color, scene->material.specular);
    specular = multiply_scale(temp, factor);
    free(temp);
    result

}