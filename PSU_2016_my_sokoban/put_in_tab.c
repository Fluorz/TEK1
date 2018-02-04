/*
** put_in_tab.c for put_in_tab.c in /home/lecherbonnier/PSU_2016_my_sokoban/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Dec 12 18:14:08 2016 Leo Lecherbonnier
** Last update Tue Dec 20 19:18:54 2016 Leo Lecherbonnier
*/

#include "sokoban.h"

void put_in_tab(char *str, int *ligne)
{
  char	**tab;
  int	i;
  int	j;
  int	m;
  int	tmp;

  i = -1;
  j = 0;
  m = 0;
  tab = malloc(sizeof(char) * my_strlen(str) + 10);
  while (str[++i] != '\0')
    {
      tab[j] = malloc(sizeof(char) * (my_strlen(str) / *ligne) + 10);
      while (str[i] != '\n')
	{
	  tab[j][m] = str[i];
	  m++;
	  i++;
	}
      tab[j][m] = '\0';
      j++;
      m = 0;
    }
  tmp = *ligne;
  print_tab(tab, tmp, 0, 0);
}

int	print_tab(char **str, int ligne, int x, int y)
{
  int	j;
  int i;

  initscr();
  curs_set(0);
  while (compting_o(str, ligne) != 0)
    {
      j = 0;
      refresh();
      while (j < ligne)
	{
	  mvprintw(LINES / 2 - (ligne / 2) + j + 1, (COLS / 2) -
		   (my_strlen(str[0]) / 2), str[j]);
	  j++;
	}
      movements(str, ligne, &x, &y);
      clear();
    }
  free(str);
  endwin();
  return (0);
}
