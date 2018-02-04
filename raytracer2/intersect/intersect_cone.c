/*
** intersect_sphere.c for bs in /home/byliarus/work/Graph/bsraytracer1/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Feb 13 13:36:55 2017 John Doe
** Last update Mon Mar  6 19:28:28 2017 John Doe
*/

#include "my.h"

float intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector, float radius)
{
  float a;
  float b;
  float c;
  float p;

  p = radius * M_PI / 180.0;
  a = pow(dir_vector.x, 2) + pow(dir_vector.y, 2) - (pow(dir_vector.z, 2) * pow(tan(p), 2));
  b = ((2 * eye_pos.x * dir_vector.x) + (2 * eye_pos.y * dir_vector.y) - ((2 * eye_pos.z * dir_vector.z) * pow(tan(p), 2)));
  c = pow(eye_pos.x, 2) + pow(eye_pos.y, 2) - (pow(eye_pos.z, 2) *
  pow(tan(p), 2));
  return (calc(a, b, c));
}
