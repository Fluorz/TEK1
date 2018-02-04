/*
** my_put_nbr.c for my_put_nbr.c in /home/lecherbonnier/Projet/CPE_2016_stumper3/utils/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May  2 10:46:26 2017 Leo Lecherbonnier
** Last update Tue May  2 10:10:37 2017 Nicolas Ferlet
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	c;

  c = 1;
  if (nb < 0)
    return ;
  while (nb / c > 9)
    c = c * 10;
  while (c != 0)
    {
      my_putchar(nb / c + 48);
      nb = nb % c;
      c = c / 10;
    }
}
