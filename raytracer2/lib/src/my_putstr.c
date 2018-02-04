/*
** my_putstr.c for my_putstr.c in /home/pierre.narcisi/CPool_Day04
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.net>
**
** Started on  Thu Oct  6 11:02:53 2016 Pierre Narcisi
** Last update Wed Nov 16 15:26:53 2016 Pierre Narcisi
*/

#include "my.h"

void	my_putstr(char *str, int *m)
{
  int	n;

  n = 0;
  if (str != NULL)
    {
      while (str[n] != '\0')
      {
      my_putchar(str[n], m);
      n = n + 1;
    }
  }
  else
    my_putstr("(null)", m);
}

void	my_putstrS(char *str, int *m)
{
  int	n;

  n = 0;
  while (str[n] != '\0')
    {
      if (str[n] < 32 || str[n] >= 127)
      {
        my_putchar('\\', m);
        if (str[n] <= 7)
          my_putstr("00", m);
        else if (str[n] <= 64)
          my_putchar('0', m);
        my_put_nbr_base(str[n], "01234567", m);
      }
      else
        my_putchar(str[n], m);
      n = n + 1;
    }
}
