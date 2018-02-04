/*
** disp_my_put_hex1.c for disp my put hex1 in /home/monty/Documents/Projets/Système Unix/PSU_2016_my_printf/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Thu Nov 17 10:01:03 2016 Monty Criel
** Last update Thu Nov 17 10:15:35 2016 Monty Criel
*/

#include <stdarg.h>
#include <unistd.h>

void	my_putchar(char c);

int	my_strlen(char *str);

void	my_put_nbr_base(int nb, char *base);

void	disp_my_put_hex1(va_list list)
{
  my_put_nbr_base(va_arg(list, int), "0123456789abcdef");
}
