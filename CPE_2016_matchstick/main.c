/*
** main.c for main.c in /home/lecherbonnier/bin/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Jan 30 11:17:10 2017 Leo Lecherbonnier
** Last update Tue Feb 21 09:33:18 2017 Leo Lecherbonnier
*/

#include "matchstick.h"

int	main(int ac, char **av)
{
  int	status;
  char **map = NULL;

  if (ac != 3)
    return (84);
  map = create_map(my_getnbr(av[1]));
  print_map(map, my_getnbr(av[1]) + 2);
  my_putstr("\n");
  status = player(map, my_getnbr(av[1]), my_getnbr(av[2]));
  if (status == 2)
    return (2);
  else if (status == 1)
    return (1);
  return (0);
}
