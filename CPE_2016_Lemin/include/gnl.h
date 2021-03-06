/*
** gnl.h for gnl.h in /home/lecherbonnier/Projet/PSU_2016_navy/include/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Feb  7 15:55:21 2017 Leo Lecherbonnier
** Last update Wed Feb 15 09:41:10 2017 Leo Lecherbonnier
*/

#ifndef __LIBGNL__
#define __LIBGNL__

#define READ_MAX 5

#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

int	my_xlen(char *str);
char		*get_next_line(int fd);
void		*xxmalloc(int size);
char		*my_realloc(char *old, int size);
char		get_char(const int fd);

#endif
