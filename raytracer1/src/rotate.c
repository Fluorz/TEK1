/*
** rotate.c for rotate.c in /home/lecherbonnier/Projet/raytracer1/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 14 18:16:27 2017 Leo Lecherbonnier
** Last update Fri Mar 17 15:26:31 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

static	sfVector3f	set_angle(sfVector3f angles)
{
  angles.x = (angles.x * M_PI) / 180;
  angles.y = (angles.y * M_PI) / 180;
  angles.z = (angles.z * M_PI) / 180;
  return (angles);
}

sfVector3f rotate_xyz(sfVector3f to_rotate, sfVector3f angles)
{
  double	x = 0.0;
  double	y = 0.0;
  double	z = 0.0;

  angles = set_angle(angles);
  x = to_rotate.x;
  y = to_rotate.y;
  z = to_rotate.z;
  to_rotate.x = x;
  to_rotate.y = (cos(angles.x) * y) + (-sin(angles.x) * z);
  to_rotate.z = (sin(angles.x) * y) + (cos(angles.x) * z);
  x = to_rotate.x;
  y = to_rotate.y;
  z = to_rotate.z;
  to_rotate.x = (cos(angles.y) * x) + (sin(angles.y) * z);
  to_rotate.y = y;
  to_rotate.z = -(sin(angles.y) * x) + (cos(angles.y) * z);
  x = to_rotate.x;
  y = to_rotate.y;
  z = to_rotate.z;
  to_rotate.x = (cos(angles.z) * x) - (sin(angles.z) * y);
  to_rotate.y = (sin(angles.z) * x) + (cos(angles.z) * y);
  to_rotate.z = z;
  return (to_rotate);
}

sfVector3f rotate_zyx(sfVector3f to_rotate, sfVector3f angles)
{
  double	x = 0.0;
  double	y = 0.0;
  double	z = 0.0;

  angles = set_angle(angles);
  x = to_rotate.x;
  y = to_rotate.y;
  z = to_rotate.z;
  to_rotate.x = (cos(angles.z) * x) + (-sin(angles.z) * y);
  to_rotate.y = (sin(angles.z) * x) + (cos(angles.z) * y);
  to_rotate.z = z;
  x = to_rotate.x;
  y = to_rotate.y;
  z = to_rotate.z;
  to_rotate.x = (cos(angles.y) * x) + (sin(angles.y) * z);
  to_rotate.y = y;
  to_rotate.z = (-sin(angles.y) * x) + (cos(angles.y) * z);
  x = to_rotate.x;
  y = to_rotate.y;
  z = to_rotate.z;
  to_rotate.x = x;
  to_rotate.y = (cos(angles.x) * y) - (sin(angles.x) * z);
  to_rotate.z = (sin(angles.x) * y) + (cos(angles.x) * z);
  return (to_rotate);
}
