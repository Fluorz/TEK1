/*
** minimap.c for minimap.c in /home/lecherbonnier/wolf3d/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Jan  9 19:18:20 2017 Leo Lecherbonnier
** Last update Wed Mar  8 10:26:34 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

void	minimap(t_player player, t_my_framebuffer *framebuffer)
{
  int	i;
  int	k;
  int	j;
  int	y;

  i = 0;
  k = 0;
  cross(player, framebuffer);
  while (k < player.lines)
    {
      i = 0;
      while (i < player.colums)
	{
    if (player.map[k][i] == 0)
	    draw_blocks(player, framebuffer, i * 10 + 10, k * 10 + 10);
    if (player.map[k][i] == 1)
	    draw_blocks1(player, framebuffer, i * 10 + 10, k * 10 + 10);
    i++;
	}
      k++;
    }
  j = player.pos.x;
  y = player.pos.y;
  draw_blocks2(player, framebuffer, j * 10 + 10, y * 10 + 10);
}

void	draw_blocks(t_player player, t_my_framebuffer *framebuffer,
		    int x, int y)
{
  int	i;
  int	j;

  i = x;
  j = y;
  while (i < x + 10)
    {
      player.from.x = i;
      player.from.y = j;
      player.to.x = i;
      player.to.y = j + 10;
      my_draw_line(framebuffer, player.from, player.to, sfBlack);
      i++;
    }
}

void	draw_blocks1(t_player player, t_my_framebuffer *framebuffer,
		     int x, int y)
{
  int	i;
  int	j;

  i = x;
  j = y;
  while (i < x + 10)
    {
      player.from.x = i;
      player.from.y = j;
      player.to.y = j + 10;
      player.to.x = i;
      my_draw_line(framebuffer, player.from, player.to, sfWhite);
      i++;
    }
}

void	draw_blocks2(t_player player, t_my_framebuffer *framebuffer,
		     int x, int y)
{
  int	i;
  int	j;

  i = x;
  j = y;
  while (i < x + 10)
    {
      player.from.x = i;
      player.from.y = j;
      player.to.x = i;
      player.to.y = j + 10;
      my_draw_line(framebuffer, player.from, player.to, sfRed);
      i++;
    }
}
