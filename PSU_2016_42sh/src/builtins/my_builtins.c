/*
** my_builtins.c for minishell2 in /home/monty/Documents/Rendu/minishell/PSU_2016_minishell2/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Wed Apr  5 16:18:24 2017 Monty Criel
** Last update May Jun 15 15:52:34 2017
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

int	try_print_env_var(char **env, char **cmd)
{
  char	*var;
  char	*tmp;
  int	x;
  int	i;

  if (cmd[1][0] != '$')
    return (-1);
  i = 1;
  x = 0;
  tmp = malloc(sizeof(char) * (strlen(cmd[1])));
  if (tmp == NULL)
    exit(84);
  while (cmd[1][i] != '\0')
    {
      tmp[x] = cmd[1][i];
      x += 1;
      i += 1;
    }
  tmp[i] = '\0';
  var = get_env_var(env, tmp);
  if (var == NULL)
    return (84);
  printf("%s\n", var);
  return (0);
}

t_func flag_list[3] =
{
  {&change_env, '0'},
  {&change_directory, '1'},
  {NULL, -1}
};

int	basic_builtin(char **env, char **cmd)
{
  if (((strcmp(cmd[0], "setenv") == 0) || (strcmp(cmd[0], "env") == 0)) &&
      cmd[1] == NULL)
    {
      print_env(env);
      return (0);
    }
  if (strcmp(cmd[0], "pwd") == 0 && cmd[1] == NULL)
    {
      printf("%s\n", get_env_var(env, "PWD"));
      return (0);
    }
  if ((strcmp(cmd[0], "echo") == 0) && cmd[2] == NULL)
    {
      if (try_print_env_var(env, cmd) == 0)
	return (0);
    }
  return (-1);
}

char	**my_builtins(char **env, char **cmd, int *status)
{
  int	i;

  if (basic_builtin(env, cmd) == 0)
    return (*status = 0, env);
  i = 0;
  *status = 0;
  while (flag_list[i].key != -1)
    {
      env = flag_list[i].ptrfunc(cmd, env, status);
      if (*status != -1)
	return (env);
      i += 1;
    }
  return (*status = 1, env);
}
