/*
** calc_dir_vector.c for bs in /home/byliarus/work/Graph/bsraytracer1/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Feb 13 13:26:29 2017 John Doe
** Last update Mon Feb 27 14:18:35 2017 John Doe
*/

#include "my.h"

sfVector3f calc_dir_vector(float dist_to_plane, sfVector2i screen_size,
  sfVector2i screen_pos)
{
  sfVector3f res;

  res.y = (screen_size.x / 2) - screen_pos.x;
  res.z = (screen_size.y / 2) - screen_pos.y;
  res.x  = dist_to_plane;
  return (res);
}
