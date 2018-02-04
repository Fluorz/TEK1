/*
** my_strncpy.c for my_strcpy.c in /home/leo/CPool_Day06
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Mon Oct 10 11:07:39 2016 leo lecherbonnier
** Last update Sun Dec  4 17:31:11 2016 Leo Lecherbonnier
*/

#include <unistd.h>
#include "my.h"

char	*my_strncpy(char *dest, char *src, int start, int end)
{
  int	i;
  int	m;

  dest = malloc(sizeof(char) * (end - start - 1));
  if (dest == NULL)
    exit (-1);
  i = start;
  m = 0;
  while (i != end)
    {
      dest[m] = src[i];
      i++;
      m++;
    }
  dest[i] = '\0';
  return (dest);
}
