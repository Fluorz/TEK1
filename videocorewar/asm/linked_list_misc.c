/*
** linked_list_misc.c for corewar in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Wed Mar 29 14:32:41 2017 Monty Criel
** Last update Sun Apr  2 21:45:29 2017 Monty Criel
*/

#include <unistd.h>
#include <stdlib.h>
#include "linked_list.h"
#include "my.h"
#include "op.h"

char	*epure_str(char *str)
{
  char	*new;
  int	tmp;
  int	i;
  int	x;

  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i += 1;
  tmp = i;
  while (str[i] != '\0')
    i += 1;
  new = malloc(sizeof(char) * (i - tmp + 1));
  if (new == NULL)
    exit(84);
  i = 0;
  while (str[tmp] != '\0')
    {
      new[i] = str[tmp];
      tmp += 1;
      i += 1;
    }
  new[i] = '\0';
  return (new);
}

char	**second_epure(char **tab)
{
  int	i;
  char	**new;

  while (tab[i] != NULL)
    i += 1;
  if ((new = malloc(sizeof(char *) * (i + 1))) == NULL)
    exit(84);
  i = 0;
  while (tab[i] != NULL)
    {
      new[i] = epure_str(tab[i]);
      i += 1;
    }
  return (new);
}

char	**epure_wordtab(char **tab)
{
  int	i;
  int	x;
  int	tmp;
  char	**e_tab;

  i = 0;
  tmp = 0;
  while (tab[i] != NULL)
    {
      if (my_strlen(tab[i]) > 0)
	tmp += 1;
      i += 1;
    }
  e_tab = malloc(sizeof(char *) * (tmp + 1));
  i = x = 0;
  while (tab[i] != NULL)
    {
      if (my_strlen(tab[i]) > 0)
	{
	  e_tab[x] = my_strdup(tab[i]);
	  x += 1;
	}
      i +=1;
    }
  return (e_tab);
}

int	is_label(char *str)
{
  int	i;
  int	tmp;

  i = 0;
  if (str == NULL)
    return (84);
  if (str[0] == ' ' || str[0] == '\t')
    return (84);
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == '\t')
	return (84);
      if (str[i] == LABEL_CHAR)
	return (0);
      i += 1;
    }
  return (84);
}
