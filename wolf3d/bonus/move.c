/*
** move.c for move.c in /home/lecherbonnier/wolf3d/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Jan  6 17:34:41 2017 Leo Lecherbonnier
** Last update Wed Mar  8 10:26:31 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

t_player	move(t_player player, t_my_framebuffer	*framebuffer)
{
  float	k;

  if (sfKeyboard_isKeyPressed(sfKeyZ) &&
      (k = (double)raycast(player.pos, player.direction,
	    player.map, player.mapSize) > 0.3))
    player.pos = move_forward(player.pos, player.direction, 0.2);
  if (sfKeyboard_isKeyPressed(sfKeyS) &&
      (k = (double)raycast(player.pos, player.direction - 180,
	    player.map, player.mapSize) > 0.3))
    player.pos = move_forward(player.pos, player.direction, - 0.2);
  if (sfKeyboard_isKeyPressed(sfKeyQ))
    player.direction -= 5;
  if (sfKeyboard_isKeyPressed(sfKeyD))
    player.direction += 5;
  if (sfKeyboard_isKeyPressed(sfKeyEscape))
    exit(0);
  if (sfKeyboard_isKeyPressed(sfKeyT))
    {
      player.nice.r -= 10;
      player.nice.g -= 10;
      player.nice.b += 10;
      player.nice.a = 255;
    }
  return (player);
}
