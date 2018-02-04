/*
** player_1.c for player_1.c in /home/lecherbonnier/Projet/PSU_2016_navy/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Feb  2 20:05:25 2017 Leo Lecherbonnier
** Last update Thu Feb 23 11:06:52 2017 Leo Lecherbonnier
*/

#include "navy.h"

void	update(t_player *player1, char *str, struct sigaction s_sa)
{
  int	a;
    //send_signal(str, g_player.pid_adverse);
    //check_connection(s_sa);
    //if (g_player.position_envoye[0] == 'M')
    a = rand_a_b(1, 3);
  if (a == 1)
      shoot(player1, str, 'M');
  else
      shoot(player1, str, 'H');
}

void	print_first_map(char **map, char **enemy)
{
  my_putstr("my positions:\n");
  print_board(map);
  my_putchar('\n');
  my_putstr("enemy's positions:\n");
  print_board(enemy);
  my_putchar('\n');
}

int		player1(struct sigaction s_sa, t_player *player_1, char **argv)
{
  char		*str;

  if (player_1 == NULL)
    return (84);
  print_first_map(player_1->map, player_1->enemy);
  while (1)
    {
      my_putstr("attack: ");
      str = get_next_line(0);
      str = up(str);
      if (check_str(str) == 0)
	{
	  update(player_1, str, s_sa);
    if (count_cross(player_1->enemy) == 14)
	    return (1);
	  printf("AI's TURN:\n\n");
	  str = play_ia();
	  attack_status(str, player_1->map);
	  display_map(player_1->map, player_1->enemy);
    if (count_cross(player_1->map) == 14)
    return (2);
	}
    }
}

int rand_a_b(int a, int b)
{
  if (b == 1)
    b++;
  return (rand() % (b - a) + a);
}

char	*play_ia()
{
  char	lettre = 0;
  char	nombre = 0;
  char	*total;

  total = malloc(sizeof(char) * 4);
  lettre = rand_a_b('A', 'H');
  nombre = rand_a_b('1', '8');
  total[0] = lettre;
  total[1] = nombre;
  total[2] = '\0';
  return (total);
}

char *up(char *str)
{
  int	i = 0;

  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      else
	i++;
    }
  return (str);
}

int	count_cross(char **map)
{
  int	i = 0;
  int	j = 0;
  int	index = 0;

  while (map[j] != NULL)
    {
      if (map[j][i] == 'x')
	index++;
      if (map[j][i] == '\n')
	{
    i = 0;
	  j++;
	}
      i++;
    }
  return (index);
}
