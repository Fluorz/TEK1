/*
** cross.c for cross.c in /home/lecherbonnier/wolf3d/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Jan 10 14:37:02 2017 Leo Lecherbonnier
** Last update Wed Mar  8 10:25:44 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

void	cross(t_player player, t_my_framebuffer	*framebuffer)
{
  sfVector2i		A;
  sfVector2i		B;

  A.x = 1280 / 2;
  A.y = 720 / 2;
  B.x = 1280 / 2 + 20;
  B.y = 720 / 2;
  my_draw_line(framebuffer, A, B, sfBlack);
  B.x = 1280 / 2 + 10;
  B.y = 720 / 2 - 10;
  A.x = 1280 / 2 + 10;
  A.y = 720 / 2 + 10;
  my_draw_line(framebuffer, B, A, sfBlack);
}
