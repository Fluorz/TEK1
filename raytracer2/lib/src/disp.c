/*
** disp.c for disp.c in /home/pierre/work/Unix_System/PSU_2016_my_printf/
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Wed Nov  9 17:00:53 2016 Pierre Narcisi
** Last update Tue Nov 15 10:07:44 2016 Pierre Narcisi
*/

#include "my.h"
#include <stdarg.h>

void disp_char(va_list pa, int *m)
{
  my_putchar(va_arg(pa, int), m);
}

void disp_str(va_list pa, int *m)
{
  my_putstr(va_arg(pa, char*), m);
}

void disp_int(va_list pa, int *m)
{
  my_put_nbr(va_arg(pa, int), m);
}

void disp_X(va_list pa, int *m)
{
  my_put_nbr_base(va_arg(pa, int), "0123456789ABCDEF", m);
}

void disp_x(va_list pa, int *m)
{
  my_put_nbr_base(va_arg(pa, int), "0123456789abcdef", m);
}
