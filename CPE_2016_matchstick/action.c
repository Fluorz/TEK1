/*
** action.c for action.c in /home/lecherbonnier/Projet/CPE_2016_matchstick/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Feb 16 14:32:02 2017 Leo Lecherbonnier
** Last update Thu Feb 23 19:48:08 2017 Leo Lecherbonnier
*/

#include "matchstick.h"

t_player *second_action(t_player *player)
{
  my_putstr("\n");
  play_ia(player->map, player->len, player->len_max, player->len_max);
  if (check_end_game(player->map, player->len) == 0)
{
      my_printf("I lost... snif... but I'll get you next time!!\n");
      return (NULL);
    }
  my_putchar('\n');
  return (player);
}

t_player *first_action(t_player *player)
{
  my_printf("Line: ");
  if ((player->line = get_next_line(0)) == NULL)
    return (end_return_null());
  if (handler_lines(*player) == 0)
{
      my_printf("Matches: ");
      if ((player->number = get_next_line(0)) == NULL)
	return (end_return_null());
      if ((handler_matches(*player) == 0))
	*player = handler_map(*player);
      else
	{
	  if ((player = first_action(player)) == NULL)
	    return (NULL);
	}
    }
  else
    {
      if ((player = first_action(player)) == NULL)
	return (NULL);
    }
  return (player);
}

void	*end_return_null()
{
  my_putchar('\n');
  return (NULL);
}
