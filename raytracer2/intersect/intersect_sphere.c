/*
** intersect_sphere.c for bs in /home/byliarus/work/Graph/bsraytracer1/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Feb 13 13:36:55 2017 John Doe
** Last update Tue Feb 14 10:33:40 2017 John Doe
*/

#include "my.h"

float calc(float a, float b, float c)
{
  float dis;
  float k1;
  float k2;
  float k;

  dis = pow(b, 2) - (4 * a * c);
  if (dis == 0)
    k = -b / (2 * a);
  else if (dis > 0)
  {
    k1 = (-b + sqrt(dis)) / (2 * a);
    k2 = (-b - sqrt(dis)) / (2 * a);
    if (k1 > k2)
      k = k2;
    else
      k = k1;
  }
  else if (dis < 0)
    return (-1);
  return (k);
}

float intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector, float radius)
{
  float a;
  float b;
  float c;

  a = pow(dir_vector.x, 2) + pow(dir_vector.y, 2) + pow(dir_vector.z, 2);
  b = 2 * ((eye_pos.x * dir_vector.x) + (eye_pos.y * dir_vector.y) +
    (eye_pos.z * dir_vector.z));
  c = pow(eye_pos.x, 2) + pow(eye_pos.y, 2) + pow(eye_pos.z, 2) -
  pow(radius, 2);
  return (calc(a, b, c));
}
