/*
** wordtab_funcs.c for minishell1 in /home/monty/Documents/Rendu/minishell/PSU_2016_minishell1/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Sun Jan 22 18:37:29 2017 Monty Criel
** Last update Sun Apr 30 11:11:39 2017 Monty Criel
*/

#include <stdlib.h>
#include "my.h"

void	print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    my_printf("%s\n", tab[i++]);
}

char	**realloc_tab(char **tab, int size)
{
  int	i;
  char	**new_tab;

  i = 0;
  while (tab[i] != NULL)
    i = i + 1;
  new_tab = malloc(sizeof(char *) * (i + 1 + size));
  return (new_tab);
}

char	**tab_append_tail(char **tab, char *str)
{
  int	i;
  char	**new_tab;

  i = 0;
  if (str == NULL)
    return (tab);
  new_tab = realloc_tab(tab, 1);
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
