/*
** cylinder.c for src in /home/byliarus/work/Graph/raytracer1/src/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Mar 13 14:17:31 2017 John Doe
** Last update Mon Mar 13 14:21:38 2017 John Doe
*/

#include "my.h"

float intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector, float radius)
{
  float a;
  float b;
  float c;

  a = pow(dir_vector.x, 2) + pow(dir_vector.y, 2);
  b = 2 * ((eye_pos.x * dir_vector.x) + (eye_pos.y * dir_vector.y));
  c = pow(eye_pos.x, 2) + pow(eye_pos.y, 2) - pow(radius, 2);
  return (calc(a, b, c));
}

sfVector3f get_normal_cylinder(sfVector3f intersection_point)
{
  intersection_point.z = 0;
  return (intersection_point);
}
