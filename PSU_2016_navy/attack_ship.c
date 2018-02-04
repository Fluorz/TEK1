/*
** attack_ship.c for navy in /home/monty/Documents/Rendu/navy/PSU_2016_navy/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 23:01:10 2017 Monty Criel
** Last update Thu Feb 16 18:17:58 2017 Leo Lecherbonnier
*/

#include <stdlib.h>
#include "navy.h"

char	*attack_status(char *target, char **map)
{
  int	x;
  int	y;

  x = (target[1] - 48) + 1;
  y = (target[0] - 64) * 2;
  if (('0' <= map[x][y]) && (map[x][y] <= '5'))
    {
      map[x][y] = 'x';
      my_printf("%s: %s\n\n", target, "hit");
      return ("hit");
    }
  else
    {
      if ((map[x][y] == 'x') || (map[x][y] == 'o'))
	return ("missed");
      map[x][y] = 'o';
      my_printf("%s: %s\n\n", target, "missed");
      return ("missed");
    }
}

int	check_coord(char *target)
{
  if (my_strlen(target) > 2)
      return (84);
  if (('A' <= target[0] && target[0] <= 'Z') &&
      ('1' <= target[1] && target[1] <= '8'))
    return (0);
  else
    return (84);
  return (0);
}

void	hit_or_miss(t_player *player, t_pos pos, char *str, char option)
{
  if (option == 'H')
    {
      player->enemy[pos.x][pos.y] = 'x';
      player->ships = player->ships - 1;
      my_printf("%s: hit\n\n", str);
    }
  else
    {
      my_printf("%s: missed\n\n", str);
      if (player->enemy[pos.x][pos.y] == 'x')
	return;
      player->enemy[pos.x][pos.y] = 'o';
    }
}

void		shoot(t_player *player, char *target, char option)
{
  t_pos	pos;

  if (check_coord(target) != 0)
    my_putstr("wrong position");
  pos.x = (target[1] - 48) + 1;
  pos.y = (target[0] - 64) * 2;
  hit_or_miss(player, pos, target, option);
}
