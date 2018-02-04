/*
** disp_my_put_octal.c for my put octal in /home/monty/Documents/Projets/Système Unix/PSU_2016_my_printf/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Thu Nov 17 09:36:00 2016 Monty Criel
** Last update Sat Nov 26 18:54:25 2016 Monty Criel
*/

#include <stdarg.h>
#include <unistd.h>

void	my_putchar(char c);

int	my_strlen(char *str);

void	my_put_nbr_base(int nb, char *base)
{
  int	max;
  int	rest;

  max = my_strlen(base);
  rest = nb % max;
  nb = nb / max;
  if (nb > 0)
    my_put_nbr_base(nb, base);
  my_putchar(base[rest]);
}

void	disp_my_put_octal(va_list list)
{
  my_put_nbr_base(va_arg(list, int), "01234567");
}
