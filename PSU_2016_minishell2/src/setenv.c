/*
** setenv.c for setenv.c in /home/lecherbonnier/Projet/PSU_2016_minishell2/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Apr  5 10:54:39 2017 Leo Lecherbonnier
** Last update Tue Apr 11 09:36:36 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

char	**else_my_setenv(char **str, char **env)
{
  if (str[2] == NULL)
  {
    env = struct_op(env, str[1], NULL);
  }
  else if (str[3] == NULL)
  env = struct_op(env, str[1], str[2]);
  return (env);

}
char	**my_setenv(char **str, char **env)
{
  int	i = 0;

  if (str[1] == NULL) {print_env(env); return (env);}
  else if (str[1][0] >= '0' && str[1][0] <= '9')
    {
      my_putstr("setenv: Variable name must begin with a letter.\n");
      RETURN_VALUE = 1;
      return (env);
    }
  while (str[1][i] != '\0')
    {
      if (str[1][i] >= 'a' && str[1][i] <= 'z')
	i++;
      else if (str[1][i] >= 'A' && str[1][i] <= 'Z')
	i++;
      else
	{
    my_putstr("setenv: Variable name must contain alphanumeric characters.\n");
	  RETURN_VALUE = 1;
	  return (env);
	}
    }
  return (else_my_setenv(str, env));
}

char **my_unsetenv(char **str, char **env)
{
  int	j;

  if (str[1] == NULL)
    {
      my_putstr("unsetenv: Too few arguments.\n");
      RETURN_VALUE = 1;
    }
  else
    {
      if ((j = find_line_before_delete(str[1], env)) == -1)
	return (env);
      env = delete_line(j, env);
    }
}
