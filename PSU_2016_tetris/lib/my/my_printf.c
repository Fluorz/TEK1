/*
** func_flags.c for function flags and prototypes in /home/monty/Documents/Projets/Système Unix/PSU_2016_my_printf/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Tue Nov 15 15:15:56 2016 Monty Criel
** Last update Fri Nov 25 16:04:48 2016 Monty Criel
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

t_func flag_list[12] =
{
  {&disp_my_putchar, 'c'},
  {&disp_my_putstr, 's'},
  {&disp_my_put_nbr, 'd'},
  {&disp_my_put_nbr, 'i'},
  {&disp_my_put_octal, 'o'},
  {&disp_my_put_hex1, 'x'},
  {&disp_my_put_hex2, 'X'},
  {&disp_my_put_binary, 'b'},
  {&disp_my_put_address, 'p'},
  {&disp_my_put_nbr_u, 'u'},
  {&disp_my_putstr_S, 'S'},
  {NULL, -1}
};

void	find_flag(const char c, va_list list)
{
  int  i;

  i = 0;
  while (flag_list[i].key_word != -1)
    {
      if (flag_list[i].key_word == c)
	{
	  flag_list[i].ptrfunc(list);
	  return;
	}
      i = i + 1;
    }
  my_putchar('%');
  my_putchar(c);
  return;
}

int		my_printf(const char *format, ...)
{
  int		i;
  va_list	list;

  i = 0;
  va_start(list, format);
  while (format[i] != '\0')
    {
      if (format[i] != '%')
	my_putchar(format[i]);
      else if (format[i] == '%' && format[i + 1] == '%')
	 {
	  i = i + 1;
	  my_putchar('%');
	}
      else if (format[i] == '%' && format[i + 1] != '%')
	{
	  i = i + 1;
	  find_flag(format[i], list);
	}
      i = i + 1;
    }
  va_end(list);
  return (0);
}
