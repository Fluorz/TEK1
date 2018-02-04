/*
** main.c for main.c in /home/lecherbonnier/Projet/PSU_2016_tetris/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 21 09:58:58 2017 Leo Lecherbonnier
** Last update Mon Mar 13 14:33:50 2017 Leo Lecherbonnier
*/

#include "tetris.h"

int	main(int ac, char **list)
{
  t_debug	debug;

  if (ac < 2) {return (84);}
  if (check_list(list, ac) != 0) {exit (0);}
  debug = parse_list(list, ac, debug);
  if ((my_strcmp(debug.list[0], "--help")) == 0)
    {
      print_info(list);
      return (0);
    }
  debug = init_debug(ac, debug);
  debug = build_debug(debug);
  return (0);
}

int	check_list(char **list, int len)
{
  int	j = 0;

  while (j != len)
    {
      if (list[j][0] == '-')
	{
	  if ((check_after_minus(list, j)) != 0)
	    exit (0);
	  if ((check_after_arg(list, j + 1)) != 0)
	    exit (0);
	}
	j++;
    }
  return (0);
}

int	check_after_arg(char **list, int j)
{
  if (list[j + 1] == NULL)
    {
      return (1);
    }
  return (0);
}

int	check_after_minus(char **list, int j)
{
  if (((my_strcmp(list[j], "-l") == 0))
      || ((my_strcmp(list[j], "--level=") == 0))
      || ((my_strcmp(list[j], "-kl") == 0))
      || ((my_strcmp(list[j], "--key-left=") == 0))
      || ((my_strcmp(list[j], "-kr") == 0))
      || ((my_strcmp(list[j], "--key-right=") == 0))
      || ((my_strcmp(list[j], "-kt") == 0))
      || ((my_strcmp(list[j], "--key-turn=") == 0))
      || ((my_strcmp(list[j], "-kd") == 0))
      || ((my_strcmp(list[j], "--key-drop") == 0))
      || ((my_strcmp(list[j], "-kq") == 0))
      || ((my_strcmp(list[j], "--key-quit=") == 0))
      || ((my_strcmp(list[j], "-kp") == 0))
      || ((my_strcmp(list[j], "--key-pause=") == 0))
      || ((my_strcmp(list[j], "--map-size") == 0))
      || ((my_strcmp(list[j], "-w") == 0))
      || ((my_strcmp(list[j], "--without-next") == 0))
      || ((my_strcmp(list[j], "-d") == 0))
      || ((my_strcmp(list[j], "--debug") == 0))
      || ((my_strcmp(list[j], "--help") == 0)))
    return (0);
  return (-1);
}
