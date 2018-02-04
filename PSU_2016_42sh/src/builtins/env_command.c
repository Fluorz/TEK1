/*
** env_command.c for 42sh in /home/monty/Documents/Rendu/minishell/PSU_2016_42sh/src/builtins/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Fri Jun  2 11:17:29 2017 Monty Criel
** Last update Mon Jun 12 11:40:45 2017 Monty Criel
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <my_exec.h>
#include "my.h"

int	my_isalpha(char c)
{
  if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
    return (0);
  else
    return (1);
}

char	**set_env(char **env, char **cmd, int *status)
{
  int	pos;
  char	*new_var;

  if (my_isalpha(cmd[1][0]) == 0)
    {
      pos = find_str_tab(env, cmd[1]);
      if (pos != -1)
	{
	  new_var = my_strcat(my_strcat(cmd[1], "="), cmd[2]);
	  printf("%s\n", new_var);
	  env[pos] = my_copy(new_var);
	}
      else
	{
	  new_var = my_strcat(my_strcat(cmd[1], "="), cmd[2]);
	  env = tab_append_tail(env, new_var);
	}
      free(new_var);
      return (*status = 0, env);
    }
  else
    {
      printf("setenv: Variable name must begin with a letter.\n");
      return (*status = 1, env);
    }
}

int	setenv_args(char **cmd_args, char **env)
{
  int	i;

  i = 0;
  while (cmd_args[i] != NULL)
    i = i + 1;
  if (i > 3)
    {
      printf("setenv: Too many arguments.\n");
      return (-1);
    }
  if (i == 1)
    {
      print_env(env);
      return (0);
    }
  return (0);
}

char	**unset_env(char **env, char **cmd, int *status)
{
  int	pos;

  pos = find_str_tab(env, cmd[1]);
  if (pos != -1)
    env = tab_pop(env, pos);
  *status = 0;
  return (env);
}

char	**change_env(char **cmd, char **env, int *status)
{
  if (strcmp(cmd[0], "setenv") == 0)
    {
      if ((check_arg_setenv(cmd)) != 0)
	return (*status = 1, env);
      if (setenv_args(cmd, env) == -1)
	{
	  free_tab(cmd);
	  return (*status = 1, env);
	}
      env = set_env(env, cmd, status);
      free_tab(cmd);
      return (env);
    }
  if (strcmp(cmd[0], "unsetenv") == 0)
    {
      if (cmd[1] == NULL)
	return (printf("unsetenv: Too few arguments.\n"), *status = 1, env);
      env = unset_env(env, cmd, status);
      free_tab(cmd);
      return (env);
    }
  if ((check_bonus_builtins(cmd, env)) == 0)
    return (*status = 0, env);
  return (*status = -1, env);
}
