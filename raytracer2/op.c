/*
** op.c for src in /home/byliarus/work/Graph/raytracer1/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Mar 13 19:18:26 2017 John Doe
** Last update Sun Mar 19 20:39:46 2017 John Doe
*/

#include "my.h"

sfColor selecte_col(t_value *value, sfVector2f size, sfVector2i pos)
{
  int i;
  float l;
  int j;
  sfVector3f light =
  {0, 0, 0};

  l = -1;
  i = 0;
  j = 0;
  while (value->objects[i].bol != 0)
  {
    if (l < 0)
    {
      l = value->objects[i].k;
      j = i;
    }
    else if (value->objects[i].k > 0 && value->objects[i].k < l)
    {
      l = value->objects[i].k;
      j = i;
    }
    i++;
  }
  if (l < 0)
    return (sfBlack);
  else
    return (my_light(value->objects[j], size, pos, light));
}

void k_value(t_value *value, sfVector2i pos, sfVector3f ray)
{
  int i;

  i = 0;
  while (value->objects[i].bol != 0)
    {
      if (value->objects[i].type == 's')
        op_sphere(value, ray, i);
      else if (value->objects[i].type == 'c')
        op_cylinder(value, ray, i);
      else if (value->objects[i].type == 'q')
        value->objects[i].k = intersect_cone(value->objects[i].eye,
           ray, value->objects[i].size);
      else if (value->objects[i].type == 'p')
      {
        value->objects[i].k = intersect_plane(value->objects[i].eye,
          ray);
        ray.x *= value->objects[i].k;
        ray.y *= value->objects[i].k;
        ray.z *= value->objects[i].k;
        value->objects[i].inter = ray;
        value->objects[i].normal = get_normal_plane(1);
      }
      i++;
    }
}

void init_eye(t_value *value)
{
  int i;
  sfVector3f eye =
  {0, 0, 0};

  i = 0;
  while (value->objects[i].bol != 0)
  {
    if (value->objects[i].type != 'p')
      value->objects[i].eye = my_transformations(&value->objects[i], eye);
    i++;
  }
}
