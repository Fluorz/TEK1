/*
** player.c for player.c in /home/lecherbonnier/Projet/CPE_2016_matchstick/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Feb 13 15:50:53 2017 Leo Lecherbonnier
** Last update Thu Feb 23 19:44:26 2017 Leo Lecherbonnier
*/

#include "matchstick.h"

int	player(char **map, int len, int len_max)
{
  t_player *player;

  player = xmalloc(sizeof(player));
  player->map = xmalloc(sizeof(char) * len);
  player->map = map;
  player->len = len;
  player->len_max = len_max;
  while (1)
    {
      my_printf("Your turn:\n");
      if ((player = first_action(player)) == NULL)
	return (-1);
      if (check_end_game(map, len) == 0)
	{
	  my_printf("You lost, too bad...\n");
	  return (2);
	}
      if ((player = second_action(player)) == NULL)
	return (1);
    }
}
