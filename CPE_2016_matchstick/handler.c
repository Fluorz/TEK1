/*
** handler.c for handler.c in /home/lecherbonnier/Projet/CPE_2016_matchstick/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 21 23:52:55 2017 Leo Lecherbonnier
** Last update Tue Feb 21 23:57:05 2017 Leo Lecherbonnier
*/

#include "matchstick.h"

t_player	handler_map(t_player player)
{
  my_printf("Player removed %s match(es) from line %s\n",
	    player.number, player.line);
  player.map = move_pipe(my_getnbr(player.line),
			 my_getnbr(player.number), player.map);
  print_map(player.map, player.len + 2);
  return (player);
}

int	handler_lines(t_player player)
{
  int	i = 0;

  while (player.line[i] != '\0')
    {
      if (player.line[i] < '0' || player.line[i] > '9')
	{
    my_printf("Error: invalid input (positive number expected)\n");
	  return (1);
  }
      i++;
    }
  if (my_getnbr(player.line) <= player.len &&
      my_getnbr(player.line) > 0 && player.line[0] != '\0')
      return (0);
  else if (my_getnbr(player.line) <= 0 || my_getnbr(player.line) > player.len)
    {
      my_printf("Error: this line is out of range\n");
      return (1);
    }
  return (0);
}

int	handler_matches(t_player player)
{
  int	i = 0;

  while (player.number[i] != '\0')
    {
      if (player.number[i] < '0' || player.number[i] > '9')
	{
    my_printf("Error: invalid input (positive number expected)\n");
	  return (1);
  }
      i++;
    }
  if ((my_getnbr(player.number)) == 0)
    {
      my_printf("Error: you have to remove at least one match\n");
      return (1);
    }
  else if (my_getnbr(player.number) > player.len_max)
    {
      my_printf("Error: you cannot remove more than %d matches ",
		player.len_max);
      my_printf("per turn\n");
      return (1);
    }
  return (check_other(player));
}

int	check_other(t_player player)
{
  if (my_getnbr(player.number) > get_how_many_pipe(player))
    {
      my_printf("Error: not enough matches on this line\n");
      return (1);
    }
  return (0);
}
int	get_how_many_pipe(t_player player)
{
  int	index = 0;
  int	i = my_getnbr(player.line);
  int	j = 0;

  while (player.map[i][j] != '\0')
    {
      if (player.map[i][j] == '|')
	index++;
      j++;
    }
  return (index);
}
