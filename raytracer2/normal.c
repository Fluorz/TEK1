/*
** normal.c for raytracer1 in /home/byliarus/work/Graph/raytracer1/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sat Mar 11 00:28:17 2017 John Doe
** Last update Fri Mar 17 17:59:53 2017 John Doe
*/

#include "my.h"

sfVector3f get_normal_sphere(sfVector3f intersection_point, sfVector3f pos)
{
  intersection_point.x -= pos.x;
  intersection_point.y -= pos.y;
  intersection_point.z -= pos.z;
  normalize(&intersection_point);
  return (intersection_point);
}

sfVector3f get_normal_plane(int upward)
{
  sfVector3f res;

  if (upward == 0)
    res.z = -1;
  else if (upward == 1)
    res.z = 1;
  res.x = 0;
  res.y = 0;
  return (res);
}

sfVector3f get_normal_cylinder(sfVector3f intersection_point, sfVector3f pos)
{
  intersection_point.x -= pos.x;
  intersection_point.y -= pos.y;
  intersection_point.z -= pos.z;
  intersection_point.z = 0;
  return (intersection_point);
}
