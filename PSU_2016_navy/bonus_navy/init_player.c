/*
** init_player.c for navy in /home/monty/Documents/Rendu/navy/PSU_2016_navy/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  8 10:20:01 2017 Monty Criel
** Last update Thu Feb 16 16:24:46 2017 Leo Lecherbonnier
*/

#include <navy.h>

t_player	*init_player(char *av)
{
  int		file;
  t_player	*player;
  int		status;

  if ((file = open(av, O_RDONLY)) == -1)
    return (NULL);
  if ((player = malloc(sizeof(t_player))) == 0)
    return (NULL);
  player->map = create_board();
  player->enemy = create_board();
  if ((player->ships = count_ships(av)) == -1)
    return (NULL);
  status = place_ships(player->map, av);
  if (status != 0)
    return (NULL);
  return (player);
}

int	game_end(int ships)
{
  if (ships == 0)
    return (0);
  else
    return (1);
}
