/*
** my_put_nbr.c for my_put_nbr.c in /home/pierre.narcisi/CPool_Day03
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.net>
**
** Started on  Wed Oct  5 17:08:17 2016 Pierre Narcisi
** Last update Mon Nov 14 21:13:47 2016 Pierre Narcisi
*/

#include "my.h"

void	my_put_nbr_base(unsigned int nb, char *base, int *m)
{
  if (nb >= my_strlen(base))
    {
      my_put_nbr_base(nb / (my_strlen(base)), base, m);
      my_putchar(base[(nb % my_strlen(base))], m);
    }
  else
    {
      my_putchar(base[nb], m);
    }
}
