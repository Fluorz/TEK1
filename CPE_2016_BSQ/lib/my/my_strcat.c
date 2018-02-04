/*
** my_strcat.c for my_strcat in /home/leo/CPool_Day07/lib/my
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Tue Oct 11 14:00:15 2016 leo lecherbonnier
** Last update Sun Dec 18 12:36:45 2016 Leo Lecherbonnier
*/

#include <unistd.h>
#include "my.h"

char	*my_strcat1(char *s1, char *s2)
{
  char	*dest;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s1[i])
    i = i + 1;
  while (s2[j])
    j = j + 1;
  if ((dest = (char*)malloc(sizeof(char) * (i + j + 2))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (s1[i])
    dest[i] = s1[i++];
  if (dest[i - 1] != '/')
    dest[i++] = '/';
  while (s2[j])
    dest[i + j] = s2[j++];
  dest[i + j] = 0;
  return (dest);
}

char *my_strcat(char *dest, char *src)
{
  int len;
  int i;

  len = my_strlen(dest);
  i = 0;
  while (src[i])
    {
      dest[len + i] = src[i];
      i = i + 1;
    }
  dest[len + i] = '\0';
  return (dest);
}
