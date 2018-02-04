/*
** get_next_line.caracter for get_next_line.caracter in /home/lecherbonnier/Projet/CPE_2016_matchstick/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Feb 15 09:07:24 2017 Leo Lecherbonnier
** Last update Fri Feb 24 10:12:46 2017 Leo Lecherbonnier
*/

#include "gnl.h"

int			my_xlen(char *str)
{
  int		i = 0;

  while (str[i] != '\0')
    i++;
  return (i);
}

void		*xxmalloc(int size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      write(2, "Impossible to allocate Memory\n", 30);
      return (NULL);
    }
  return (ptr);
}

char            *my_realloc(char *old, int size)
{
  int           i = 0;
  char          *new;

  new = xxmalloc(sizeof(*new) * (my_xlen(old) + size));
  while (old[i] != '\0')
    {
      new[i] = old[i];
      i++;
    }
  free(old);
  return (new);
}

char get_char(const int fd)
{
  static char buff[READ_MAX];
  static char* pointer;
  static int len = 0;
  char caracter;

  if (len == 0)
    {
      len = read(fd, buff, READ_MAX);
      pointer = (char*)&buff;
      if (len == 0)
	return (0);
    }
  caracter = *pointer;
  pointer++;
  len--;
  return caracter;
}

char *get_next_line(const int fd)
{
  char caracter;
  char* str;
  int len = 0;

  str = xxmalloc(READ_MAX + 1);
  if (str == NULL)
    return (0);
  caracter = get_char(fd);
  while (caracter != '\n')
    {
      str[len] = caracter;
      caracter = get_char(fd);
      len++;
      if (len % (READ_MAX + 1) == 0)
	str = my_realloc(str, len + READ_MAX + 1);
    }
  str[len] = 0;
  if (caracter == 0 && str[0] == 0)
    return (0);
  return (str);
}
