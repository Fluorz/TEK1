/*
** breadth.h for breadth.h in /home/lecherbonnier/Projet/dante/breadth/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed May 10 15:35:07 2017 Leo Lecherbonnier
** Last update Sat May 13 19:18:15 2017 Leo Lecherbonnier
*/

#ifndef MY_H_
# define MY_H_

/*
** Includes
*/
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include "unistd.h"
#include "../include/my.h"
#include "../include/gnl.h"

#define UNVISITED '*'
#define VISITED	  'V'
#define WALL	  'X'
#define PATH	  'o'

typedef struct	s_stack
{
  int		index;
  struct s_stack *prev;
}		t_stack;

typedef struct	s_solver
{
  int		len;
  int		line_len;
  int		x;
  int		y;
  char		*good_one;
}		t_solver;

int	my_error(char *str, int erreur);
char	*algorithm(t_stack *list, t_solver *maze, char *map);

char	*fs_open_file(char* filepath);

#endif /* !MY_H_ */
