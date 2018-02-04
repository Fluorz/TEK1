/*
** my_printf.c for my_printf.c in /home/pierre/work/Unix_System/PSU_2016_my_printf/
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Wed Nov  9 15:22:39 2016 Pierre Narcisi
** Last update Sun Feb 26 21:49:16 2017 John Doe
*/

#include "my.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

t_params tab[12] = {
  {'d', disp_int},
  {'i', disp_int},
  {'u', disp_u},
  {'o', disp_o},
  {'x', disp_x},
  {'X', disp_X},
  {'c', disp_char},
  {'s', disp_str},
  {'p', disp_p},
  {'b', disp_b},
  {'S', disp_S},
  {'\0', NULL}
};

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
  {
  while (str[i] != '\0')
    i++;
  }
  return (i);
}

void ouais(char c, int *m)
{
  my_putchar('%', m);
  my_putchar(c, m);
}

int       my_printf(char *str, ...)
{
  t_f var;
  va_list pa;

  var.m = 0;
  var.i = 0;
  va_start(pa, str);
  while (str[var.i] != '\0')
  {
    var.n = 0;
    if (str[var.i] == '%')
    {
      while (tab[var.n].c != str[var.i + 1] && tab[var.n].c != '\0')
        var.n++;
      if (tab[var.n].c == '\0')
        ouais(str[var.i + 1], &var.m);
      else
        tab[var.n].disp(pa, &var.m);
      var.i = var.i + 1;
    }
    else if (str[var.i] != '%')
      my_putchar(str[var.i], &var.m);
    var.i++;
  }
  return (var.m);
}
