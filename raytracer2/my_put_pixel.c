/*
** my_put_pixel.c for my_put_pixels.c in /home/pierre/work/c_graphical/wirefra
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Sat Dec 10 14:14:02 2016 Pierre Narcisi
** Last update Mon Mar 13 19:19:56 2017 John Doe
*/

#include "my.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color)
{
  int	i;

  if ((x < framebuffer->width && x >= 0) && (y < framebuffer->height && y >= 0))
    {
      i = (framebuffer->width * y + x) * 4;
      framebuffer->pixels[i] = color.r;
      framebuffer->pixels[i + 1] = color.g;
      framebuffer->pixels[i + 2] = color.b;
      framebuffer->pixels[i + 3] = color.a;
    }
}
