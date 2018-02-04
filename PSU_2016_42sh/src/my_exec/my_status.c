/*
** my_status.c for my_status.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/my_exec/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Jun  2 10:00:22 2017 Leo Lecherbonnier
** Last update Fri Jun  2 14:51:55 2017 Leo Lecherbonnier
*/

#include "transition.h"
#include "my_exec.h"

t_arg_transitor *my_else_status(int status, t_arg_transitor *arg)
{
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == SIGSEGV)
	write(2, "Segmentation fault", 18) , arg->return_value = 139;
      if (WTERMSIG(status) == SIGFPE)
	write(2, "Floating exception", 18) , arg->return_value = 136;
      if (WTERMSIG(status) == SIGILL)
	write(2, "Illegal instruction", 19);
      if (WTERMSIG(status) == SIGKILL)
	write(2, "Killed", 6);
      if (WTERMSIG(status) == SIGUSR1)
	write(2, "User signal 1", 13);
      if (WTERMSIG(status) == SIGUSR2)
	write(2, "User signal 2", 13);
      if ((status & 0x80))
	write(2, " (core dumped)", 14);
      write(2, "\n", 1);
    }
  return (arg);
}

t_arg_transitor *my_status(int status, t_arg_transitor *arg)
{
  if (status != 0)
    arg->return_value = 1;
  arg = my_else_status(status, arg);
  return (arg);
}
