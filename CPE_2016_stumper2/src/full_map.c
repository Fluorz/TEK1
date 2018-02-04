/*
** full_map.c for full_map.c in /home/lecherbonnier/Projet/CPE_2016_stumper2/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Apr 25 11:21:30 2017 Leo Lecherbonnier
** Last update Tue Apr 25 09:27:57 2017 Nicolas Ferlet
*/

#include "my.h"

int	full_map(char **tab)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (tab[j])
    {
      i = 0;
      while (tab[j][i] != '\0')
	{
	  if (tab[j][i] == ' ')
	    return (0);
	  i++;
	}
      j++;
    }
  return (1);
}
