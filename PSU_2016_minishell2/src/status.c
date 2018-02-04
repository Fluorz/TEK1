/*
** status.c for status.c in /home/lecherbonnier/Projet/PSU_2016_minishell2/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Apr 11 09:18:11 2017 Leo Lecherbonnier
** Last update Tue Apr 11 09:18:35 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

void	my_else_status(int status)
{
  if (WIFSIGNALED(status))
  {
    if (WTERMSIG(status) == SIGSEGV)
    {
      write(2, "Segmentation fault", 18);
      RETURN_VALUE = 139;
    }
    if (WTERMSIG(status) == SIGFPE)
    {
      write(2, "Floating exception", 18);
      RETURN_VALUE = 136;
    }
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
}

void	my_status(int status)
{
  if (status != 0)
    RETURN_VALUE = 1;
  my_else_status(status);
}
