/*
** flag_key.c for flag_key.c in /home/lecherbonnier/Projet/PSU_2016_tetris/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 21 15:32:39 2017 Leo Lecherbonnier
** Last update Sun Feb 26 18:30:06 2017 Leo Lecherbonnier
*/

#include "tetris.h"

t_debug	flag_level(t_debug debug, char **list, char *str)
{
  debug.level = my_getnbr(str);
  return (debug);
}

t_debug	flag_key_left(t_debug debug, char **list, char *str)
{
  debug.key_left = str;
  if (my_strcmp(str, " ") == 0)
    debug.key_left = "(space)";
  return (debug);
}

t_debug	flag_key_right(t_debug debug, char **list, char *str)
{
  debug.key_right = str;
  if (my_strcmp(str, " ") == 0)
    debug.key_right = "(space)";
  return (debug);
}

t_debug	flag_key_turn(t_debug debug, char **list, char *str)
{
  debug.key_turn = str;
  if (my_strcmp(str, " ") == 0)
    debug.key_turn = "(space)";
  return (debug);
}

t_debug	flag_key_drop(t_debug debug, char **list, char *str)
{
  debug.key_drop = str;
  if (my_strcmp(str, " ") == 0)
    debug.key_drop = "(space)";
  return (debug);
}
