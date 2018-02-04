/*
** leo.h for leo.h in /home/lecherbonnier/Projet/PSU_2016_tetris/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Mar  1 14:32:32 2017 Leo Lecherbonnier
** Last update Fri Mar  3 01:21:42 2017 Leo Lecherbonnier
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>
#include <curses.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <string.h>
#include "../include/my.h"

typedef struct s_map
{
  WINDOW *win_hud;
  WINDOW *win_game;
  WINDOW *win3;
  WINDOW *win4;
  int	lines;
  int	cols;
}						t_map;

int	print_map(char **map);
char	**create_map();

WINDOW	*next_print_tetris(WINDOW *win);
WINDOW	*print_tetris(WINDOW *win);
int	my_init_color(void);
WINDOW	*create_window(int x, int y, int xx, int yy);
t_map	init_game(void);
