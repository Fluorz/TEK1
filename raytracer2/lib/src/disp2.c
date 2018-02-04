/*
** disp2.c for disp2.c in /home/pierre/work/Unix_System/PSU_2016_my_printf/
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Thu Nov 10 14:33:24 2016 Pierre Narcisi
** Last update Sun Nov 20 16:50:09 2016 Pierre Narcisi
*/

#include "my.h"
#include <stdarg.h>

void disp_o(va_list pa, int *m)
{
  my_put_nbr_base(va_arg(pa, int), "01234567", m);
}

void disp_b(va_list pa, int *m)
{
  my_put_nbr_base(va_arg(pa, int), "01", m);
}

void disp_S(va_list pa, int *m)
{
  my_putstrS(va_arg(pa, char*), m);
}

void disp_u(va_list pa, int *m)
{
  my_put_nbr_base(va_arg(pa, int), "0123456789", m);
}

void disp_p(va_list pa, int *m)
{
  my_putstr("0x", m);
  my_put_nbr_base(va_arg(pa, int), "0123456789abcdef", m);
}
