/*
** my.h for my ls in /home/abdel/PSU_2016_my_ls
**
** Made by Abderrahim CHERKAOUI
** Login   <abdel@epitech.net>
**
** Started on  Thu Dec  1 07:30:35 2016 Abderrahim CHERKAOUI
** Last update Sun Apr  2 13:43:59 2017 Leo Lecherbonnier
*/

#ifndef _MY_H_
#define _MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "./gnl/gnl.h"

typedef struct	s_index
{
  int	i;
  int	i2;
  int	j;
  int	k;
  int	x;
  int	y;
  int	z;
  int	lines;
  int	columns;
  char	*str;
  char	**tab;
}		t_index;

void	nbrbase(int nb, char *base);
char    *my_parse_str(int s, int e, char *str);
char    **str_to_tab(char *str);
char	*my_realloc(char *str, int size);
char	*int_to_str(int nbr);
char	*get_next_line(const int fd);

#endif /*!MY_H*/
