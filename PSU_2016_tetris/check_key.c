/*
** check_key.c for check_key.c in /home/lecherbonnier/Projet/PSU_2016_tetris/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Feb 27 18:04:13 2017 Leo Lecherbonnier
** Last update Wed Mar  1 10:46:35 2017 Leo Lecherbonnier
*/

#include "tetris.h"

t_debug check_other(t_debug debug)
{
  int	i = 0;
  int	j = 0;
  char	**tab;

  tab = init_tab(debug);
  while (i != 5)
    {
      if (my_strcmp(tab[i], tab[j]) == 0 && i != j)
	exit (0);
      if (j == 5)
	    {
	      j = 0;
	      i++;
	    }
	  j++;
    }
  if (debug.boolean == 1)
    print_debug(debug);
  return (debug);
}

char	**init_tab(t_debug debug)
{
  char	**str;

  str = malloc(sizeof(char) * debug.len_list);
  str[0] = malloc(sizeof(char) * debug.len_list);
  str[0] = debug.key_left;
  str[1] = malloc(sizeof(char) * debug.len_list * 2);
  str[1] = debug.key_right;
  str[2] = malloc(sizeof(char) * debug.len_list * 2);
  str[2] = debug.key_turn;
  str[3] = malloc(sizeof(char) * debug.len_list * 2);
  str[3] = debug.key_drop;
  str[4] = malloc(sizeof(char) * debug.len_list * 2);
  str[4] = debug.key_quit;
  str[5] = malloc(sizeof(char) * debug.len_list * 2);
  str[5] = debug.key_pause;
  return (str);
}
