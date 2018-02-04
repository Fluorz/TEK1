/*
** my_get_next_line.c for my_get_next_line.c in /home/lecherbonnier/Projet/CPE_2016_stumper4/src/utils/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May  9 12:21:49 2017 Leo Lecherbonnier
** Last update Mar May 9 12:21:56 2017
*/

#include "my.h"

char	*my_realloc(char *str, int len)
{
  char	*new_str;

  if ((new_str = malloc(sizeof(char) * len + 3)) == NULL)
    return (NULL);
  new_str = my_strcpy(str, new_str);
  free (str);
  return (new_str);
}

char	my_get_char(int fd)
{
  char	c;

  c = '\0';
  if (read(fd, &c, 1) < 0)
    return ('\0');
  return (c);
}

char	*my_get_next_line(int fd)
{
  int	i;
  char	c;
  char	*str;

  i = 0;
  if ((str = malloc(sizeof(char) * 4)) == NULL)
    return (NULL);
  c = my_get_char(fd);
  if (c == '\0')
    return (NULL);
  str[i] = c;
  i++;
  while (c != '\0' && c != '\n')
    {
      c = my_get_char(fd);
      str[i] = c;
      str[i + 1] = '\0';
      str = my_realloc(str, i);
      i++;
    }
  str[i - 1] = '\0';
  return (str);
}
