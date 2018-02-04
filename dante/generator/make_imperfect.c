/*
** make_imperfect.c for make_imperfect.c in /home/lecherbonnier/Projet/dante/generator/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 20:09:20 2017 Leo Lecherbonnier
** Last update Jul May 13 13:37:51 2017
*/

#include "generator.h"

int	my_strcmp(char *str, char *dest)
{
  int	i = 0;

  while (str[i] != '\0' && dest[i] != '\0')
    {
      if (str[i] != dest[i])
	return (1);
      i++;
    }
  return (0);
}

int	how_many_break(char **map)
{
  int	i = 0;
  int	j = 0;
  int	result = 0;

  while (map[i])
    {
      j = 0;
      while (map[i][j] != '\0')
	{
	  if (map[i][j] == 'X')
	    result++;
	  j++;
	}
      i++;
    }
  return (result / 4);
}

int rand_a_b(int a, int b)
{
  if (b == 1)
    b++;
  return (rand() % (b - a) + a);
}

int	get_tab_len(char **tab)
{
  int	i = 0;

  while (tab[i])
    i++;
  return (i);
}

void	make_imperfect(t_args *args)
{
  int	many_break;
  int	have_break = 0;
  int	x = 0;
  int	y = 0;
  int	line_len;
  int	tab_len;

  many_break = how_many_break(args->map);
  line_len = my_strlen(args->map[0]);
  tab_len = get_tab_len(args->map);
  while (have_break != many_break)
    {
      x = rand_a_b(0, line_len);
      y = rand_a_b(0, tab_len);
      if (args->map[y][x] == 'X')
	{
	  args->map[y][x] = '*';
	  have_break++;
	}
    }
}
