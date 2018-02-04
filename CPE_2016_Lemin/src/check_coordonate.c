/*
** check_coordonate.c for check_coordonate.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun Apr 30 22:30:22 2017 Leo Lecherbonnier
** Last update Jan Apr 30 22:30:53 2017
*/

#include "open_file.h"

int	check_coordonate(char **tab)
{
  char	**take;
  int	**new_tab;
  int	i = 0;

  if ((new_tab = malloc(sizeof(int *) * i + 1)) == NULL)
    return (FAILURE);
  while (tab[i][1] != '-' && tab[i])
    {
      if ((new_tab[i] = malloc(sizeof(int) * 3)) == NULL)
	return (FAILURE);
      take = my_str_to_wordtab(tab[i], '-');
      new_tab[i][0] = my_getnbr(take[1]);
      new_tab[i][1] = my_getnbr(take[2]);
      i++;
    }
  new_tab[i] = NULL;
  return (coordonate(new_tab));
}

int	coordonate(int **new_tab)
{
  int	i = 0;
  int	j = 0;

  while (new_tab[i])
    {
      j = 0;
      while (new_tab[j])
	{
	  if (i == j)
	    j++;
	  else if (new_tab[i][0] == new_tab[j][0] &&
		   new_tab[i][1] == new_tab[j][1])
	    return (FAILURE);
	  else
	    j++;
	}
      i++;
    }
  return (SUCCESS);
}
