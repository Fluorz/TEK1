/*
** get_next_line.c for gnl in /home/lecherbonnier/Projet/raytracer2/include/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun May 28 20:47:18 2017 Leo Lecherbonnier
** Last update Jan May 28 22:45:06 2017
*/

#include "open_file.h"
#include "gnl.h"

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

char	*get_next_line(int fd)
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
  str[i + 1] = '\0';
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
