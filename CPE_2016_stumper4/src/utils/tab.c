/*
** tab.c for tab in /home/ferlet_n/colle/CPE_2016_stumper4/src
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue May  9 08:52:12 2017 Nicolas Ferlet
** Last update Tue May  9 08:52:46 2017 Nicolas Ferlet
*/

#include "my.h"

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i = i + 1;
    }
  free(tab);
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i] != NULL)
    i = i + 1;
  return (i);
}
