/*
** flag1.c for flag in /root/PSU_2016_my_printf/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Wed Nov 16 19:32:10 2016 Leo Lecherbonnier
** Last update Wed Nov 16 19:32:46 2016 Leo Lecherbonnier
*/

#include <stdarg.h>
#include "my.h"

void	flag_p(va_list valist)
{
  int	pointeur;
  int	a;

  pointeur = (va_arg(valist, int));
  if (pointeur == 0)
    {
      my_putstr("(nil)");
    }
  else
    {
      my_putstr("0x");
      transform_more1(pointeur);
    }
}

void	flag_b(va_list valist)
{
  int	a;

  a = (va_arg(valist, int));
  if (a == 0)
    my_putchar('0');
  else
    transform_less1(a);
}

void	flag_o(va_list valist)
{
  int	o;

  o = (va_arg(valist, int));
  if (o == 0)
    my_putchar('0');
  else
    transform_less(o);
}

void	flag_u(va_list valist)
{
  my_put_nbr1(va_arg(valist, unsigned int));
}
