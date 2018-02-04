/*
** sig_handler.c for sig_handler.c in /home/lecherbonnier/Projet/PSU_2016_navy/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 15:40:48 2017 Leo Lecherbonnier
** Last update Mon Feb 13 11:31:13 2017 Leo Lecherbonnier
*/

#include "navy.h"

void sig_handler(int signo, siginfo_t *info, void *sig_handler)
{
  static	int	i = 0;

  if (i == 0 && signo == SIGUSR1)
    {
      g_player.pid_adverse = info->si_pid;
      i++;
    }
  else if (signo == SIGQUIT)
    return;
  else if (signo == SIGUSR2)
    my_writer(0);
  else if (signo == SIGUSR1)
    my_writer(1);
  return;
}
