/*
** get_light.c for src in /home/byliarus/work/Graph/raytracer1/src/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Mar 10 23:03:07 2017 John Doe
** Last update Sat Mar 11 15:12:35 2017 John Doe
*/

#include "my.h"

float get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  float nl;
  float nn;
  float res;

  nl = normal_vector.x * light_vector.x + normal_vector.y *
   light_vector.y + normal_vector.z * light_vector.z;
   nn = sqrt(pow(light_vector.x, 2) + pow(light_vector.y, 2) +
    pow(light_vector.z, 2)) * sqrt(pow(normal_vector.x, 2) +
     pow(normal_vector.y, 2) + pow(normal_vector.z, 2));
  res = acos(nl / nn);
  res = 1 - res;
  return (res);
}
