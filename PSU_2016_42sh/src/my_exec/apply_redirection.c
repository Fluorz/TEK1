/*
** apply_redirection.c for apply_redirection.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/my_exec/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Jun  2 23:04:16 2017 Leo Lecherbonnier
** Last update Feb Jun 12 15:59:59 2017
*/

#include "gnl.h"
#include "my_exec.h"

static void    error_redirection(t_arg_transitor *arg)
{
        if (arg->pipe_in == true || arg->pipe_out == true)
    {
        if (arg->prev->r_right == true)
        {
            printf("Ambiguous output redirect.\n");
            exit (1);
        }
        printf("Ambiguous input redirect.\n");
        arg->return_value = 1;
        exit (1);
    }

}
t_transitor	*apply_in_redirection(t_transitor *transitor,
                                    t_arg_transitor *arg)
{
  int		in;
  int 		pid;
  int		status;

  error_redirection(arg);
  if ((in = open(arg->arg_redirection, O_RDONLY)) == -1)
    {
      printf("Ambiguous input redirect.\n");
      arg->return_value = 1;
      return (transitor);
    }
    pid = create_process();
    if (pid == 0)
     {
       dup2(in, 0);
       chlid_process(arg->bin_path, arg->argv_execve, transitor->env);
     }
   else
     waitpid(pid, &status, WSTOPPED);
    arg = my_status(status, arg);
    return (transitor);
}

t_transitor	*apply_out_redirection(t_transitor *transitor,
                                    t_arg_transitor *arg)
{
  int		status;
  int		out;
  int 		pid;

  pid = create_process();
  if (pid == 0)
   {
     if ((out = open(arg->arg_redirection, O_CREAT | O_WRONLY | O_TRUNC, \
		    S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
       exit (-1);
     dup2(out, 1);
     chlid_process(arg->bin_path, arg->argv_execve, transitor->env);
   }
 else
   waitpid(pid, &status, WSTOPPED);
  arg = my_status(status, arg);
  return (transitor);
}

t_transitor	*apply_double_in_redirection(t_transitor *transitor,
                                            t_arg_transitor *arg)
{
  int 		pid;
  int		status;
  int		fd[2];
  char		*str;
  int		old;

  pipe (fd);
  write(2, "? ", 2);
  while ((str = get_next_line(0)) && strcmp(str, arg->arg_redirection))
    {
      write(fd[1], str, strlen(str));
      write(fd[1], "\n", 1);
      free(str);
      write(2, "? ", 2);
    }
  close (fd[1]);
  old = dup(0);
  dup2(fd[0], 0);
  pid = create_process();
  if (pid == 0)
    chlid_process(arg->bin_path, arg->argv_execve, transitor->env);
  wait(&status);
  close(fd[0]);
  dup2(old, 0);
  arg = my_status(status, arg);
  return (transitor);
}

t_transitor	*apply_double_out_redirection(t_transitor *transitor,
                                            t_arg_transitor *arg)
{
  int		status;
  int		out;
  int 		pid;

  pid = create_process();
  if (pid == 0)
    {
      if ((out = open(arg->arg_redirection, O_CREAT | O_WRONLY | O_APPEND, \
		      S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	exit (-1);
      dup2(out, 1);
      chlid_process(arg->bin_path, arg->argv_execve, transitor->env);
    }
  else
    waitpid(pid, &status, WSTOPPED);
  arg = my_status(status, arg);
  return (transitor);
}
