/*
** light.c for raytraicer1 in /home/byliarus/work/Graph/raytracer1/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sat Mar 11 00:23:10 2017 John Doe
** Last update Sun Mar 19 20:24:49 2017 John Doe
*/

#include "my.h"

void normalize(sfVector3f *vec)
{
  float norm;

  norm = sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
  vec->x /= norm;
  vec->y /= norm;
  vec->z /= norm;
}

float get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float res;

  normalize (&normal_vector);
  normalize (&light_vector);
  res = normal_vector.x * light_vector.x + normal_vector.y * light_vector.y +
  normal_vector.z * light_vector.z;
  if (res < 0)
    res = 0;
  if (res > 1)
    res = 1;
  return (res);
}

sfColor my_light(t_object object, sfVector2f size, sfVector2i pos,
   sfVector3f light)
{
  sfColor color;
  float coef;

  color = object.color;
  light.x -= object.inter.x;
  light.y -= object.inter.y;
  light.z -= object.inter.z;
  coef = get_light_coef(light, object.normal);
  color.r *= coef;
  color.g *= coef;
  color.b *= coef;
  return (color);
}
