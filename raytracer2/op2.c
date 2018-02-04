/*
** op2.c for raytracer1 in /home/byliarus/work/Graph/raytracer1/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sun Mar 19 20:34:32 2017 John Doe
** Last update Sun Mar 19 20:38:53 2017 John Doe
*/

#include "my.h"

void op_sphere(t_value *value, sfVector3f ray, int i)
{
  value->objects[i].k = intersect_sphere(value->objects[i].eye,
  ray, value->objects[i].size);
  ray.x *= value->objects[i].k;
  ray.y *= value->objects[i].k;
  ray.z *= value->objects[i].k;
  value->objects[i].inter = ray;
  value->objects[i].normal = get_normal_sphere(ray, value->objects[i].pos);
}

void op_cylinder(t_value *value, sfVector3f ray, int i)
{
  value->objects[i].k = intersect_cylinder(value->objects[i].eye,
  ray, value->objects[i].size);
  ray.x *= value->objects[i].k;
  ray.y *= value->objects[i].k;
  ray.z *= value->objects[i].k;
  value->objects[i].inter = ray;
  value->objects[i].normal = get_normal_cylinder(ray, value->objects[i].pos);
}
