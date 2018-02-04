/*
** main.c for main.c in /root/Desktop/PSU/PSU_2016_my_sokoban/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Dec 12 16:44:10 2016 Leo Lecherbonnier
** Last update Tue Dec 20 17:40:14 2016 Leo Lecherbonnier
*/

#include "sokoban.h"

int			main(int ac, char **av)
{
  struct winsize	w;
  char			*str;
  int			ligne;

  ligne = 0;
  str = fs_open_file(av[1], &ligne);
  put_in_tab(str, &ligne);
  clear();
  free(str);
  return (0);
}
