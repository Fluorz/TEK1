/*
** my_strcpy.c for my_strcpy.c in /home/leo/CPool_Day06
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Mon Oct 10 09:37:50 2016 leo lecherbonnier
** Last update Sun Dec  4 17:29:12 2016 Leo Lecherbonnier
*/

#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i + 1] = '\0';
  return (dest);
}
