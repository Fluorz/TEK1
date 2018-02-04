/*
** init_debug.c for init_debug.c in /home/lecherbonnier/Projet/PSU_2016_tetris/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 21 10:45:12 2017 Leo Lecherbonnier
** Last update Sun Feb 26 18:20:42 2017 Leo Lecherbonnier
*/

#include "tetris.h"

t_debug	init_debug(int ac, t_debug debug)
{
  debug.key_left = "^EOD";
  debug.key_right = "^EOC";
  debug.key_turn = "^EOA";
  debug.key_drop = "^EOB";
  debug.key_quit = "q";
  debug.key_pause = "(space)";
  debug.next = "Yes";
  debug.level = 1;
  debug.size = "20*10";
  debug.ac = ac;
  debug.boolean = 0;
  return (debug);
}
