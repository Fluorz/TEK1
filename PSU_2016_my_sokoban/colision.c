/*
** colision.c for colision.c in /home/lecherbonnier/PSU_2016_my_sokoban/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Dec 12 22:03:28 2016 Leo Lecherbonnier
** Last update Tue Dec 20 18:36:23 2016 Leo Lecherbonnier
*/

#include "sokoban.h"

int	colision(char **tab, int x, int y, int ligne)
{
  if (tab[y][x] == 'X' && x > 0 && x < my_strlen(tab[y])
      && y > 0 && y < ligne - 1)
    return (2);
  else if (tab[y][x] == '#')
    return (1);
  else if (tab[y][x] == ' ' && x >= 0 && x < my_strlen(tab[y]) &&
      y > 0 && y < ligne - 1)
    return (0);
  else
    return (84);
}
