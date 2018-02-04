/*
** raycast.c for raycast.h in /home/lecherbonnier/wolf3d/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Jan  5 20:00:38 2017 Leo Lecherbonnier
** Last update Wed Mar  8 10:26:28 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

float raycast(sfVector2f pos, float direction, int **map,
	      sfVector2i mapSize)
{
  int		i;
  float	k;
  double	yy;
  double	xx;

  k = 0.0;
  i = 0;
  yy = pos.y;
  xx = pos.x;
  direction = M_PI * direction / 180.0;
  while (i < mapSize.x * mapSize.y * 100 && yy < mapSize.y
	 && xx < mapSize.x && xx > 0 && yy > 0)
    {
      if (map[(int)yy][(int)xx] == 1)
	{
    k = sqrt(pow(xx - (double)pos.x, 2) + pow(yy - (double)pos.y, 2)) - 0.01;
    return (k);
	}
      k = k + 0.01;
      xx = pos.x + k * cos(direction);
      yy = pos.y + k * sin(direction);
      i++;
    }
}
