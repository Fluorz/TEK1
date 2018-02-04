/*
** flag_key_other.c for flag_key_other.c in /home/lecherbonnier/Projet/PSU_2016_tetris/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 21 15:35:09 2017 Leo Lecherbonnier
** Last update Mon Feb 27 18:08:37 2017 Leo Lecherbonnier
*/

#include "tetris.h"

t_debug	flag_key_quit(t_debug debug, char **list, char *str)
{
  debug.key_quit = str;
  if (my_strcmp(str, " ") == 0)
    debug.key_quit = "(space)";
  return (debug);
}

t_debug	flag_key_pause(t_debug debug, char **list, char *str)
{
  debug.key_pause = str;
  if (my_strcmp(str, " ") == 0)
    debug.key_pause = "(space)";
  return (debug);
}

t_debug	flag_key_map(t_debug debug, char **list, char *str)
{
  static int	i = 0;

  if (i == 0)
    {
      debug.size = str;
      i++;
    }
  return (debug);
}

t_debug	flag_key_next(t_debug debug, char **list, char *str)
{
  debug.next = "No";
  return (debug);
}

t_debug	flag_key_debug(t_debug debug, char **list, char *str)
{
  debug.boolean = 1;
  return (debug);
}
