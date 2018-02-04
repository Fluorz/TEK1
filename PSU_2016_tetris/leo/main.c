/*
** main.c for main.c in /home/lecherbonnier/Projet/PSU_2016_tetris/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Mar  1 14:32:27 2017 Leo Lecherbonnier
** Last update Tue Mar 14 14:12:37 2017 Leo Lecherbonnier
*/

#include "leo.h"

int	map(void)
{
  t_map map;

  initscr();

  my_init_color();
  map = init_game();
  while (1)
    {
      if (LINES != map.lines || COLS != map.cols)
	map = init_game();
	  wrefresh(map.win_hud);
	  wrefresh(map.win_game);
	  wrefresh(map.win3);
	  wrefresh(map.win4);
    }
  endwin();
  return (0);
}
