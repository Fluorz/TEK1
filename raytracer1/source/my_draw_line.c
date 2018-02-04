/*
** draw_line.c for draw_line.c in /home/lecherbonnier/Bureau/bswireframe/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Dec  8 13:59:49 2016 Leo Lecherbonnier
** Last update Wed Mar  8 10:26:30 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

void my_draw_line(t_my_framebuffer* framebuffer, sfVector2i from,
		  sfVector2i to, sfColor color)
{
  sfColor	sfRed;
  float		dx;
  float		dy;
  float		len;
  float		y;
  float		yy;
  float		x;
  int		i;

  if (abs((float)to.x - (float)from.x) >= abs((float)to.y - (float)from.y))
    len = abs((float)to.x -  (float)from.x);
  else
    len = abs((float)to.y -  (float)from.y);
  dx = ((float)to.x - (float)from.x) / len;
  dy = ((float)to.y - (float)from.y) / len;
  x = (float)from.x + 0.5;
  y = (float)from.y + 0.5;
  i = 0;
  while (i <= len)
    {
      my_put_pixel(framebuffer, (int)x, (int)y, color);
      x = x + dx;
      y = y + dy;
      i = i + 1;
    }
}
