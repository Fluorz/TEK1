/*
** flag.c for flag.c in /home/lecherbonnier/PSU_2016_my_sokoban/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Dec 12 21:43:31 2016 Leo Lecherbonnier
** Last update Tue Dec 20 17:41:20 2016 Leo Lecherbonnier
*/

#include "sokoban.h"

void	flag_right(char **tab, int *x, int *y, int ligne)
{
  int	tmpx;
  int	tmpy;

  tmpx = *x;
  tmpy = *y;
  if (colision(tab, tmpx + 1, tmpy, ligne) == 0)
    {
      tab[*y][*x] = ' ';
      tab[*y][++(*x)] = 'p';
    }
  else if (colision(tab, tmpx + 1, tmpy, ligne) == 2)
    {
      if (tab[tmpy][tmpx + 2] != '#' && tab[tmpy][tmpx + 2] != 'X')
	{
	  tab[*y][*x] = ' ';
	  tab[(*y)][(*x) + 1] = 'P';
	  tab[(*y)][(*x) + 2] = 'X';
	}
    }
}

void	flag_left(char **tab, int *x, int *y, int ligne)
{
  int	tmpx;
  int	tmpy;

  tmpx = *x;
  tmpy = *y;
  if (colision(tab, tmpx - 1, tmpy, ligne) == 0)
    {
      tab[*y][*x] = ' ';
      tab[*y][--(*x)] = 'p';
    }
  else if (colision(tab, tmpx - 1, tmpy, ligne) == 2)
    {
      if (tab[tmpy][tmpx - 2] != '#' && tab[tmpy][tmpx - 2] != 'X')
	{
	  tab[*y][*x] = ' ';
	  tab[(*y)][(*x) - 1] = 'P';
	  tab[(*y)][(*x) - 2] = 'X';
	}
    }
}

void	flag_down(char **tab, int *x, int *y, int ligne)
{
  int	tmpx;
  int	tmpy;

  tmpx = *x;
  tmpy = *y;
  if (colision(tab, tmpx, tmpy + 1, ligne) == 0)
    {
      tab[*y][*x] = ' ';
      tab[++(*y)][*x] = 'p';
    }
  else if (colision(tab, tmpx, tmpy + 1, ligne) == 2)
    {
      if (tab[tmpy + 2][tmpx] != '#' && tab[tmpy + 2][tmpx] != 'X')
	{
	  tab[*y][*x] = ' ';
	  tab[(*y) + 1][*x] = 'P';
	  tab[(*y) + 2][*x] = 'X';
	}
    }
}

void	flag_up(char **tab, int *x, int *y, int ligne)
{
  int	tmpx;
  int	tmpy;

  tmpx = *x;
  tmpy = *y;
  if (colision(tab, tmpx, tmpy - 1, ligne) == 0)
    {
      tab[(*y)][*x] = ' ';
      tab[--(*y)][*x] = 'p';
    }
  else if (colision(tab, tmpx, tmpy - 1, ligne) == 2)
    {
      if (tab[tmpy - 2][tmpx] != '#' && tab[tmpy - 2][tmpx] != 'X')
	{
	  tab[(*y)][(*x)] = ' ';
	  tab[(*y) - 1][*x] = 'P';
	  tab[(*y) - 2][*x] = 'X';
	}
    }
}
