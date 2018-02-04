/*
** get_next_line.c for get_next_line.c in /home/lecherbonnier/Projet/CPE_2016_stumper2/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Apr 25 09:29:06 2017 Leo Lecherbonnier
** Last update Mar Apr 25 10:43:26 2017
*/

#include "my.h"

char get_char(int fd)
{
  char c;

  if ((read(fd, &c, 1)) == 0)
    {
      return ('\0');
    }
  return (c);
}

char	*my_realloc(char *str, int len)
{
  char *new_str;

  new_str = NULL;
  if ((new_str = malloc(sizeof(char) * len + 3)) == NULL)
    return (NULL);
  new_str = my_strcpy(new_str, str, len);
  free (str);
  return (new_str);
}

char *get_next_line(int fd)
{
  int	i;
  char *str;
  char	c;

  str = NULL;
  i = 0;
  if ((str = malloc(sizeof(char) * 1)) == NULL)
    return (NULL);
  if ((c = get_char(fd)) == '\0')
    return (NULL);
  if ((str = my_realloc(str, i)) == NULL)
    return (NULL);
  str[i] = c;
  i++;
  while (c != '\n')
    {
      if ((c = get_char(fd)) == '\0')
	break;
      if ((str = my_realloc(str, i)) == NULL)
	return (NULL);
      str[i] = c;
      i++;
    }
  str[i - 1] = '\0';
  return (str);
}
