/*
** main_option.c for main_option.c in /home/lecherbonnier/Projet/PSU_2016_navy/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Feb  7 16:03:14 2017 Leo Lecherbonnier
** Last update Fri Feb 17 13:42:42 2017 Leo Lecherbonnier
*/

#include "navy.h"

int	set_player_2(struct sigaction s_sa,
		      t_player *player_2, char **av, int pid_player2)
{
  int	status;

  status = player1(s_sa, player_2, av);
  if (status != 84)
    {
      if (status == 2)
	my_putstr("Enemy won\n");
      else
	my_putstr("I won\n");
      return (status);
    }
  return (status);
}

int	set_player_1(struct sigaction s_sa, t_player *player_1, char **av)
{
  int	pid_player2 = 0;
  int	status;

  if ((pid_player2 = open(av[1], O_RDONLY)) == -1)
    return (84);
  check_first_connection(s_sa);
	my_printf("waiting for enemy connexion...\n");
  my_printf("\nenemy connected\n\n");
  kill(g_player.pid_adverse, SIGUSR1);
  status = player1(s_sa, player_1, av);
  if (status != 84)
    {
      if (status == 2)
	my_putstr("Enemy won\n");
      else
	my_putstr("I won\n");
      return (status);
    }
  return (status);
}

int	main_option(int ac, char **av)
{
  if (ac < 2 || ac > 3)
    return (84);
  if (my_strcmp(av[1], "-h") == 0)
    {
      print_info();
      return (0);
    }
  return (0);
}
