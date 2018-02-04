/*
** get_next_line.c for my_getnextline in /home/bilyarus/work/CPE/CPE_2016_getn
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sat Jan  7 15:10:30 2017 John Doe
** Last update Fri Mar 10 19:39:25 2017 John Doe
*/

#include "get_next_line.h"

char *my_alloc(char car, int size, char *str)
{
  int i;
  char *res;

  if ((res = malloc(sizeof(char) * (size + 2))) == NULL)
    return (NULL);
  i = 0;
  while (str[i])
  {
    res[i] = str[i];
    i = i + 1;
  }
  res[i] = car;
  res[i + 1] = 0;
  free(str);
  return (res);
}

char *get_next_line(const int fd)
{
  char *str;
  char car;
  char size;

  if ((str = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  str[0] = 0;
  size = 0;
  while (read(fd, &car, 1) > 0)
  {
    if (car == '\n')
      return (str);
    str = my_alloc(car, size, str);
    size = size + 1;
  }
  if (size == 0)
  {
    free(str);
    return (NULL);
  }
  return (str);
}
