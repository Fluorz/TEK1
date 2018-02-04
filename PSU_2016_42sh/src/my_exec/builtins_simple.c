/*
** builtins_simple.c for builtins_simple.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/my_exec/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Jun  2 10:24:20 2017 Leo Lecherbonnier
** Last update Feb Jun 12 14:08:46 2017
*/

#include "my_exec.h"
#include "my.h"

t_transitor	*builtins_simple(t_transitor *transitor, t_arg_transitor *arg)
{
  int		status;

  transitor->env = my_builtins(transitor->env, arg->argv_execve, &status);
  arg->return_value = status;
  return (transitor);
}

t_transitor     *builtins_pipe(t_transitor *transitor, t_arg_transitor *arg)
{
  int 		pid;
  int		status;

  if (arg->r_right == true)
    {
      printf("Ambiguous output redirect.\n");
      exit (1);
    }
  if (arg->r_left == true)
    {
      transitor = apply_pipe_out_and_redir_left(transitor, arg);
      return (transitor);
    }
  pid = create_process();
  if (pid == 0)
    {
      close(transitor->pipefd[0]);
      dup2(transitor->pipefd[1], 1);
      my_builtins(transitor->env, arg->argv_execve, &status);
    }
  wait(&status);
  close(transitor->pipefd[1]);
  dup2(transitor->pipefd[0], 0);
  arg->return_value = status;
  return (transitor);
}
