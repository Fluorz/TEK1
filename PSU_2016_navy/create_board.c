/*
** create_board.c for navy in /home/monty/Documents/Rendu/navy/PSU_2016_navy/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 16:39:33 2017 Monty Criel
** Last update Mon Feb 13 11:28:19 2017 Leo Lecherbonnier
*/

#include "navy.h"

char	**alloc_map()
{
  char	**map;
  int	x;

  x = 0;
  if ((map = malloc(sizeof(char *) * 11)) == 0)
    return (NULL);
  while (x != 10)
    {
      if ((map[x] = malloc(sizeof(char) * 19)) == 0)
	return (NULL);
      x = x + 1;
    }
  map[x] = NULL;
  return (map);
}

void	fill_board_top(char **map)
{
  int	i;

  map[0][0] = ' ';
  map[0][1] = '|';
  i = 0;
  fill_row1(map);
  while (i != 17)
    {
      if (i == 1)
	map[1][i] = '+';
      else
	map[1][i] = '-';
      i = i + 1;
    }
  map[1][i] = '\n';
  i = i + 1;
  map[1][i] = '\0';
}

void	board_char(char **map, int *x, int *y, int *i)
{
  if (*y == 0)
    {
      map[*x][*y] = 49 + *i;
      *i = *i + 1;
      return;
    }
  if (*y == 1)
    map[*x][*y] = '|';
  else if (*y % 2 == 0)
    map[*x][*y] = '.';
  else
    map[*x][*y] = ' ';
}

void	fill_map(char **map)
{
  int	x;
  int	y;
  int	i;

  x = 2;
  i = 0;
  while (x != 10)
    {
      y = 0;
      while (y != 17)
	{
	  board_char(map, &x, &y, &i);
	  y = y + 1;
	}
      map[x][y] = '\n';
      y = y + 1;
      map[x][y] = '\0';
      x = x + 1;
    }
  map[x] = NULL;
}

char	**create_board(void)
{
  char	**map;

  map = alloc_map();
  fill_board_top(map);
  fill_map(map);
  return (map);
}
