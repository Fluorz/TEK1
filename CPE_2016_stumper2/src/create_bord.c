/*
** create_bord.c for create_bord.c in /home/lecherbonnier/Projet/CPE_2016_stumper2/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Apr 25 09:54:07 2017 Leo Lecherbonnier
** Last update Tue Apr 25 09:24:46 2017 Nicolas Ferlet
*/

#include "my.h"

char	**create_bord(t_param param)
{
  int	i;
  char **tab;

  i = 0;
  tab = NULL;
  if ((tab = malloc(sizeof(char *) * (param.height + 1))) == NULL)
    return (NULL);
  while (i != param.height)
    {
      if ((tab[i] = malloc(sizeof(char) * (param.width + 1))) == NULL)
	return (NULL);
      tab[i][param.width] = '\0';
      i++;
    }
  tab[i] = NULL;
  return (tab);
}

void	put_in_tab(char **tab, int turn, t_param param, int nb)
{
  int	j;
  int	i;
  char	c;

  j = 0;
  i = nb - 1;
  if (turn == 0)
    c = param.avatar1;
  else
    c = param.avatar2;
  while (j != param.height && tab[j][i] == ' ')
    j++;
  tab[j - 1][i] = c;
}

char	**put_space(char **tab, t_param param)
{
 int	i;
 int	j;

 i = 0;
 j = 0;
 while (i != param.height)
    {
      j = 0;
      while (j != param.width)
	{
	  tab[i][j] = ' ';
	  j++;
	}
      i++;
    }
  return (tab);
}
