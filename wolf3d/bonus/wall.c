/*
** wall.c for wall.c in /home/lecherbonnier/wolf3d/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun Jan  8 16:51:13 2017 Leo Lecherbonnier
** Last update Wed Mar  8 10:26:26 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

void	wall(t_player *player, t_my_framebuffer	*framebuffer)
{
  int	column;
  float	k;
  double	projection;
  float dir;

  column = 0;
  dir = player->direction;
  dir = dir - 30;
  while (column < framebuffer->width)
    {
      k = raycast(player->pos, dir , player->map, player->mapSize);
      player->from.x = column;
      player->to.x = column;
      projection = framebuffer->height / (double)k;
      player->from.y =
	  (int)((double)framebuffer->height / 2) - ((double)projection / 2);
      player->to.y =
	  (int)((double)framebuffer->height / 2) + ((double)projection / 2);
      player->nice.g = 230 - ((int)k * 10);
      my_draw_line(framebuffer, player->from, player->to, player->nice);
      dir =  dir + (60 / (double)framebuffer->width);
      column++;
    }
}
