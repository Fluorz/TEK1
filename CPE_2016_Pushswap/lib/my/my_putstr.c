/*
** my_putstr.c for my_putstr.c in /home/leo/CPool_Day04
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Thu Oct  6 15:27:24 2016 leo lecherbonnier
** Last update Fri Nov 25 12:15:45 2016 Leo Lecherbonnier
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

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
