/*
** disp_my_put_hex2.c for disp my put hex2 in /home/monty/Documents/Projets/Système Unix/PSU_2016_my_printf/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Thu Nov 17 10:02:45 2016 Monty Criel
** Last update Thu Nov 17 10:15:27 2016 Monty Criel
*/

#include <stdarg.h>
#include <unistd.h>

void	my_putchar(char c);

int	my_strlen(char *str);

void	my_put_nbr_base(int nb, char *base);

void	disp_my_put_hex2(va_list list)
{
  my_put_nbr_base(va_arg(list, int), "0123456789ABCDEF");
}
