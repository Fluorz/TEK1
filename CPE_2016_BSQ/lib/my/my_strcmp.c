/*
** my_strcmp.c for my_strcmp.c in /home/leo/CPool_Day07/lib/my
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Tue Oct 11 13:20:17 2016 leo lecherbonnier
** Last update Wed Nov 30 09:02:59 2016 Leo Lecherbonnier
*/

#include <stdio.h>
#include "my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s2[i] != '\0')
    {
      s1[i] = s2[i];
      i++;
    }
  return (0);
}
