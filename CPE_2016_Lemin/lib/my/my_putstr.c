/*
** my_putstr.c for my_putstr.c in /home/leo/CPool_Day04
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Thu Oct  6 15:27:24 2016 leo lecherbonnier
** Last update Mon Jan 30 11:30:28 2017 Leo Lecherbonnier
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
