/*
** my_getenv.c for get_env.c in /root/PSU_2016_minishell1/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Jan 16 14:42:29 2017 Leo Lecherbonnier
** Last update Fri Jan 20 17:00:58 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

char	*my_getenv(char **env, char *element)
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
}

char	*cut_path_fromenv(char *env)
{
  char	*str;
  int	i;
  int	k;

  i = 0;
  k = 0;
  if ((str = malloc(sizeof(char) * my_strlen(env) + 1)) == NULL)
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
