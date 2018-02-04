/*
** wordtab_funcs.c for minishell1 in /home/monty/Documents/Rendu/minishell/PSU_2016_minishell1/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Sun Jan 22 18:37:29 2017 Monty Criel
** Last update Sun Apr  2 20:30:19 2017 Monty Criel
*/

#include <stdlib.h>
#include "my.h"

void	print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_printf("%s\n", tab[i]);
      i = i + 1;
    }
}

char	**realloc_tab(char **tab, int size)
{
  int	i;
  char	**new_tab;

  i = 0;
  while (tab[i] != NULL)
    i = i + 1;
  new_tab = malloc(sizeof(char *) * (i + 1 + size));
  if (new_tab == NULL)
    return (NULL);
  new_tab[i + 1] = NULL;
  return (new_tab);
}

char	**tab_append_head(char **tab, char *str)
{
  int	i;
  char	**new_tab;

  i = 1;
  new_tab[0] = my_strdup(str);
  new_tab = realloc_tab(tab, 1);
  while (tab[i] != NULL)
    {
      new_tab[i] = my_strdup(tab[i]);
      i = i + 1;
    }
  new_tab[i] = NULL;
  return (new_tab);
}

char	**tab_append_tail(char **tab, char *str)
{
  int	i;
  char	**new_tab;

  if (tab == NULL)
    {
      if ((new_tab = malloc(sizeof(char *) * 2)) == NULL)
	exit(84);
      new_tab[0] = my_strdup(str);
      new_tab[1] = NULL;
      return (new_tab);
    }
  i = 0;
  new_tab = realloc_tab(tab, 1);
  if (new_tab == NULL)
    return (NULL);
  while (tab[i] != NULL)
    {
      new_tab[i] = my_strdup(tab[i]);
      i = i + 1;
    }
  new_tab[i] = my_strdup(str);
  i = i + 1;
  new_tab[i] = NULL;
  return (new_tab);
}

char	**tab_pop(char **tab, int pos)
{
  int	i;
  int	x;
  char	**new_tab;

  i = 0;
  x = 0;
  new_tab = realloc_tab(tab, -1);
  while (tab[i] != NULL)
    {
      new_tab[x] = my_strdup(tab[i]);
      i = i + 1;
      x = x + 1;
      if (i == pos)
	i = i + 1;
    }
  new_tab[x] = NULL;
  return (new_tab);
}
