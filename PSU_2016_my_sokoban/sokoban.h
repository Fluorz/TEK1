/*
** sokoban.h for sokoban.h in /root/Desktop/PSU/PSU_2016_my_sokoban/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Dec 12 16:41:43 2016 Leo Lecherbonnier
** Last update Tue Dec 20 18:53:15 2016 Leo Lecherbonnier
*/

#ifndef SOKOBAN_H
# define SOKOBAN_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <string.h>

typedef struct	s_flags
{
  	char	arr;
  	void	(*s_flags)(char **tab, int *x, int *y, int ligne);
}		t_flags;

void	flag_right(char **tab, int *x, int *y, int ligne);
void	flag_left(char **tab, int *x, int *y, int ligne);
void	flag_down(char **tab, int *x, int *y, int ligne);
void	flag_up(char **tab, int *x, int *y, int ligne);

int	my_strlen(char *str);
int	colision(char **tab, int x, int y, int ligne);
int	print_tab(char **str, int ligne, int x, int y);
char	*fs_open_file(char* filepath, int *ligne);
void	writeScr(char *string);
void	put_in_tab(char *str, int *ligne);
int	movements(char **tab, int ligne, int *x, int *y);
int	check_p(char **tab, int ligne, int *x, int *y);
int	opere(char **tab, int *x, int *y);
int	compting_o(char **tab, int ligne);

#endif /* !SOKOBAN_H */
