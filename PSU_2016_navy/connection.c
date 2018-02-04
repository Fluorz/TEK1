/*
** connection.c for connection.c in /home/lecherbonnier/Projet/PSU_2016_navy/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 15:40:11 2017 Leo Lecherbonnier
** Last update Mon Feb 13 09:25:39 2017 Leo Lecherbonnier
*/

#include "navy.h"

void	check_first_connection(struct sigaction s_sa)
{
  sigaction(SIGUSR1, &s_sa, NULL);
  sigaction(SIGQUIT, &s_sa, NULL);
  pause();
  return;
}

void	check_connection(struct sigaction s_sa)
{
  g_player.position_envoye[1] = 0;
  while (g_player.position_envoye[1] == 0)
    {
      sigaction(SIGUSR1, &s_sa, NULL);
      sigaction(SIGUSR2, &s_sa, NULL);
      sigaction(SIGQUIT, &s_sa, NULL);
    }
  return;
}

/*void	check_connection(struct sigaction s_sa)
{
  while (1)
    {
      sigaction(SIGUSR1, &s_sa, NULL);
      sigaction(SIGUSR2, &s_sa, NULL);
      sigaction(SIGQUIT, &s_sa, NULL);
    }
}*/
