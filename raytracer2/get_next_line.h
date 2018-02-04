/*
** get_next_line.h for my_getnextline.h in /home/bilyarus/work/CPE/CPE_2016_ge
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sat Jan  7 16:29:43 2017 John Doe
** Last update Wed Feb 22 10:53:37 2017 John Doe
*/

#ifndef READ_SIZE
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define READ_SIZE (10)

typedef struct s_val
{
  int size;
  int size2;
  int size3;
}              t_val;

int my_strlen(char *str);
#endif
