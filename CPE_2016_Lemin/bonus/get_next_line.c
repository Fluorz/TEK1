/*
** get_next_line.c for get_next_line in /home/monty/Documents/Rendu/get_next_line/CPE_2016_getnextline/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Wed Jan 11 11:23:35 2017 Monty Criel
** Last update Mon Apr 24 09:26:28 2017 Monty Criel
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "my.h"

char		*init_line(char *buffer)
{
  char		*str;
  int		i;
  int		x;

  i = 0;
  x = 0;
  str = malloc(sizeof(char) * (READ_SIZE + 2));
  if (str == NULL)
    return (NULL);
  if (buffer[i] != '\n' || buffer[i] != '\0')
    {
      while (i < READ_SIZE)
	{
	  if (buffer[i] == '\n' || buffer[i] == '\0')
	    {
	      i = i + 1;
	      while (buffer[i] != '\0' && i < READ_SIZE)
		str[x++] = buffer[i++];
	    }
	  i = i + 1;
	}
    }
  return (str);
}

char		*my_realloc(char *str, int size)
{
  int		i;
  int		len;
  char		*src;

  i = 0;
  len = my_strlen(str);
  src = malloc(sizeof(char) * (len + size));
  if (src == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      src[i] = str[i];
      i = i + 1;
    }
  src[i] = '\0';
  free(str);
  return (src);
}

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE + 1];
  static char	*line;
  int		i;
  int		x;
  int		n;

  x = 0;
  line = init_line(buffer);
  while ((n = read(fd, buffer, READ_SIZE)) > 0)
    {
      i = 0;
      while (i < n)
	{
	  if (buffer[i] == '\n' || buffer[i] == '\0')
	    {
	      line[x] = '\0';
	      return (line);
	    }
	  line[x++] = buffer[i++];
	}
      if ((line = my_realloc(line, READ_SIZE + 3)) == NULL)
	return (NULL);
    }
  return (NULL);
}
