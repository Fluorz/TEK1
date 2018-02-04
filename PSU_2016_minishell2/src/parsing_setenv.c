/*
** parsing_setenv.c for parsing_setenv.c in /home/lecherbonnier/Projet/PSU_2016_minishell2/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Apr 11 09:24:13 2017 Leo Lecherbonnier
** Last update Tue Apr 11 09:24:54 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

char	**delete_line(int line, char **env)
{
  int	i = 0;
  int	j = 0;
  int	len = -1;
  char **new_env = NULL;

  while (env[++len] != NULL);
  if ((new_env = malloc(sizeof(char *) * len + 1)) == NULL)
    exit(my_putstr("Problem with memory champs"));
  while (i != len)
    {
      if (i != line)
	{
    new_env[j] = my_strdup(env[i]);
    j++;
	}
      i++;
    }
  new_env[len] = NULL;
  return (new_env);
}

int	find_line_before_delete(char *element, char **env)
{
  int	j = 0;

  while (env[j] != NULL)
    {
      if (env[j][0] == element[0] && env[j][1] == element[1] &&
    	 env[j][2] == element[2])
	return (j);
      j++;
    }
  return (-1);
}

char 	**struct_op(char **env, char *name, char *value)
{
  int	i = 0;
  int	len = -1;
  char **new_env = NULL;

  while (env[++len] != NULL);
  if ((new_env = malloc(sizeof(char *) * len + 5)) == NULL)
    exit(my_putstr("Problem with memory champs"));
  while (i != len)
    {
      new_env[i] = my_strdup(env[i]);
      i++;
    }
  new_env[len] = my_strdup(name);
  new_env[len] = my_strcat(new_env[len], "=");
  if (value != NULL)
    new_env[len] = my_strcat(new_env[len], value);
  new_env[len + 1] = NULL;
  return (new_env);
}
