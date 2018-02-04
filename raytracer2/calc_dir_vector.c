/*
** calc_dir_vector.c for bs in /home/byliarus/work/Graph/bsraytracer1/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Feb 13 13:26:29 2017 John Doe
** Last update Fri Mar 17 17:57:52 2017 John Doe
*/

#include "my.h"

sfVector3f calc_dir_vector(sfVector2i pos)
{
  sfVector3f res;

  res.y = (((float)pos.x / (float)WIDTH) * 2) - 1;
  res.z = (((float)pos.y / (float)HEIGHT) * 2) - 1;
  res.x = -1;
  return (res);
}
