/*
** compting_o.c for compting_o in /home/lecherbonnier/PSU_2016_my_sokoban/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Dec 20 19:15:07 2016 Leo Lecherbonnier
** Last update Tue Dec 20 18:29:28 2016 Leo Lecherbonnier
*/

#include "sokoban.h"

int	compting_o(char **tab, int ligne)
{
  int	i;
  int	j;
  int	o;

  i = 0;
  j = 0;
  o = 0;
  while (j < ligne)
    {
      i = 0;
      while (tab[j][i] != '\0')
	{
	  if (tab[j][i] == 'O')
	    o++;
	  i++;
	}
      j++;
    }
  return (o);
}
