/*
** take.c for take.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Apr 26 17:36:14 2017 Leo Lecherbonnier
** Last update Apr Apr 26 17:36:36 2017
*/

#include "open_file.h"

char	*take_name(char *str)
{
  char	**tab;

  tab = my_str_to_wordtab(str, ' ');
  return (tab[0]);
}

int	take_x(char *str)
{
  char	**tab;

  tab = my_str_to_wordtab(str, ' ');
  return (my_getnbr(tab[1]));
}

int	take_y(char *str)
{
  char	**tab;

  tab = my_str_to_wordtab(str, ' ');
  return (my_getnbr(tab[2]));
}
