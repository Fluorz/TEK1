/*
** execve_pipe.c for execve_pipe.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/my_exec/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Jun  2 10:26:15 2017 Leo Lecherbonnier
** Last update Sat Jun  3 16:51:35 2017 Leo Lecherbonnier
*/

#include "my_exec.h"

t_transitor	*execve_pipe(t_transitor *transitor, t_arg_transitor *arg)
{
  if (arg->pipe_in == true && arg->pipe_out == false && arg->r_left == false)
    transitor = apply_pipe_in(transitor, arg);
  else if (arg->pipe_out == true && arg->pipe_in == false)
    transitor = apply_pipe_out(transitor, arg);
  else if (arg->pipe_out == true && arg->pipe_in == true)
    transitor = apply_double_pipe(transitor, arg);
  else if (arg->r_left == true)
    transitor = apply_in_redirection(transitor, arg);
  else if (arg->r_double_left == true)
    transitor = apply_double_in_redirection(transitor, arg);
  else if (arg->r_right == true)
    transitor = apply_out_redirection(transitor, arg);
  else if (arg->r_double_right == true)
    transitor = apply_double_out_redirection(transitor, arg);
  return (transitor);
}
