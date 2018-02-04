/*
** plane.c for src in /home/byliarus/work/Graph/raytracer1/src/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Mar 13 14:21:53 2017 John Doe
** Last update Mon Mar 13 14:22:17 2017 John Doe
*/

#include "my.h"

float intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
float k;

if (dir_vector.z == 0)
  return (-1);
else if ((k = (-eye_pos.z - 25) / dir_vector.z) <= 0)
  return (-1);
return (k);
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
