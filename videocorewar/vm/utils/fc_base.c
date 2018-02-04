/*
** fc_base.c for fc_base in /home/abdel/PSU_2016_my_exec
**
** Made by Abderrahim CHERKAOUI
** Login   <abdel@epitech.net>
**
** Started on  Thu Jan  5 09:55:06 2017 Abderrahim CHERKAOUI
** Last update Thu Apr 20 12:41:28 2017 abdel cherkaoui
*/

#include "../vm.h"

void	nbrbase(int nb, char *base)
{
  int	size;
  int	rest;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (- 1);
    }
  size = my_strlen(base);
  rest = nb % size;
  nb = nb / size;
  if (nb != 0)
    nbrbase(nb, base);
  my_putchar(base[rest]);
}
