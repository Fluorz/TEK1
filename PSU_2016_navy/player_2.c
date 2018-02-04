/*
** player_2.c for player_2.c in /home/lecherbonnier/Projet/PSU_2016_navy/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Feb 13 09:33:09 2017 Leo Lecherbonnier
** Last update Thu Feb 16 18:29:14 2017 Leo Lecherbonnier
*/

#include "navy.h"

void	update_map(t_player *player2, char *str, struct sigaction s_sa, int i)
{
  if (i == 0)
    {
      send_signal(str, g_player.pid_adverse);
      check_connection(s_sa);
      if (g_player.position_envoye[0] == 'M')
	shoot(player2, str, 'M');
      else
	shoot(player2, str, 'H');
      display_map(player2->map, player2->enemy);
    }
}

int		player2(struct sigaction s_sa, t_player *player_2, char **argv)
{
  int		i = 0;
  char		*str;

  if (player_2 == NULL)
    return (84);
  print_first_map(player_2->map, player_2->enemy);
  while (1)
    {
      if (i == 0)
	{
	  my_printf("waiting for enemy's attack...\n");
	  check_connection(s_sa);
	  str = g_player.position_envoye;
	  send_signal(attack_status(str, player_2->map), g_player.pid_adverse);
    if (count_cross(player_2->map) == 14)
	    return (2);
	}
      i = 0;
      str = str_inutile();
      if (check_str(str) == 1)
	i = 1;
      update_map(player_2, str, s_sa, i);
      if (count_cross(player_2->enemy) == 14)
	return (1);
    }
}

char *str_inutile()
{
  char	*str = NULL;

  my_putstr("attack: ");
  str = get_next_line(0);
  str = up(str);
  return (str);
}
void	display_map(char **map, char **enemy)
{
  my_putstr("my positions:\n");
  print_board(map);
  my_putchar('\n');
  my_putstr("enemy's positions:\n");
  print_board(enemy);
  my_putchar('\n');
}
