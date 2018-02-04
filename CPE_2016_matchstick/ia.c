/*
** ia.c for ia.c in /home/lecherbonnier/Projet/CPE_2016_matchstick/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Feb 16 13:58:39 2017 Leo Lecherbonnier
** Last update Fri Feb 24 10:03:24 2017 Leo Lecherbonnier
*/

#include "matchstick.h"

int	play_ia(char **map, int len, int len_max, int matches)
{
  int	line = 0;
  int	number = 0;

  if (total_pipe(map, len) > 3)
    {
      line = rand_a_b(where_are_pipe(map, len + 1), len + 1);
      number = rand_a_b(1, how_many_pipe(map, line));
    }
  else
    {
      line = rand_a_b(where_are_pipe(map, len + 1), len + 1);
      number = 1;
    }
  if (check_macthes(number, len_max, line, map) != 0)
    return (play_ia(map, len, len_max, matches));
  my_printf("AI's turn...\n");
  my_printf("AI removed %d match(es) from line %d\n", number, line);
  map = move_pipe(line, number, map);
  print_map(map, len + 2);
  return (0);
}

int rand_a_b(int a, int b)
{
  if (b == 1)
    b++;
  return (rand() % (b - a) + a);
}

int	check_macthes(int number, int matches, int line, char **map)
{
  if (number > matches)
    return (-1);
  if (number > how_many_pipe(map, line))
    return (-1);
  return (0);
}

int	how_many_pipe(char **map, int line)
{
  int	index = 0;
  int	i = 0;

  while (i != my_strlen(map[line]))
    {
      if (map[line][i] == '|')
	{
    index++;
	}
      i++;
    }
  return (index);
}

int	where_are_pipe(char **map, int len)
{
  int	i = 0;
  int	j = 0;

  while (j != len)
    {
      if (map[j][i] == '|')
	return (j);
      else if (map[j][i] == '\n')
	{
	  j++;
	  i = 0;
	}
      else
	i++;
    }
  return (j);
}
