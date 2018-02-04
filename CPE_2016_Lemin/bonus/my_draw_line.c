/*
** my_draw_line.c for lemin in /home/monty/Documents/Rendu/lemin/CPE_2016_Lemin/bonus/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sun Apr 30 16:06:26 2017 Monty Criel
** Last update Sun Apr 30 18:23:40 2017 Monty Criel
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "lemin.h"

void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  float	run;
  float	rise;
  float	steps;
  float	tmpX;
  float 	tmpY;
  int 		i;

  tmpX = from.x;
  tmpY = from.y;
  if (abs((float)to.x - (float)from.x) >= abs((float)to.y - (float)from.y))
    steps = abs((float)to.x - (float)from.x);
  else
    steps = abs((float)to.y - (float)from.y);
  run = ((float)to.x - (float)from.x) / steps;
  rise = ((float)to.y - (float)from.y) / steps;
  i = 0;
  while (i <= steps)
    {
      my_put_pixel(framebuffer, tmpX, tmpY, color);
      tmpX = tmpX + run;
      tmpY = tmpY + rise;
      i = i + 1;
    }
}
