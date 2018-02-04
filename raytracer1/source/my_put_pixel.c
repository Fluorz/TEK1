/*
** my_put_pixels.c for put_pixels.c in /home/lecherbonnier/Bureau/bswireframe/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Dec  8 14:02:56 2016 Leo Lecherbonnier
** Last update Wed Mar  8 10:26:29 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

void my_put_pixel(t_my_framebuffer* framebuffer, int x, int y, sfColor color)
{
  if (x < 0 || y < 0 || x > framebuffer->width -1
      || y > framebuffer->height - 1)
    return ;
  framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
  framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
}
