/*
** clear_window.c for clear_window.c in /home/lecherbonnier/wolf3d/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Jan  5 22:36:09 2017 Leo Lecherbonnier
** Last update Wed Mar  8 10:25:46 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

void	my_clear(t_my_framebuffer *framebuffer)
{
  int	i;
  int	len;

  i = 0;
  len = framebuffer->width * framebuffer->height * 4;
  while (i < len)
    {
      framebuffer->pixels[i] = 0;
      i++;
    }
}
