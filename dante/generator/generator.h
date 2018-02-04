/*
** my.h for my.h in /home/hugo/cours/Code/Semestre 2/Initiation IA/dante/generator/include/
**
** Made by Hugo Bleuzen
** Login   <hugo.bleuzen@epitech.eu>
**
** Started on  Fri Apr 28 13:48:17 2017 Hugo Bleuzen
** Last update Jun May 12 12:33:41 2017
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/gnl.h"

typedef struct	s_my_bool
{
  bool	UP;
  bool	LEFT;
}		t_my_bool;

typedef struct	s_args
{
  int		x;
  int		y;
  char		*type;
  char		**map;
}		t_args;

int	main(int ac, char **av);
int	init_args(t_args *args, char *x, char *y, char *str);
void	build_maze(t_args *args);
void	pair_line(t_args *args, int index);
void	impair_line(t_args *args, int index);
void	print_maze(t_args *args);
int	where_to_go(t_args *args);
int	create_maze(t_args *args);
t_my_bool my_check_case(t_args *args, int i, int j);
void	where_break(t_args *args, int i, int j, t_my_bool check);
void	break_wall(t_args *args);
void	make_finish(t_args *args);
void	rien_faire();
void	make_imperfect(t_args *args);
int	my_strcmp(char *str, char *dest);

#endif /*MY_H_*/
