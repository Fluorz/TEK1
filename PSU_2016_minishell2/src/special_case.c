/*
** special_case.c for special_case.c in /root/PSU_2016_minishell1/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Wed Jan 18 00:27:53 2017 Leo Lecherbonnier
** Last update Tue Apr 11 09:36:59 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

int checkInternalCommand(char	**str, t_parse *p)
{
  int	i;

  if (my_strcmp("cd", str[0]) == 0)
    {
      changeDir(str, p->env);
      return (1);
    }
  if (my_strcmp("exit", str[0]) == 0)
    {
      i = 0;
      if (str[1] != NULL)
	i = my_getnbr(str[1]);
      my_putstr("exit\n");
      exit(i);
    }
  else if (my_strcmp("clear", str[0]) == 0)
    {
      my_putstr("\033[2J\033[1;1H");
      return (1);
    }
  else if (my_strcmp("env", str[0]) == 0)
    print_env(p->env);
  else if (check_other_command(str, p) == 1)
      return (1);
  return (0);
}

int	check_other_command(char **str, t_parse *p)
{
  if (my_strcmp("setenv", str[0]) == 0)
    {
      p->env = my_setenv(str, p->env);
      return (1);
    }
  else if (my_strcmp("unsetenv", str[0]) == 0)
    {
      my_unsetenv(str, p->env);
      return (1);
    }
  return (0);
}

void	my_error(const char *error, const char *var)
{
  (void)write(2, var, my_strlen(var));
  (void)write(2, ": ", 3);
  (void)write(2, error, my_strlen(error));
}
