/*
** my_strcat.c for my_strcat.c in /root/PSU_2016_minishell1/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Jan 16 14:22:57 2017 Leo Lecherbonnier
** Last update Wed Jan 18 09:38:05 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

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
