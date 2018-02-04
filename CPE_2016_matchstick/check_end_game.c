/*
** check_end_game.c for check_end_game.c in /home/lecherbonnier/Projet/CPE_2016_matchstick/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Feb 16 14:00:46 2017 Leo Lecherbonnier
** Last update Fri Feb 24 09:59:40 2017 Leo Lecherbonnier
*/

#include "matchstick.h"

int	check_end_game(char **map, int len)
{
  int	i = 0;
  int	j = 0;

  while (j != len + 1)
    {
      if (map[j][i] == '|')
	return (1);
      else if (map[j][i] == '\n')
	{
	  j++;
	  i = 0;
	}
      else
	i++;
    }
  return (0);
}

int	total_pipe(char **map, int len)
{
  int	index = 0;
  int	i = 0;
  int	j = 0;

  while (j != len + 1)
    {
      if (map[j][i] == '|')
	index++;
     if (map[j][i] == '\n')
	{
	  j++;
	  i = 0;
	}
      else
	i++;
    }
  return (index);
}
