/*
** background.c for draw_sky in /home/lecherbonnier/wolf3d/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Jan 11 16:41:18 2017 Leo Lecherbonnier
** Last update Wed Mar  8 10:25:23 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

void	draw_sky(t_my_framebuffer *framebuffer)
{
  int	i;
  int	c;
  float	stock;
  float	restock;

  i = 0;
  c = 0;
  while (i < (framebuffer->width * framebuffer->height / 2))
    {
      if (i % framebuffer->width == 0)
	if (c <= 90)
	  c++;
      stock = c;
      framebuffer->pixels[i * 4] = 100 + c;
      framebuffer->pixels[i * 4 + 1] = 206;
      framebuffer->pixels[i * 4 + 2] = 250;
      framebuffer->pixels[i * 4 + 3] = 255;
      i++;
      restock = c;
      c = stock;
    }
}

void	draw_floor(t_my_framebuffer *framebuffer)
{
  int	i;
  int	c;

  c = 0;
  i = framebuffer->width * framebuffer->height / 2;
  while (i < (framebuffer->width * framebuffer->height))
    {
      if (i % (framebuffer->width * 4) == 0)
	c++;
      framebuffer->pixels[i * 4] = 0 + c;
      framebuffer->pixels[i * 4 + 1] = 0 + c;
      framebuffer->pixels[i * 4 + 2] = 0 + c;
      framebuffer->pixels[i * 4 + 3] = 255;
      i++;
    }
}
