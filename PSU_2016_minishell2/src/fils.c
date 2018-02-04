/*
** fils.c for fils.c in /root/PSU_2016_minishell1/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Jan 16 16:49:24 2017 Leo Lecherbonnier
** Last update Tue Apr 11 09:12:56 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

void	chlid_process(char *str, char **arg, char **env)
{
  if ((execve(str, arg, env)) == 0)
    exit (0);
  if (errno == ENOEXEC)
    {
      my_putstr(arg[0]);
      my_putstr(": Exec format error. Binary file not executable.\n");
      RETURN_VALUE = 1;
    }
  else if (errno == EACCES)
    {
      my_putstr(arg[0]);
      my_putstr(": Permission denied.\n");
      RETURN_VALUE = 1;
    }
  exit (RETURN_VALUE);
}

char	*delete_pwd_of_string(char *string, char *pwd)
{
  char	*new_str;
  int	i = 0;
  int	j = 0;

  if ((new_str = malloc(sizeof(char *) * my_strlen(string))) == NULL)
    return (NULL);
  while (string[i] == pwd[i])
    i++;
  while (string[i] != '\0')
    {
      new_str[j] = string[i];
      j++;
      i++;
    }
  return (new_str);
}
