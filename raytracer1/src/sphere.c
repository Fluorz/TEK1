/*
** sphere.c for sphere.c in /home/lecherbonnier/Projet/raytracer1/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Mar 15 11:37:23 2017 Leo Lecherbonnier
** Last update Fri Mar 17 10:34:51 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

float intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector, float radius)
{
  double	a;
  double	b;
  double	c;

  a = pow(dir_vector.x, 2) + pow(dir_vector.y, 2) + pow(dir_vector.z, 2);
  b = 2 * (eye_pos.x * dir_vector.x + eye_pos.y *
	   dir_vector.y + eye_pos.z * dir_vector.z);
  c = pow(eye_pos.x, 2) + pow(eye_pos.y, 2)
      + pow(eye_pos.z, 2) - pow(radius, 2);
  return (check_delta(a, b, c));
}

static	float	check_pos(float nb)
{
  if (nb > 0)
    return (nb);
  return (-1);
}

static	float	check_delta(double a, double b, double c)
{
  double	x1 = 0.0;
  double	x2 = 0.0;
  double	delta = 0.0;

  delta = (b * b) - (4 * a * c);
  if (delta == 0.0)
    return (check_pos(- b / (2 * a)));
  if (delta > 0.0)
    {
      x1 = (-b - sqrt(delta)) / (2 * a);
      x2 = (-b + sqrt(delta)) / (2 * a);
      if (x1 < 0 && x2 < 0)
	return (-1);
      if (x1 > 0 && x2 > 0)
	{
	  if (x1 > x2)
	    return (x2);
	  return (x1);
	}
      if (x1 > x2)
	return (x1);
      return (x2);
    }
  if (delta < 0)
    return (-1);
}

sfVector3f get_normal_sphere(sfVector3f intersection_point)
{
  return (intersection_point);
}
