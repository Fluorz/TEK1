/*
** apply_pipe.c for apply_pipe.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/my_exec/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Jun  2 23:02:28 2017 Leo Lecherbonnier
** Last update Feb Jun 12 12:27:02 2017
*/

#include "my_exec.h"

t_transitor	*apply_pipe_in(t_transitor *transitor, t_arg_transitor *arg)
{
  int 		pid;
  int		status;

  if (arg->r_right == true)
    {
      transitor = apply_out_redirection(transitor, arg);
      return (transitor);
    }
  pid = create_process();
  if (pid == 0)
    {
      dup2(transitor->pipefd[0], 0);
      close(transitor->pipefd[1]);
      close(transitor->pipefd[0]);
      chlid_process(arg->bin_path, arg->argv_execve, transitor->env);
    }
  wait(&status);
  close(transitor->pipefd[0]);
  close(transitor->pipefd[1]);
  arg = my_status(status, arg);
  return (transitor);
}

t_transitor	*apply_pipe_out(t_transitor *transitor, t_arg_transitor *arg)
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
  if (pipe(transitor->pipefd) != 0)
    exit (84);
  pid = create_process();
  if (pid == 0)
    {
      dup2(transitor->pipefd[1], 1);
      close(transitor->pipefd[1]);
      close(transitor->pipefd[0]);
      chlid_process(arg->bin_path, arg->argv_execve, transitor->env);
    }
  wait(&status);
  close(transitor->pipefd[1]);
  transitor->prev_read = transitor->pipefd[0];
  arg = my_status(status, arg);
  return (transitor);
}

t_transitor	*apply_double_pipe(t_transitor *transitor, t_arg_transitor *arg)
{
  int 		pid;
  int		status;

  if (pipe(transitor->pipefd) != 0)
    exit (84);
  pid = create_process();
  if (pid == 0)
    {
      dup2(transitor->prev_read, 0);
      dup2(transitor->pipefd[1], 1);
      close(transitor->prev_read);
      close(transitor->pipefd[1]);
      chlid_process(arg->bin_path, arg->argv_execve, transitor->env);
    }
  wait(&status);
  close(transitor->prev_read);
  close(transitor->pipefd[1]);
  transitor->prev_read = transitor->pipefd[0];
  arg = my_status(status, arg);
  return (transitor);
}
