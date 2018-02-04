/*
** flag.c for flag.c in /root/PSU_2016_my_printf/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Nov 14 15:06:11 2016 Leo Lecherbonnier
** Last update Sat Feb 11 11:27:36 2017 Leo Lecherbonnier
*/

#include <stdio.h>
#include <stdarg.h>
#include "my.h"

void	flag_d(va_list valist)
{
  my_put_nbr(va_arg(valist, int));
}

void	flag_c(va_list valist)
{
  my_putchar(va_arg(valist, int));
}

void	flag_i(va_list valist)
{
  my_put_nbr(va_arg(valist, int));
}

void	flag_P(va_list valist)
{
  int	pointeur;

  pointeur = (va_arg(valist, int));
  if (pointeur == 0)
    {
      my_putstr("(nil)");
    }
  else
    {
      my_putstr("0x");
      transform_more(pointeur);
    }
}
