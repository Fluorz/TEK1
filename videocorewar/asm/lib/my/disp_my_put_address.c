/*
** disp_my_put_address.c for disp my put address in /home/monty/Documents/Projets/Système Unix/PSU_2016_my_printf/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Sat Nov 19 17:04:24 2016 Monty Criel
** Last update Sat Nov 19 18:27:30 2016 Monty Criel
*/

#include <stdarg.h>
#include <unistd.h>

void	my_putchar(char c);

int	my_strlen(char *str);

void	my_put_nbr_base_hex(long int nb, char *base)
{
  int	max;
  int	rest;

  max = my_strlen(base);
  rest = nb % max;
  nb = nb / max;
  if (nb > 0)
    my_put_nbr_base_hex(nb, base);
  my_putchar(base[rest]);
}

void	disp_my_put_address(va_list list)
{
  my_putchar('0');
  my_putchar('x');
  my_put_nbr_base_hex(va_arg(list, long int), "0123456789abcdef");
}
