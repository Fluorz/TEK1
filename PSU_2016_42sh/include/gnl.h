/*
** get_next_line.h for ok in /home/abdel/CPE_2016_getnextline
**
** Made by Abderrahim CHERKAOUI
** Login   <abdel@epitech.net>
**
** Started on  Sat Jan 14 18:08:43 2017 Abderrahim CHERKAOUI
** Last update Jun Jun 2 14:17:14 2017
*/

#ifndef GNL_H_
# define GNL_H_
#ifndef READ_SIZE
# define READ_SIZE 4096
#endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_my_gnl
{
  int           treat;
  char          *line;
}		t_my_gnl;

char            *get_next_line(const int fd);
#endif /* !GNL */
