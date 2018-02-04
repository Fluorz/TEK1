/*
** check_access.c for check_access.c in /root/PSU_2016_minishell1/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Jan 16 14:43:14 2017 Leo Lecherbonnier
** Last update Thu Apr  6 12:22:37 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

char	**parse_before_checkaccess(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  tab = malloc(sizeof(char) * my_strlen(str) * 2);
  tab[0] = malloc(sizeof(char) * my_strlen(str));
  while (str[k] != '\0')
    {
      if (str[k] == ':')
	{
	  k++;
	  j++;
	  tab[j] = malloc(sizeof(char) * my_strlen(str));
	  i = 0;
	}
      tab[j][i] = str[k];
      i++;
      k++;
    }
  return (tab);
}

char	*check_acess(char **path, char **string, t_parse *p)
{
  int	i;
  char	*str;

  i = 0;
  while (path[i] != NULL)
    {
      str = malloc(sizeof(char) * my_strlen(path[i]) + my_strlen(string[0]));
      str = my_strcat(path[i], "/");
      str = my_strcat(str, string[0]);
      if (access(str, F_OK | X_OK) == 0)
	return (str);
      i++;
    }
  str = my_strcat(my_getenv(p->env, "PWD"), "/");
  str = my_strcat(str, string[0]);
  if ((access(str, F_OK | X_OK) == 0))
    return (str);
  if (checkInternalCommand(string, p) == 0)
    {
      write(2, string[0], my_strlen(string[0]));
      write(2, ": ", 2);
      write(2, "Command not found.\n", my_strlen("Command not found.\n"));
      RETURN_VALUE = 1;
    }
  return (NULL);
}

/*
char	*check_acess(char **path, char **string, char **env)
{
  int	i;
  char	*str;

  i = 0;
  while (path[i] != NULL)
    {
      str = malloc(sizeof(char) * my_strlen(path[i]) + my_strlen(string[0]));
      str = my_strcat(path[i], "/");
      str = my_strcat(str, string[0]);
      if (access(str, F_OK | X_OK) == 0)
	return (str);
      i++;
    }
  str = my_strcat(my_getenv(env, "PWD"), "/");
  str = my_strcat(str, string[0]);
  if ((access(str, F_OK | X_OK) == 0))
      return (str);
  if (checkInternalCommand(string, env) == 0)
    {
      write(2, string[0], my_strlen(string[0]));
      write(2, ": ", 2);
      write(2, "Command not found.\n", my_strlen("Command not found.\n"));
      RETURN_VALUE = 1;
    }
  return (NULL);
}
*/
