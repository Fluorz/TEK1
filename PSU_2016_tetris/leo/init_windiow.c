/*
** init_windiow.c for init_window.c in /home/lecherbonnier/Projet/PSU_2016_tetris/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Mar  2 19:24:39 2017 Leo Lecherbonnier
** Last update Thu Mar  2 22:49:16 2017 Leo Lecherbonnier
*/

#include "leo.h"

WINDOW	*create_window(int x, int y, int xx, int yy)
{
  WINDOW *win;

  win = newwin(x, y, xx, yy);
  return (win);
}

int	my_init_color(void)
{
  start_color();
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
  return (0);
}

WINDOW	*print_tetris(WINDOW *win)
{
  wattrset(win, COLOR_PAIR(2));
  mvwprintw(win, 5, 20, "***");
  mvwprintw(win, 6, 20, "* *");
  mvwprintw(win, 7, 20, "** ");
  mvwprintw(win, 8, 20, "* *");
  mvwprintw(win, 9, 20, "* *");
  wattrset(win, COLOR_PAIR(6));
  mvwprintw(win, 5, 24, " * ");
  mvwprintw(win, 6, 24, "   ");
  mvwprintw(win, 7, 24, " * ");
  mvwprintw(win, 8, 24, " * ");
  mvwprintw(win, 9, 24, " * ");
  wattrset(win, COLOR_PAIR(5));
  mvwprintw(win, 5, 28, "***");
  mvwprintw(win, 6, 28, "*  ");
  mvwprintw(win, 7, 28, "***");
  mvwprintw(win, 8, 28, "  *");
  mvwprintw(win, 9, 28, "***");
  win = next_print_tetris(win);
  return (win);
}

WINDOW	*next_print_tetris(WINDOW *win)
{
  wattrset(win, COLOR_PAIR(1));
  mvwprintw(win, 5, 8, "***");
  mvwprintw(win, 6, 8, " * ");
  mvwprintw(win, 7, 8, " * ");
  mvwprintw(win, 8, 8, " * ");
  mvwprintw(win, 9, 8, " * ");
  wattrset(win, COLOR_PAIR(4));
  mvwprintw(win, 5, 12, "***");
  mvwprintw(win, 6, 12, "*  ");
  mvwprintw(win, 7, 12, "***");
  mvwprintw(win, 8, 12, "*  ");
  mvwprintw(win, 9, 12, "***");
  wattrset(win, COLOR_PAIR(3));
  mvwprintw(win, 5, 16, "***");
  mvwprintw(win, 6, 16, " * ");
  mvwprintw(win, 7, 16, " * ");
  mvwprintw(win, 8, 16, " * ");
  mvwprintw(win, 9, 16, " * ");
  return (win);
}
