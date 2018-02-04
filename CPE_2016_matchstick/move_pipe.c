/*
** move_pipe.c for move_pipe.c in /home/lecherbonnier/Projet/CPE_2016_matchstick/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Feb 16 13:59:41 2017 Leo Lecherbonnier
** Last update Thu Feb 16 14:00:09 2017 Leo Lecherbonnier
*/

#include "matchstick.h"

char	**move_pipe(int line, int number, char **map)
{
  int	i = 0;
  int	j = 0;
  int	number_delete = number;
  int	line_delete = line;

  while (map[0][j] != '\n')
    j++;
  j--;
  while (i != number_delete && j != 0)
    {
      if (map[line_delete][j] == ' ')
	j--;
      else if (map[line_delete][j] == '|')
	{
	  map[line_delete][j] = ' ';
	  i++;
	  j--;
	}
      else if (map[line_delete][j] == '*')
	j--;
    }
  return (map);
}
