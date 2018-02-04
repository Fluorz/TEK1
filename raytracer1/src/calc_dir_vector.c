/*
** calc_dir_vector.c for raytracer1.c in /home/lecherbonnier/Projet/raytracer1/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 14 17:58:34 2017 Leo Lecherbonnier
** Last update Tue Mar 14 18:14:44 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

sfVector3f	calc_dir_vector(float dist_to_plane,
				sfVector2i screen_size, sfVector2i screen_pos)
{
  sfVector3f v3f;

  v3f.x = dist_to_plane;
  v3f.y = (float)((screen_size.x / 2) - (screen_pos.x));
  v3f.z = (float)((screen_size.y / 2) - (screen_pos.y));
  return (v3f);
}
