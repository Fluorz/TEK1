/*
** tetrimino_funcs.c for bootstrap tetris in /home/monty/Documents/Rendu/tetris/PSU_2016_btetris/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Mon Feb 27 12:44:14 2017 Monty Criel
** Last update Sun Mar 12 16:16:13 2017 Monty Criel
*/

#include <unistd.h>
#include "my.h"

int	is_tetrimino(char *file)
{
  int	i;
  int	idx;
  int	x;
  char	*extension;

  if (my_strlen(file) < 10)
    return (84);
  extension = my_strdup(".tetrimino");
  i = my_strlen(file) - 10;
  x = 0;
  while (x != 10)
    {
      if (file[i] != extension[x])
	return (84);
      i += 1;
      x += 1;
    }
  return (0);
}

int	max_width(char **tetrimino)
{
  int	i;
  int	x;
  int	max;
  int	tmp;

  i = 1;
  max = 0;
  tmp = 0;
  while (tetrimino[i] != NULL)
    {
      x = 0;
      tmp = 0;
      while (tetrimino[i][x] != '\0')
	{
	  x += 1;
	  if (tetrimino[i][x] == '\n')
	    tmp += 1;
	}
      if (x > max)
	max = x - tmp;
      i += 1;
    }
  return (max);
}

void	print_tetrimino_name(char *file)
{
  int	i;

  my_putstr("Tetriminos : Name ");
  i = 0;
  while (file[i] != '.')
    {
      my_putchar(file[i]);
      i += 1;
    }
  my_putstr(" : ");
}

int	print_tetrimino_size(char **tetrimino)
{
  int	height;
  int	width;
  int	h;
  int	w;
  int	i;

  height = tetrimino[0][2] - '0';
  width = tetrimino[0][0] - '0';
  h = 0;
  i = 1;
  while (tetrimino[i] != NULL)
    {
      i += 1;
      h += 1;
    }
  w = max_width(tetrimino);
  if ((height != h) || (width != w))
    {
      my_putstr("Error\n");
      return (84);
    }
  else
    my_printf("Size %d*%d : ", width, height);
  return (0);
}

int	tetrimino_color(char **tetrimino)
{
  int	nb;

  nb = tetrimino[0][4] - '0';
  if ((0 <= nb) || (nb >= 8))
    my_printf("Color %d :\n", nb);
  else
    my_putstr("Error\n");
  return (0);
}
