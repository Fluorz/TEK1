/*
** disp_my_put_binary.c for disp my put binary in /home/monty/Documents/Projets/Système Unix/PSU_2016_my_printf/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Thu Nov 17 10:35:23 2016 Monty Criel
** Last update Thu Nov 17 10:35:48 2016 Monty Criel
*/

#include <stdarg.h>
#include <unistd.h>

void	my_putchar(char c);

int	my_strlen(char *str);

void	my_put_nbr_base(int nb, char *base);

void	disp_my_put_binary(va_list list)
{
  my_put_nbr_base(va_arg(list, int), "01");
}
