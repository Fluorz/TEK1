/*
** intersect_plane.c for bs in /home/byliarus/work/Graph/bsraytracer1/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Feb 14 10:57:59 2017 John Doe
** Last update Fri Mar 10 19:52:57 2017 John Doe
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
