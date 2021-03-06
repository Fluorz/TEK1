/*
** main.c for main.c in /home/lecherbonnier/Projet/PSU_2016_navy/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Jan 31 16:19:21 2017 Leo Lecherbonnier
** Last update Thu Feb 16 15:42:33 2017 Leo Lecherbonnier
*/

#include "navy.h"

int					main(int ac, char **av)
{
  int				pid_player2 = 0;
  struct		sigaction s_sa;
  t_player	*player1;
  t_player	*player2;

  s_sa.sa_sigaction = &sig_handler;
  s_sa.sa_flags = SA_SIGINFO;
  if (main_option(ac, av) != 0)
    return (84);
  if (ac == 3)
    {
      if ((player2 = init_player(av[2])) == NULL)
	return (84);
      my_printf("my_pid: %d\n", getpid());
      return (set_player_2(s_sa, player2, av, pid_player2));
    }
  else if (ac == 2)
    {
      if ((player1 = init_player(av[1])) == NULL)
	return (84);
      my_printf("my_pid: %d\n", getpid());
      return (set_player_1(s_sa, player1, av));
    }
  return (0);
}
