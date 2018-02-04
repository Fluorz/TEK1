/*
** my_put_nbr.c for my_put_nbr.c in /home/pierre.narcisi/CPool_Day03
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.net>
**
** Started on  Wed Oct  5 17:08:17 2016 Pierre Narcisi
** Last update Mon Nov 14 21:14:29 2016 Pierre Narcisi
*/

#include "my.h"

void	my_put_nbr(int nb, int *m)
{
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-', m);
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10, m);
      my_putchar((nb % 10) + 48, m);
    }
  else
    {
      my_putchar(nb + 48, m);
    }
}
