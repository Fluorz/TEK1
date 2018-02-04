/*
** env.c for env.h in /root/PSU_2016_minishell1/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Tue Jan 17 20:55:29 2017 Leo Lecherbonnier
** Last update Fri Jan 20 16:39:30 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

int	check_env(char *str, char **env)
{
  if (str[0] == 'e' && str[1] == 'n' &&
      str[2] == 'v')
    {
      print_env(env);
      return (1);
    }
  return (0);
}

void	print_env(char **env)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (env[j] != NULL)
    {
      my_putstr(env[j]);
      my_putchar('\n');
      j++;
    }
}
