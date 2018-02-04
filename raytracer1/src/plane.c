/*
** plane.c for plane.c in /home/lecherbonnier/Projet/raytracer1/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Mar 15 12:07:50 2017 Leo Lecherbonnier
** Last update Fri Mar 17 15:57:04 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

float intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector)
{
  float	intersect_plane;

  if (eye_pos.z == 0)
    return (0.0);
  if (dir_vector.z == 0)
    return (0.0);
  intersect_plane = (- eye_pos.z) / dir_vector.z;
  return (intersect_plane);
}

sfVector3f get_normal_plane(int upward)
{
  sfVector3f normal;

  normal.x = 0;
  normal.y = 0;
  if (upward == 1)
    normal.z = 1;
  else
    normal.z = -1;
  return (normal);
}
