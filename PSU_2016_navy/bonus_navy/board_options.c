/*
** board_options.c for navy in /home/monty/Documents/Rendu/navy/PSU_2016_navy/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Fri Feb  3 00:19:54 2017 Monty Criel
** Last update Mon Feb 13 11:27:16 2017 Leo Lecherbonnier
*/

#include <stdlib.h>
#include "navy.h"

int	check_file(char *str)
{
  int	x;
  int	i;

  x = 0;
  while (str[x] != '\0')
    {
      i = 0;
      while (str[x] != '\n')
	{
	  i = i + 1;
	  x = x + 1;
	}
      if (i != 7)
	return (84);
      x = x + 1;
    }
  return (0);
}

char	**alloc_tab(char *str)
{
  int	x = 0;
  int	i;
  int	size = 0;
  char	**tab;

  while (str[x] != '\0')
    {
      if (str[x] == '\n')
	size = size + 1;
      x = x + 1;
    }
  if ((tab = malloc(sizeof(char *) * (size + 1))) == 0)
    return (NULL);
  i = 0;
  while (str[i] != '\n')
    i = i + 1;
  x = 0;
  while (x != size)
    {
      if ((tab[x] = malloc(sizeof(char) * (i + 1))) == 0)
	return (NULL);
      x = x + 1;
    }
  tab[x] = NULL;
  return (tab);
}

char	**get_boat_coord(char *str)
{
  char	**tab;
  int	x;
  int	y;
  int	i;

  if (check_file(str) != 0)
    return (NULL);
  tab = alloc_tab(str);
  x = 0;
  i = 0;
  while (tab[x] != NULL)
    {
      y = 0;
      while (str[i] != '\n')
	{
	  tab[x][y] = str[i];
	  y = y + 1;
	  i = i + 1;
	}
      tab[x][y] = '\0';
      x = x + 1;
      i = i + 1;
    }
  return (tab);
}

void	print_board(char **map)
{
  int	x;
  int	y;

  x = 0;
  while (map[x] != NULL)
    {
      y = 0;
      while (map[x][y] != '\0')
	{
	  my_printf("%c", map[x][y]);
	  y = y + 1;
	}
      x = x + 1;
    }
}

void	fill_row1(char **map)
{
  int	i;
  int	x;

  i = 2;
  x = 0;
  while (i != 17)
    {
      if (i % 2 == 0)
	{
	  map[0][i] = 65 + x;
	  x = x + 1;
	}
      else
     	map[0][i] = ' ';
      i = i + 1;
    }
  map[0][i] = '\n';
  i = i + 1;
  map[0][i] = '\0';
}
