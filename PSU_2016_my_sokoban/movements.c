/*
** movements.c for movements.c in /home/lecherbonnier/PSU_2016_my_sokoban/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Dec 12 19:21:03 2016 Leo Lecherbonnier
** Last update Tue Dec 20 19:01:06 2016 Leo Lecherbonnier
*/

#include "sokoban.h"

t_flags	flag[] =
{
	{67, &flag_right},
	{68, &flag_left},
	{66, &flag_down},
	{65, &flag_up},
	{0, NULL}
};

int	check_p(char **str, int ligne, int *x, int *y)
{
  int	i;
  int	m;

  i = 0;
  m = 0;
  while (m < ligne)
    {
      while (str[m][i] != '\0')
	{
	  if (str[m][i] == 'P')
	    {
	      *x = i;
	      *y = m;
	      return (0);
	    }
	  else
	    i++;
	}
      m++;
      i = 0;
    }
}

int	movements(char **tab, int ligne, int *x, int *y)
{
  int	i;
  int	m;
  char	caractere;

  check_p(tab, ligne, x, y);
  i = getch();
  caractere = i;
  m = 0;
  if (caractere == 65 || caractere == 66 ||
      caractere == 67 || caractere == 68)
    {
      while (flag[m].arr != i)
	m++;
      flag[m].s_flags(tab, x, y, ligne);
    }
  else
    return (84);
}
