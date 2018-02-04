/*
** change_env.c for change_env.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/builtins/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sat Jun  3 18:10:32 2017 Leo Lecherbonnier
** Last update Jul Jun 3 18:29:17 2017
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	**leo_change_env(char **env, char *element, char *to_put)
{
  int	j;

  j = 0;
  while (env[j] != NULL)
    {
      if (env[j][0] == element[0] && env[j][1] == element[1] &&
       env[j][2] == element[2])
  env = put_new_data(env, j, to_put);
      j++;
    }
  return (env);
}

char	**put_new_data(char **env, int j, char *to_put)
{
  char	*new_line;
  int	i = 0;
  int	k = 0;

  new_line = malloc(sizeof(char) * strlen(to_put) * 10);
  new_line = env[j];
  while (new_line[i] != '=')
    i++;
  i++;
  while (to_put[k] != '\0')
    {
      new_line[i] = to_put[k];
      i++;
      k++;
    }
  new_line[i] = '\0';
  env[j] = malloc(sizeof(char) * strlen(to_put));
  env[j] = new_line;
  return (env);
}

char	*leo_getenv(char **env, char *element)
{
  char	*str;
  int	j;

  j = 0;
  while (env[j] != NULL)
    {
      if (env[j][0] == element[0] && env[j][1] == element[1] &&
    	 env[j][2] == element[2])
	{
	  str = cut_path_fromenv(env[j]);
	  return (str);
	}
      j++;
    }
  return (NULL);
}

char	*cut_path_fromenv(char *env)
{
  char	*str;
  int	i;
  int	k;

  i = 0;
  k = 0;
  if ((str = malloc(sizeof(char) * strlen(env) + 1)) == NULL)
    return (0);
  while (env[i] != '=')
    i++;
  i++;
  while (env[i] != '\0')
    {
      str[k] = env[i];
      i++;
      k++;
    }
  str[k] = '\0';
  return (str);
}
