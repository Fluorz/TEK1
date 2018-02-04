/*
** init_map.c for init_map.c in /home/lecherbonnier/Projet/PSU_2016_tetris/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Mar  2 19:35:06 2017 Leo Lecherbonnier
** Last update Fri Mar  3 14:00:22 2017 Leo Lecherbonnier
*/

#include "leo.h"

t_map	init_game(void)
{
  t_map	map;

  initscr();
  map.lines = LINES;
  map.cols = COLS;
  map.win_hud = create_window(map.lines, map.cols, 0, 0);
  map.win_game = create_window(map.lines / 3, map.cols / 4, 20, 10);
  map.win3 = create_window(map.lines / 1.5 , map.cols / 3, 10 ,
			   map.cols / 2 - 10);
  map.win4 = create_window(map.lines / 7, map.cols / 7, 10 , map.cols / 1.3);
  wborder(map.win_hud, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wborder(map.win_game, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wborder(map.win3, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wborder(map.win4, '|', '|', '-', '-', '/', '\\', '\\', '/');
  mvwprintw(map.win_game, 3, 1, "Hight score:");
  mvwprintw(map.win_game, 4, 1, "Score:");
  mvwprintw(map.win_game, 7, 1, "Lines");
  mvwprintw(map.win_game, 8, 1, "Level");
  mvwprintw(map.win_game, 10, 1, "Timer");
  mvwprintw(map.win4, 0, 1, "Next");
  mvwprintw(map.win_hud, map.lines - 2, map.cols / 3,
	    "by Leo Lecherbonnier && Monty Criel #GradeAonly");
  map.win_hud = print_tetris(map.win_hud);
  curs_set(0);
  return (map);
}
