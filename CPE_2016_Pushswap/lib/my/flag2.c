/*
** flag2.c for flag2.c in /root/PSU_2016_my_printf/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Wed Nov 16 19:33:18 2016 Leo Lecherbonnier
** Last update Sun Nov 20 16:36:18 2016 Leo Lecherbonnier
*/

#include <stdarg.h>
#include "my.h"

void	flag_s(va_list valist)
{
  char	*str;

  str = (va_arg(valist, char*));
  if (str == NULL)
    my_putstr("(null)");
  else
    my_putstr(str);
}

void	flag_S(va_list valist)
{
  char	*str;
  int	i;
  int	a;

  i = 0;
  str = (va_arg(valist, char*));
  while (str[i] != '\0')
    {
      if (str[i] < 33 || str[i] > 127)
	{
	  my_putchar('\\');
	  a = str[i];
	  if (a <= 9 && a >= 0)
	      my_putstr("00");
	  else if (a <= 32 && a >= 0)
	      my_putstr("0");
	  my_put_nbr(a);
	}
      else
	my_putchar(str[i]);
      i++;
    }
}

void	print_percentage(va_list valist)
{
  my_putchar('%');
}

void	flag_x(va_list valist)
{
  int	X;

  X = (va_arg(valist, int));
  if (X == 0)
    my_putchar('0');
  else
    {
      transform_more1(X);
    }
}

void	flag_X(va_list valist)
{
  int	X;

  X = (va_arg(valist, int));
  if (X == 0)
    my_putchar('0');
  else
    transform_more(X);
}
