/*
** build_debug.c for build_debug.c in /home/lecherbonnier/Projet/PSU_2016_tetris/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 21 10:43:40 2017 Leo Lecherbonnier
** Last update Mon Feb 27 18:15:50 2017 Leo Lecherbonnier
*/

#include "tetris.h"

t_flag	flags[] =
{
		{"-l", &flag_level},
		{"--level", &flag_level},
		{"-kl", &flag_key_left},
		{"--key-left", &flag_key_left},
		{"-kr", &flag_key_right},
		{"--key-right", &flag_key_right},
		{"-kt", &flag_key_turn},
		{" --key-turn", &flag_key_turn},
		{"-kd", &flag_key_drop},
		{"--key-drop", &flag_key_drop},
		{"-kq", &flag_key_quit},
		{"--key-quit", &flag_key_quit},
		{"-kp", &flag_key_pause},
		{"--key-pause", &flag_key_pause},
		{"--map-size", &flag_key_map},
		{"-w", &flag_key_next},
		{"--without-next", &flag_key_next},
		{"-d", &flag_key_debug},
		{"--debug", &flag_key_debug},
		{0, NULL}
};

t_debug	build_debug(t_debug debug)
{
  int	j = 0;
  int	m = 0;

  while (j != debug.len_list)
    {
      m = 0;
      if (debug.list[j][0] == '-')
	{
		while (my_strcmp(flags[m].arr, debug.list[j]) != 0 &&
		       flags[m].arr != NULL)
        m++;
	  if (flags[m].arr == NULL)
	    exit (0);
	  debug = flags[m].s_flag(debug, debug.list, debug.list[j + 1]);
	  if (check_special_case(debug.list[j]) == 0)
	    j++;
	}
      if (j >= debug.len_list)
break;
	  j++;
    }
  debug = check_other(debug);
  return (debug);
}

int	check_special_case(char *str)
{
  if ((my_strcmp(str, "-w") != 0)
      || (my_strcmp(str, "-d") != 0)
      || (my_strcmp(str, "--debug") != 0))
    return (1);
  return (0);
}
