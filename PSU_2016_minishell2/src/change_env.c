/*
** change_env.c for change_env.c in /home/lecherbonnier/Projet/PSU_2016_minishell2/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Mar 20 15:53:21 2017 Leo Lecherbonnier
** Last update Mon Mar 20 16:31:13 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

char	**change_env(char **env, char *element, char *to_put)
{
  char	*str;
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

  new_line = malloc(sizeof(char) * my_strlen(to_put) * 10);
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
  env[j] = malloc(sizeof(char) * my_strlen(to_put));
  env[j] = new_line;
  return (env);
}
