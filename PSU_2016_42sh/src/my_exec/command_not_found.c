/*
** command_not_found.c for command_not_found.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/my_exec/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Jun  1 16:45:55 2017 Leo Lecherbonnier
** Last update Tue Jun  6 09:28:15 2017 Sid Djilali Saiah
*/

#include "my_exec.h"
#include "transition.h"

void	command_not_found(t_arg_transitor *args)
{
    write(2, args->argv_execve[0], strlen(args->argv_execve[0]));
    write(2, ": ", 2);
    write(2, "Command not found.\n", strlen("Command not found.\n"));
    args->return_value = 1;
}

int	check_if_builtin(t_arg_transitor *arg)
{
  char	*str;

  str = arg->argv_execve[0];
  if (((strcmp(str, "exit") == 0))
      || ((strcmp(str, "unsetenv") == 0))
      || ((strcmp(str, "setenv") == 0))
      || ((strcmp(str, "echo") == 0))
      || ((strcmp(str, "which") == 0))
      || ((strcmp(str, "where") == 0))
      || ((strcmp(str, "env") == 0))
      || ((strcmp(str, "cd") == 0))
      || ((strcmp(str, "pwd") == 0)))
      return (0);
  return (1);
}
