/*
** my_put_pixel.c for lemin in /home/monty/Documents/Rendu/lemin/CPE_2016_Lemin/bonus/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sun Apr 30 16:06:09 2017 Monty Criel
** Last update Sun Apr 30 23:07:36 2017 Monty Criel
*/

#include "lemin.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x,
		     int y, sfColor color)
{
  if (framebuffer->width - 1 <= x || framebuffer->height - 1 <= y ||
      x < 0 || y < 0)
    return;
  else
    {
      framebuffer->pixels[((x + y * framebuffer->width) * 4) + 0] = color.r;
      framebuffer->pixels[((x + y * framebuffer->width) * 4) + 1] = color.g;
      framebuffer->pixels[((x + y * framebuffer->width) * 4) + 2] = color.b;
      framebuffer->pixels[((x + y * framebuffer->width) * 4) + 3] = color.a;
    }
}
