/*
** light.c for light.c in /home/lecherbonnier/Projet/raytracer1/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Mar 16 09:23:15 2017 Leo Lecherbonnier
** Last update Fri Mar 17 15:46:50 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

static	sfVector3f	set_vector(double longeur, sfVector3f vector)
{
  vector.x = vector.x / longeur;
  vector.y = vector.y / longeur;
  vector.z = vector.z / longeur;
  return (vector);
}

float get_light_coef(sfVector3f light_vector, sfVector3f normal_vector)
{
  double	longeur;
  float	light;
  double	a;
  double	b;
  double	c;

  longeur = sqrt(pow(light_vector.x, 2) + pow(light_vector.y, 2)
		 + pow(light_vector.z, 2));
  if (longeur <= 0)
    return (0.0);
  light_vector = set_vector(longeur, light_vector);
  longeur = sqrt(pow(normal_vector.x, 2) + pow(normal_vector.y, 2)
		 + pow(normal_vector.z, 2));
  if (longeur <= 0)
    return (0.0);
  normal_vector = set_vector(longeur, normal_vector);
  a = light_vector.x * normal_vector.x;
  b = light_vector.y * normal_vector.y;
  c = light_vector.z * normal_vector.z;
  light = a + b + c;
  if (light <= 0)
    return (0);
  else if (light > 1)
    return (1);
  return (light);
}
