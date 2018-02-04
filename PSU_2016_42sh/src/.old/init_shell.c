/*
** init_shell.c for 42sh in /home/monty/Documents/Rendu/minishell/PSU_2016_42sh/src/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Wed May 31 11:50:39 2017 Monty Criel
** Last update Wed May 31 17:08:30 2017 Monty Criel
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

int	count_paths(char *str)
{
  int	count;
  int	i;

  count = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ':')
	count = count + 1;
      i = i + 1;
    }
  return (count);
}

void	*add_tab_path(char *str, int *idx)
{
  int	count;
  char	*line;
  int	i;

  while (str[*idx] == ':' && str[*idx] != '\0')
    *idx = *idx + 1;
  i = *idx;
  while (str[i] != ' ' && str[i] != '\0')
    i = i + 1;
  count = i - *idx;
  line = malloc(sizeof(char) * (count + 1));
  if (line == NULL)
    return (NULL);
  i = 0;
  while (str[*idx] != ':' && str[*idx] != '\0')
    {
      line[i] = str[*idx];
      i = i + 1;
      *idx = *idx + 1;
    }
  line[i] = '/';
  line[i + 1] = '\0';
  return (line);
}

char	**separate_paths(char *str)
{
  int	i;
  int	x;
  int	count;
  char	**tab;

  i = 0;
  x = 0;
  count  = count_paths(str);
  tab = malloc(sizeof(char *) * (count + 2));
  if (tab == NULL)
    exit(84);
  while (x != count)
    {
      tab[x] = add_tab_path(str, &i);
      if (tab[x] == NULL)
	exit(84);
      x = x + 1;
    }
  x = x + 1;
  tab[x] = NULL;
  return (tab);
}

int	init_shell(t_shell *shell, char **env)
{
  char	*paths;

  shell->env = env;
  paths = get_env_var(env, "PATH");
  shell->bin_paths = separate_paths(paths);
  free(paths);
  return (0);
}
