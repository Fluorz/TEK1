/*
** my_get_next_line.c for my_get_next_line.c in /home/lecherbonnier/Projet/CPE_2016_stumper3/utils/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May  2 11:23:07 2017 Leo Lecherbonnier
** Last update Tue May  2 09:25:19 2017 Nicolas Ferlet
*/

#include "my.h"

char	*my_realloc(char *str)
{
  char *new_str;

  if ((new_str = malloc(sizeof(char) * my_strlen(str) + 3)) == NULL)
    return (NULL);
  my_strcpy(str, new_str);
  if (new_str == NULL)
    return (NULL);
  free(str);
  return (new_str);
}

char	get_char(int fd)
{
  char c;

  c = '\0';
  read(fd, &c, 1);
  return (c);
}

char *get_next_line(int fd)
{
  int	i;
  char 	c;
  char	*str;

  i = 1;
  c = get_char(fd);
  if (c == '\0' || c == '\n')
    return (NULL);
  if ((str = malloc(sizeof(char) * 3)) == NULL)
    return (NULL);
  str[0] = c;
  while (c != '\0' && c != '\n')
    {
      c = get_char(fd);
      str[i] = c;
      str[i + 1] = '\0';
      if ((str = my_realloc(str)) == NULL)
	return (NULL);
      i++;
    }
  return (str);
}
