/*
** special_case.c for special_case.c in /root/PSU_2016_minishell1/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Wed Jan 18 00:27:53 2017 Leo Lecherbonnier
** Last update Wed Mar  1 08:50:03 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

int checkInternalCommand(char	**str, char **env)
{
  int	i;

  if (my_strcmp("cd", str[0]) == 0)
    {
      changeDir(str, env);
      return (1);
    }
  if (my_strcmp("exit", str[0]) == 0)
    {
      i = 0;
      if (str[1] != NULL)
	i = my_getnbr(str[1]);
      exit(i);
    }
  else if (my_strcmp("clear", str[0]) == 0)
    {
      my_putstr("\033[2J\033[1;1H");
      return (1);
    }
  else if (my_strcmp("env", str[0]) == 0)
    print_env(env);
  return 0;
}

// faire un stat pour voir si cest un directory
void changeDir(char **str, char **env)
{
  if (str[1] == NULL)
      chdir(my_getenv(env, "HOME"));
    else
    {
	if (chdir(str[1]) == -1)
	{
	  my_putstr(str[1]);
	  my_putstr(": no such directory\n");
	}
    }
}
