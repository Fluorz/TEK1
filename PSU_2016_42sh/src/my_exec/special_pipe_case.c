/*
** special_pipe_case.c for special_pipe_case.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/my_exec/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun Jun  4 18:13:47 2017 Leo Lecherbonnier
** Last update Thu Jun  8 11:26:27 2017 Sid Djilali Saiah
*/

#include "my_exec.h"

t_transitor	*apply_pipe_out_and_redir_left(t_transitor *transitor,
					       t_arg_transitor *arg)
{
  int		in;
  int 		pid;
  int		status;

  if ((in = open(arg->arg_redirection, O_RDONLY)) == -1)
    {
      printf("%s: No such file or directory.\n", arg->arg_redirection);
      arg->return_value = 1;
      return (transitor);
    }
  pipe (transitor->pipefd);
  pid = create_process();
  if (pid == 0)
    {
      close(transitor->pipefd[0]);
      dup2(transitor->pipefd[1], 1);
      dup2(in, 0);
      chlid_process(arg->bin_path, arg->argv_execve, transitor->env);
    }
  else
    waitpid(pid, &status, WSTOPPED);
  close(transitor->pipefd[1]);
  dup2(transitor->pipefd[0], 0);
  arg = my_status(status, arg);
  return (transitor);
}
