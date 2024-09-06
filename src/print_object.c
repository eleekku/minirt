#include "../inc/minirt.h"

t_object    object_sphere(t_scene *scene, int index)
{
    t_object object;
    object.s = SPHERE;
	object.coord = scene->sp[index].center;
	object.diameter = scene->sp[index].diameter;
	object.color[0] = scene->sp[index].color[0];
	object.color[1] = scene->sp[index].color[1];
	object.color[2] = scene->sp[index].color[2];
    object.material = material(scene);
    return(object);
}

void    print_sphere(t_scene *scene, int index, mlx_image_t *img)
{
    float *ray_origin;
    float wall_z;
    float wall_size, half, pixel_size, canvas_pixels;
    int x, y;
    float world_x, world_y;
    float *position;
    float **ray;
    t_intersections	xs;
    t_intersection  hitpoint;
    t_matrix scaling;
    t_matrix transformation;
    t_matrix inversed;
    t_matrix translate;
    float *reminder;
    t_object object;
    float *normal;
    float *eyev;
    int     *pcol;
    int     endcolor;

    object = object_sphere(scene, index);
    float radius = scene->sp[index].diameter / 2;
    scaling = create_scaling(radius, radius, radius);
    translate = create_translate(1 + scene->movement.x, 1 + scene->movement.y, 1 + scene->movement.z);
    transformation = matrix_multiply(scaling.m, translate.m);
    object.transform = transformation;
    inversed = inverse_matrix(transformation);
    x = 0;
    y = 0;    
    ray_origin = create_point(scene->camc[0], scene->camc[1], scene->camc[2]);
    wall_z = 12;
    canvas_pixels = 1200;
	wall_size = 25;
	half = wall_size / 2;
	pixel_size = wall_size / canvas_pixels;
    (void)img;
    object.transform = create_identity();

	float *rayposition;
    while (y < canvas_pixels)
    {
        world_y = half - pixel_size * y;
        while (x < canvas_pixels)
        {
            world_x = -half + pixel_size * x;
            position = tuple(world_x, world_y, wall_z, 1);
            reminder = tuple_subs(position, ray_origin); 
            ray = create_ray(ray_origin, normalize(reminder));
            free (reminder);
            transform_ray(ray, inversed.m);
            xs = intersects(&scene->sp[index], ray);
            hitpoint = hit(xs);
            if (hitpoint.t != -1)
            {
               // printf("y:%d x:%d\n", y, x);
                rayposition = ray_position(ray, hitpoint.t);
                normal = normal_at(&object, rayposition);
                eyev = negate_vector(ray[1]);
                pcol = lighting(scene, position, eyev, normal, index);
                endcolor = colors_to_int(pcol, 256);
                mlx_put_pixel(img, x, y, endcolor);
                free(eyev);
				free(normal);
            }
            x++;
            free(ray);
        }
    x = 0;
    y++;
    }
}
void    print_object(t_scene *scene, mlx_image_t *img)
{
    int i;

    i = -1;
    while(++i < scene->spheres)
        print_sphere(scene, i, img);
}